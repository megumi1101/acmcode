#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n, k;
        cin >> n >> k;
        if (n & 1) {
            if (k == 1) {
                cout << "YES\n";
                for (int i = 1; i <= n; i++) cout << i << "\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                for (int j = i; j <= n * k; j += n) {
                    cout << j << " ";
                }
                cout << "\n";
            }
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
    return Xbbbz::main(), 0;
}
