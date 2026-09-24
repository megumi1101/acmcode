#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    vector<map<int, int>> vmp(n + 1);
 
    vector<int> v;
 
    auto mer = [&](auto& v1, auto &v2) -> vector<int> {
        vector<int> tmp;
        for (auto &i : v1) {
            for (auto &j : v2) {
                if (i == j) {
                    tmp.push_back(i);
                }
            }
        }
        return tmp;
    };
 
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        vector<int> nv;
        int t = a[i];
        while (1) {
            vmp[i][t] = cnt;
            cnt++;
            nv.push_back(t);
            if (t <= 2) break;
            if (t & 1) t++;
            else t >>= 1;
        }
        if (t == 1) {
            vmp[i][2] = cnt;
            nv.push_back(2);
        } else {
            vmp[i][1] = cnt;
            nv.push_back(1);
        }
        if (i == 1) v = move(nv);
        else v = mer(v, nv);
    }
 
    int ans = 1e18;
    for (auto x : v) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += vmp[i][x];
        }
        ans = min(ans, res);
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
