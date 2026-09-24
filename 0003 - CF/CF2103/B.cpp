#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    void sol() {
        int ans = 0;
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = " " + s;
        s[0] = '0';
        
        for (int i = 1; i <= n; i++) {
            if (s[i] != s[i - 1]) ans++;
        }
        if (ans == 0) ;
        else if (ans <= 3) ans = 1;
        else ans -= 2;
        cout << ans + n << "\n";
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
