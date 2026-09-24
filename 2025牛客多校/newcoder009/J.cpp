#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    void sol() {
        int n;
        cin >> n;
        cout << n << " nya\n";
        cin.ignore();
        while (n--) {
            
            string s;
            getline(cin, s);
            cout << s << " nya\n";
        }
        
    
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}