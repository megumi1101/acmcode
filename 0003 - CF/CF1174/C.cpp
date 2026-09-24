#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    bool pd (int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return 0;
        }
        return 1;
    }
    void sol() {
        int n;
        cin >> n;
        int a[n + 5];
        memset(a, 0, sizeof(a));
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (!a[i]) {
                a[i] = ++cnt;
            }
            else continue;
            for (int j = 2 * i; j <= n; j += i) {
                if (!a[j]) a[j] = cnt;
            }
        } 
        for (int i = 2; i <= n; i++) {
            cout << a[i] << " ";
        } 
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }
    #undef int
}
 
int main() {
    return Xbbbz :: main(), 0;
}
