#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    int gcd (int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int x = 1;
        for (int i = n; i > 1; i--) {
            if (a[i] % a[i - 1] == 0) continue;
            else a[i - 1] /= x;
            if (a[i] % a[i - 1] == 0) continue;
            else {
                int y = a[i - 1] / gcd(a[i], a[i - 1]);
                a[i - 1] /= y;
                x *= y;
            }
        }
        cout << x << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
/*
3 3
010
101
010
*/
