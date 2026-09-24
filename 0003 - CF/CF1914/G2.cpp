#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353;
static mt19937 gen(random_device{}());
uniform_int_distribution<long long> dis(1, 1e18);
void sol() {
    int n;
    cin >> n;
    vector<int> c(2 * n + 1), cl(n + 1), cr(n + 1), rnd(n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> c[i];
        rnd[c[i]] = dis(gen);
        if (cl[c[i]]) cr[c[i]] = i;
        else cl[c[i]] = i;
    }
    
    int l = 1, r = 0;
    vector<pair<int, int>> prs;
    for (int i = 1; i <= 2 * n; i++) {
        if (i > r) {
            if (r) prs.push_back({l, r});
            l = r + 1;
        }
        r = max(r, cr[c[i]]);
    }
    if (r) prs.push_back({l, r});
 
    int ans = 1;
    for (auto [l, r] : prs) {
        int cnt = 0;
        int res = 0;
        map<int, int> mp;
        vector<pair<int, int>> p;
        int lst = 0;
        for (int i = l; i <= r; i++) {
            res = res ^ rnd[c[i]];
            auto it = mp.find(res);
            if (it != mp.end()) {
                int x = it -> second;
                while (!p.empty() && x < p.back().first) p.pop_back();
                p.push_back({x, i});
            }
            mp[res] = i;
        }
        for (auto [x, y] : p) cnt += y - x; 
        ans *= r - l + 1 - cnt;
        ans %= mod;
    }
    cout << prs.size() << " " << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
