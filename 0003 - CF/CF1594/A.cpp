#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    #define int long long
    
    void sol() {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "0 1\n";
            return;
        }
        if (n & 1) {
            cout << 1 - n / 2 << " " << 1 + n / 2 << "\n"; 
        }
        else {
            cout << 1 - n << " " << n << "\n";
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
