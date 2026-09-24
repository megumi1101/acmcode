#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    int gcd (int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    void sol() { 
        int a, b ,k;
        cin >> a >> b >> k;
        int x = gcd(a, b);
        a /= x;
        b /= x;
        if (a <= k && b <= k) {
            cout << 1 << "\n";
        }
        else {
            cout << 2 << "\n";
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
 
int main() {
    return Xbbbz::main(), 0;
}
