#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    
    void sol() {
        string s;
        cin >> s;
        s = ' ' + s;
        int res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0' && s[i - 1] != '0') {
                res++;
            }
        }
        cout << min(res, (int)2) << "\n";
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
