#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    vector<vector<string>> a(n);
    
    for (int i = 0; i < n; i++) {
        string s, t;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> t) {
            a[i].push_back(t);
        }
    }

    vector<int> p(n, 0);
    vector<bool> vis(n, 0);
    auto get = [&](int id) {
        string s;
        for (int j = 0; j < a[id].size(); j++) {
            if (j < p[id]) s += a[id][j];
            else s += a[id][j][0];
        }
        return s;
    };

    vector<string> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = get(i);
    }

    while (1) {
        map<string, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[ans[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i] && mp[ans[i]].size() == 1) {
                vis[i] = 1;
            }
        }

        bool fg = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            if (mp[ans[i]].size() == 1) continue;
            if (p[i] < (int)a[i].size()) {
                p[i]++;
                fg = 1;
            }
        }

        if (!fg) break;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans[i] = get(i);
            }
        }
    }

    for (auto &s : ans) {
        cout << s << '\n';
    }
    return 0;
}