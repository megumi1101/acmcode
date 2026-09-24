#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 2; i <= n; i++) {
            cout << "XOR 1 " << i << endl;
            cin >> a[i];
        }
 
        for (int i = 2; i <= n; i++) {
            if (a[i] == 0) {
                cout << "AND 1 " << i << endl;
                int x;
                cin >> x;
 
                cout << "! ";
                for (int i = 1; i <= n; i++) {
                    cout << (a[i] ^ x) << " ";
                }
                cout << endl;
                return;
            }
        }
        
        // a[1] = a[i] ^ x;
        for (int i = 2; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i] == a[j]) {
                    cout << "AND " << i << " " << j << endl;
                    int x;
                    cin >> x;
                    x ^= a[i];
 
                    cout << "! ";
                    for (int i = 1; i <= n; i++) {
                        cout << (a[i] ^ x) << " ";
                    }
                    cout << endl;
                    return;
                }
            }
        }
        
        int mask = n - 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if ((a[i] ^ a[j]) == mask) {
                    cout << "AND " << 1 << " " << i << endl;
                    int x, y;
                    cin >> x;
                    cout << "AND " << 1 << " " << j << endl;
                    cin >> y;
                    x ^= y;
 
                    cout << "! ";
                    for (int i = 1; i <= n; i++) {
                        cout << (a[i] ^ x) << " ";
                    }
                    cout << endl;
                    return;
                }
            }
        }
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
