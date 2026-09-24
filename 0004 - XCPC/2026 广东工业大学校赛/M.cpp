#include <bits/stdc++.h>
 
using namespace std;
 
 
void sol() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> ed(n + 1);
    
    for (int i = 2; i <= n; i++) {
        int x;
        string s;
        cin >> x >> s;
        ed[x].push_back({s[0] - 'a', i});
    }
    cout << "1 ";
    [&] (this auto &&self, int u) -> void {
        sort(ed[u].begin(), ed[u].end());
        vector<int> rt(26);
        vector<vector<int>> p(26);
        for (auto[c, v] : ed[u]) {
            p[c].push_back(v);
            if (!rt[c]) rt[c] = v;
            else {
                for (auto t : ed[v]) {
                    ed[rt[c]].push_back(t);
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            for (auto x : p[i]) cout << x << " ";
            if (rt[i]) {
                self(rt[i]);
            }
        }
    } (1);
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
2
3
1 b
2 a
6
1 z
1 a
2 b
2 a
5 c
*/
