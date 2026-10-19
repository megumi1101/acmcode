#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

int inv(int a) {
    return fap(a, mod - 2);
}

signed main() {
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> r[i];

    int e = 0;
    int e2 = 0;
    for (int i = 1; i <= n; i++) {
        int mxl = max(l[i], l[i - 1]);
        int mnr = min(r[i], r[i - 1]);

        int mul = (r[i] - l[i] + 1) * (r[i - 1] - l[i - 1] + 1);
        int p = mod + 1 - max(mnr - mxl + 1, 0LL) * inv(mul) % mod;
        p %= mod;

        // cout << p << "\n";
        (e2 += p * (2 * e % mod + 1) % mod) %= mod;
        (e += p) %= mod;
    }
    cout << e2 << "\n";
    
}

/*
4
-
+ 1
+ 2
-
*/