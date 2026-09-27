#include <bits/stdc++.h>

using namespace std;

#define int long long
#define debug(x) cerr << #x << " = " << x << '\n'

const int mod = 998244353;
const int inv2 = (mod + 1) / 2;
void transform(vector<int>& a, int op, int f) {
    int n = a.size();
    for (int l = 2; l <= n; l <<= 1) {
        int m = l >> 1;
        for (int i = 0; i < n; i += l) for (int j = 0; j < m; j++) {
            int &x = a[i + j], &y = a[i + j + m], u, v;
            if (op == 0) (f == 1) ? y = (y + x) % mod : y = (y - x + mod) % mod;
            else if (op == 1) (f == 1) ? x = (x + y) % mod : x = (x - y + mod) % mod;
            else {
                u = x, v = y;
                if (f == 1) x = (u + v) % mod, y = (u - v + mod) % mod;
                else x = (u + v) * inv2 % mod, y = (u - v + mod) * inv2 % mod;
            }
        }
    }
}

int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b /= 2;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, L, R;
    cin >> n >> m >> L >> R;
    if ((n & 1) && (m & 1)) {
        cout << fap(R - L + 1, n * m) << "\n";
    } else {
        vector<int> a(2);
        int t = (R - L + 1) / 2; 
        if ((R - L + 1) & 1) {
            if (L & 1) {
                a = {t, t + 1};
            } else {
                a = {t + 1, t};
            }
        } else {
            a = {t, t};
        }
        transform(a, 2, 1);
        a[0] = fap(a[0], n * m);
        a[1] = fap(a[1], n * m);
        transform(a, 2, -1);
        cout << a[0] << "\n";
    }
}