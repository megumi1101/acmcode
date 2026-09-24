#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        if (n == 4) cout << "-1\n";
        else if (n == 2) cout << "1 2\n";
        else if (n == 3) cout << "1 2\n1 3\n";
        else {
            int k;
            cout << "1 2\n1 3\n";
            if (n & 1) cout << "1 "  << n << "\n", n--; 
            for (int i = 4; i <= min(n, 5); i++) {
                cout << "2 "  << i << "\n";
            }
            for (int i = 6; i <= min(n, 7); i++) {
                cout << "3 "  << i << "\n";
            }
            for (int i = 8; i <= n; i++) {
                if (i % 4 == 0 || i % 4 == 1) {
                    cout << (i / 4 - 1) * 4 << " " << i << "\n";
                }
                else {
                    cout << (i / 4 - 1) * 4 + 3 << " " << i << "\n";
                }
            }
        }
        
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        // init();
        int T = 1;
        cin >> T;
        while (T--) sol(); 
    }
#undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
