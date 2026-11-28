#include <bits/stdc++.h>

using namespace std;

#define int long long

using i128 = __int128;
// ax + by = gcd(a,b)，a,b >= 0
int exgcd(int a, int b, int &x, int &y) {
    if (!b) { x = 1, y = 0; return a; }
    int d = exgcd(b, a % b, y, x);
    y -= (i128)(a / b) * x; return d;
}

void sol() {
    int n, A, B;
    cin >> A >> B >> n;
    int r = n % B;
    if (r == 0) r = B;
    int u, v;
    exgcd(A, B, u, v);
    int y0 = v * -r;
    y0 %= A;
    if (y0 < 0) y0 += A;
    int up = y0 * B + r;

    // cerr << up << "\n";
    if (n <= up) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}
/*
7
2 1 1
2 1 2
2 1 3
2 1 100
314 159 265
314 159 2653
314 159 26535
*/
