#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    void sol() {
        int n; 
        cin >> n;
        string s, t;
        cin >> s >> t;
        int f[n + 5];
        memset(f, 0 ,sizeof(f));
        f[0] = 1;
        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1] & (s[i] == '0' || t[i] == '0'); 
        }
        if (f[n - 1]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    void main () {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
