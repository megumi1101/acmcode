#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz{
    #define int long long
    const int inf = 1e18;
    void sol () {
        int n, x;
        cin >> n >> x;
        int a[n + 5];
        int b[n + 5];
        for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
        sort (b + 1, b + 1 + n);
        for (int i = n - x + 1; i <= x; i++) {
            if (a[i] != b[i]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) sol();
    }
 
    #undef int
}
 
int main() {
    return xbbbz::main(),0;
}
