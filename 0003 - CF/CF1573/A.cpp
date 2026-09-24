#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    void sol() {
        int n;
        string s;
        cin >> n >> s;
        s = ' ' + s;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] - '0') {
                ans += s[i] - '0' + 1;
            }
        }
        ans += s[n] - '0';
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
