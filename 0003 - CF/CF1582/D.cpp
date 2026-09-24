#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    void sol() {
        int n;
        cin >> n;
        int a[n + 5];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n % 2 == 0) {
            for (int i = 1; i <= n; i += 2) {
                cout << a[i + 1] * -1 << " " << a[i] << " ";
            }
            cout << "\n";
        }
        else {
            int x = a[1];
            int y = a[2];
            int z = a[3];
            int tmp = 1;
            if (x + y == 0) tmp = 2, x *= 2;
            cout << z * tmp << " " << z << " " << (x + y) * (-1) << " ";
            for (int i = 4; i <= n; i += 2) {
                cout << a[i + 1] * (-1) << " " << a[i] << " ";
            }
            cout << "\n";
        }
    }
    void main () {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
