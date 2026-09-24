#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, k;
    cin >> n >> k;
    vector<string> s(k);
    for (int i = 0; i < k; i++) cin >> s[i];
 
    string ans;
    for (int d = 1; d <= n; d++) {
        if (n % d != 0) {
            continue;
        }
 
        ans.clear();
        bool fg = 1;
        for (int i = 0; i < d; i++) {
            vector<int> vis(26);
            bool fg2 = 0;
            int cnt = 0;
            for (int j = i; j < n; j += d) {
                cnt++;
                vector<int> vs(26);
                for (int p = 0; p < k; p++) {
                    if (vs[s[p][j] - 'a']) continue;
                    vs[s[p][j] - 'a'] = 1;
                    vis[s[p][j] - 'a']++;
                }
            }
            for (int j = 0; j < 26; j++) if (vis[j] == cnt) {fg2 = 1, ans.push_back('a' + j); break;}
            if (!fg2) {
                fg = 0;
                break;
            }
        }
        if (fg) {
            for (int i = 1; i <= n / d; i++) cout << ans;
            break;
        }
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
