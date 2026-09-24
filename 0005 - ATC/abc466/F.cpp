#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n, X;
    vector<int> stk;
    cin >> n >> X;
    for (int i = 1; i <= n; i++) {
        int x; 
        cin >> x;
        if (!stk.empty() && x >= stk.back()) continue;
        stk.push_back(x);
    }

    if (stk.back() == 1) {
        cout << X << "\n";
        return;
    }

    int siz = stk.size();

    vector<map<int, int>> mp(siz);
    auto dfs = [&](this auto &&dfs, int i, int x) -> int {
        if (i == siz || x == 1) return 1;
        // cerr << i << " " << x << " \n";
        auto it = mp[i].find(x);
        if (it != mp[i].end()) return it->second;

        int res = 0;
        int p = stk[i];
        int quo = x / p;
        int rem = x % p;
        if (quo) {
            res += quo * dfs(i + 1, p);
        }
        if (rem) {
            int l = i + 1, r = siz - 1;
            int ans = siz;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (stk[mid] < rem) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            res += dfs(ans, rem);
        } 
        return mp[i][x] = res; 
    };
    int ans = dfs(0, X + 1) - 1;
    cout << ans << "\n";
    
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) sol();
    
}

/*
1
9 31415
9 9 8 2 4 4 3 5 3

1
3 7
5 2 3
*/