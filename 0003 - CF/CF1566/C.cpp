#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    
    void sol() {
        int n;
        string s, t;
        cin >> n >> s >> t;
        s = ' ' + s + ' ';
        t = ' ' + t + ' ';
        int ans = 0;
        bool vis[n + 5];
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i < s.size() - 1; i++) {
            if ((s[i] == '1' && t[i] == '0') || (t[i] == '1' && s[i] == '0')) {
                ans += 2;
            }
            else if (s[i] == '0' && t[i] == '0') {
                ans++;
            }
            else {
                if (s[i - 1] == '0' && t[i - 1] == '0' && !vis[i - 1]) {
                    ans++;
                }
                else if (s[i + 1] == '0' && t[i + 1] == '0') {
                    ans++;
                    vis[i + 1] = 1;
                }
            }
        }
        cout << ans << "\n";
    }
   
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
