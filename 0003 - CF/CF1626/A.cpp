#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define ll long long
    void sol() {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> vis(26);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            vis[s[i] - 'a']++;
        }
        string ans;
        for (int i = 0; i <26; i++) {
            if (vis[i] == 2) {
                ans += char(i + 'a');
            }
        }
        for (int i = 0; i < 26; i++) {
            if (vis[i] == 2) {
                ans += char(i + 'a');
            }
        }
        for (int i = 0; i < 26; i++) {
            if (vis[i] == 1) {
                ans += char(i + 'a');
            }
        }
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
