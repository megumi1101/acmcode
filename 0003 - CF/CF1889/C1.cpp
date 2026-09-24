#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> in(n + 5), out(n + 5);
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        in[l].push_back(i);
        out[r + 1].push_back(i);
    }
 
    set<int> s;
    map<int, int> sin;
    map<pair<int, int >, int> dou;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (auto j : in[i]) s.insert(j);
        for (auto j : out[i]) s.erase(j);
        if (s.empty()) cnt++;
        else if (s.size() == 1) sin[*s.begin()]++;
        else if (s.size() == 2) dou[{*s.begin(), *s.rbegin()}]++;
    }
    
    vector<int> tmp;
    for (auto [u, v] : sin) tmp.push_back(v);
    sort(tmp.rbegin(), tmp.rend());
    int ans = 0;
    if (tmp.size() >= 1) ans += tmp[0];
    if (tmp.size() >= 2) ans += tmp[1];
    
    for (auto[u, v] : dou) {
        auto [x, y] = u;
        ans = max(ans, sin[x] + sin[y] + v);
    }
    cout << ans + cnt << "\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
