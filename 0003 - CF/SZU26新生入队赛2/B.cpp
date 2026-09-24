#include <bits/stdc++.h>

using namespace std;

#define int long long


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<vector<int>> ed(26);
    vector<int> in(26);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int len1 = s[i].size();
            int len2 = s[j].size();

            bool fg = 0;
            for (int k = 0; k < min(len1, len2); k++) {
                if (s[i][k] != s[j][k]) {
                    ed[s[i][k] - 'a'].push_back(s[j][k] - 'a');
                    in[s[j][k] - 'a']++;
                    fg = 1;
                    break;
                }
            }

            if (!fg) {
                if (len1 > len2) {
                    cout << "Impossible\n";
                    return 0;
                }
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    string ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back('a' + u);
        for (auto v : ed[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }

    if (ans.size() == 26) {
        cout << ans << "\n";
    } else {
        cout << "Impossible\n";
    }
}