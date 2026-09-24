#include <bits/stdc++.h>

using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<int> vis(26);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        vis[s[i][0] - 'a'] = 1;
    }

    bool fg = 0;

    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        for (auto c : t) {
            if (!vis[c - 'A']) {
                fg = 1;
            }
        }
    }

    if (fg) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}