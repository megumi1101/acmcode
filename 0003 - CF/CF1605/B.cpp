#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    vector<int> tmp[2];
    int vis[N][2];
    void sol() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool fg = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0' && s[i - 1] == '1') {
                fg = 1;
                break;
            }
        }
        if (!fg) {
            cout  << "0\n";
            return;
        }
        cout << "1\n";
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') cnt++;
        }
        s = " " + s;
        int ans = 0;
        for (int i = 1; i <= cnt; i++) {
            if (s[i] == '1') ans++;
        }
        for (int i = cnt + 1; i <= n; i++) {
            if (s[i] == '0') ans++;
        }
        cout << ans << " ";
        for (int i = 1; i <= cnt; i++) {
            if (s[i] == '1') cout << i << " ";
        }
        for (int i = cnt + 1; i <= n; i++) {
            if (s[i] == '0') cout << i << " ";
        }
        cout << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) sol();
    }
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}
/*
1 3
5 4 3
*/
