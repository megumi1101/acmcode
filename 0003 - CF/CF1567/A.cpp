#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    void sol() {
        int n;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            if(s[i] == 'U') s[i] = 'D';
            else if(s[i] == 'D') s[i] = 'U';
        }
        cout << s << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
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
