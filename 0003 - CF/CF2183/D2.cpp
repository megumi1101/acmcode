#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    
    vector<vector<int>> ed(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    
    vector dep(n + 1, 0);
    vector siz (n + 1, 0);
    vector fa(n + 1, 0);
    vector col(n + 1, 0);
    vector<vector<int>> d(n + 1);
    int ans = 0;
    auto dfs = [&] (auto &&dfs, int u, int fat) -> void {
        dep[u] = dep[fat] + 1;
        ans = max(ans, (int)ed[u].size() + (u == 1));
        for (auto v : ed[u]) if (v != fat) {
            dfs(dfs, v, u);
        }
        siz[dep[u]]++;
        fa[u] = fat;
        d[dep[u]].push_back(u);
    };
    dfs(dfs, 1, 0);
    for (int i = 1; i <= n; i++) ans = max(ans, siz[i]);
    col[1] = 1;
 
    set<int> s;
    for (int i = 1; i <= ans; i++) s.insert(i);
    for (int i = 2; i <= n; i++) if (siz[i]) {
        for (int j = 0; j < d[i].size(); j++) {
            int x = d[i][j];
            auto it = s.begin();
            if (*it == col[fa[x]]) {
                it = s.upper_bound(*it);
            }
 
            if (it == s.end()) {
                col[x] = col[d[i][0]];
                col[d[i][0]] = col[fa[x]];
            } else {
                col[x] = *it;
                s.erase(it);
            }
        }
        for (auto x : d[i]) s.insert(col[x]);
    }
    
    vector<vector<int>> pp(ans + 1);
    for (int i = 1; i <= n; i++) pp[col[i]].push_back(i);
 
    cout << ans << "\n";
    for (int i = 1; i <= ans; i++) {
        cout << pp[i].size() << " ";
        for (auto x : pp[i]) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
