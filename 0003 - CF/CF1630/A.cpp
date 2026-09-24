#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n, k;
        cin >> n >> k;
        if (k == 0) {
            for (int i = 0; i < n / 2; i++) {
                cout << i << " " << n - 1 - i << "\n";
            }
            return;
        }
        if (k == n - 1) {
            if (n > 4) {
                cout << n - 1 << " " << n - 2 << "\n";
                cout << n - 3 << " " << 0 << "\n";
                cout << 1 << " " << 3 << "\n";
                cout << 2 << " " << n - 4 << "\n";
                for (int i = 4 ; i < n / 2; i++) {
                    cout << i << " " << n - 1 - i << "\n";
                }
 
            }
            else cout << "-1\n";
            return;
        }
        cout << k << " " << n - 1 << "\n";
        cout << "0 " << n - 1 - k << "\n";
        for (int i = 1; i < n / 2; i++) {
            if (i == k || i == (n - 1 - k)) continue;
            cout << i << " " << n - 1 - i << "\n";
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz :: main(), 0;
}
