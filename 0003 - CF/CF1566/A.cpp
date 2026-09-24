#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    
    void sol() {
        int n, s;
        cin >> n >> s;
        if (n == 1) {
            cout << s << "\n";
        }
        else {
            cout << s / (n - (n - 1) / 2) << "\n";
        }
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
