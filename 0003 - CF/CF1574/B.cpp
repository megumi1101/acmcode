#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    const int N = 2e5 + 10;
    const int inf = 1e18;
    void sol () {
        int a, b, c;
        int m;
        cin >> a >> b >> c >> m;
        if (a < b) swap(a, b);
        if (a < c) swap(a, c);
        if (b < c) swap(b, c);
        int mn = max(a - b - c - 1, (int)0) ;
        int mx = max((int)0, a - 1) + max((int)0, b - 1) + max((int)0, c - 1);
        if (m >= mn && m <= mx) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
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
