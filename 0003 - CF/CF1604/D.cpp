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
        int x, y;
        cin >> x >> y;
        if (x > y) {
            cout << x + y << "\n";
        }
        else if (x == y) {
            cout << x << "\n";
        }
        else {
            cout << (y / x * x + y) / 2 << "\n";
        }
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
