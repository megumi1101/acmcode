#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    s = " " + s;
    t = " " + t;
    vector<vector<int>> p(26);
    for (int i = n; i >= 1; i--) {
        p[s[i] - 'a'].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        int x = t[i] - 'a';
        int u;
        if (p[x].empty()) {
            cout << "NO\n";
            return;
        } else {
            u = p[x].back();
            p[x].pop_back();
        }
        for (int j = 0; j < x; j++) {
            while (!p[j].empty() && p[j].back() < u) p[j].pop_back();
        }
    }
    cout << "YES\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
 
    int T = 1;
    cin >> T;
    while (T--) sol();
}
