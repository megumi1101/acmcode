#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e6 + 10;
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }
    void sol() {
        int n;
        cin >> n;
        int a[n + 5];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int d = 2;
        for (int i = 1; i <= n; i++) {
            d = lcm(d, i + 1);
            if (a[i] % d == 0) {
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
    return Xbbbz::main(), 0;
}
