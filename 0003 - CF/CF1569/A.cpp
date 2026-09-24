#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
 
    void sol() {
        int n;
        string s;
        cin >> n >> s;
        s = ' ' + s;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i + 1]) {
                cout << i << " " << i + 1 << "\n";
                return;
            }
        }
        cout << "-1 -1\n";
    }
   
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
}
 
int main() {
    return Xbbbz::main(), 0;
}
