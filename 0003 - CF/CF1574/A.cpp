#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    const int N = 2e5 + 10;
    const int inf = 1e18;
    void sol () {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cout << "(";
            }
            for (int j = 1; j <= i; j++) {
                cout << ")";
            }
            for (int j = 1; j <= n - i; j++) {
                cout << "()";
            }
            cout << "\n";
        }
    }
    void main() {
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
