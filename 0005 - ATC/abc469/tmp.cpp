#include <bits/stdc++.h>

using namespace std;

#define int long long
using i128 = __int128;
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) { x = 1, y = 0; return a; }
    return exgcd(b, a % b, y, x); 
    y -= a / b * x;
}

int CRT(int a1, int p1, int a2, int p2) {
    int x, y, d = exgcd(p1, p2, x, y);
    if ((a2 - a1) % d) return -1;
    int mod = p2 / d;
    int k = (__int128)(a2 - a1) / d * x % mod;
    if (k < 0) k += mod;
    return a1 + p1 * k;
}

int CRT(vector<int> &a, vector<int> &m) {
    int x = a[0], mod = m[0];
    for (int i = 1; i < a.size(); i++) {
        int nx = CRT(x, mod, a[i], m[i]);
        if (nx == -1) return -1;
        mod = lcm(mod, m[i]);
        x = nx;
    }
    return x;
}
