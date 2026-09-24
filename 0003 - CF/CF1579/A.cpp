#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        string s;
        cin >> s;
        int res1  = 0, res2 = 0, res3 = 0;
        for (char c : s) {
            if (c == 'A') {
                res1++;
            }
            else if (c == 'B') {
                res2++;
            }
            else {
                res3++;
            }
        }
        if (res3 + res1 == res2) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
 
    void main() {
        int T;
        cin>>T;
        while(T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
