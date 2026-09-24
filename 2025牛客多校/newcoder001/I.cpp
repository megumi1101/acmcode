#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    const int inf = 1e18;
    int lg(int x) {
        return 64 - __builtin_clzll(x - 1);
    }
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 5), sum(n + 5, 0);
        vector<vector<vector<pair<int, int>>>> f(n + 5, vector<vector<pair<int, int>>>(n + 5));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        auto find = [&] (int i, int j, int k) -> int {
            auto it = upper_bound(f[i][j].begin(), f[i][j].end(), make_pair(k, inf));
            if (it == f[i][j].begin()) return inf;
            else return (--it) -> second;
        };
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                vector<pair<int, int>> tmp;
                for (int k = i; k < j; k++) {
                    int l1 = sum[k] - sum[i - 1];
                    int l2 = sum[j] - sum[k];
                    int x = abs(l1 - l2);
                    int t1 = 0, t2 = 0;
                    int t3 = lg(sum[j] - sum[i - 1]) * min(l1, l2);
                    if (k != i) t1 = find(i, k, x);
                    if (k + 1 != j) t2 = find(k + 1, j, x);
                    int ans = (t1 + t2 + t3);
                    if (len == n) {
                        if (ans >= inf) cout << "-1 ";
                        else cout << ans << " ";
                    }
                    tmp.emplace_back(x, ans);
                }
                int mn = inf;
                sort(tmp.begin(), tmp.end());
                for (auto v: tmp) {
                    mn = min (mn, v.second);
                    f[i][j].emplace_back(v.first, mn);
                }
            }
        }
        cout << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T  = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
/*
10 3
1001001001
2 4 3 5
1 2 6
2 5 2 6
*/