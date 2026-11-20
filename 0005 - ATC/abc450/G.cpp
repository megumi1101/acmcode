#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

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

int C(int n, int b = 2) {
    return ((n * (n - 1)) / 2) % mod;
}

void norm(int &n) {
    n %= mod;
    if (n < 0) n += mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    int ans = 0;
    
    int p = inv(C(n, 2)); // 在一起
    int now = 1;//暂时可能在一起概率

    for (int j = n - 2; j >= 2; j--) {
        now *= C(j, 2) * inv(C(j + 2, 2)) % mod;
        norm(now);
        p += now * inv(C(j + 1, 2));
        norm(p);
    }

    int p_ = p + (1 - p) * inv(2) % mod;
    norm(p_);
    int del = (1 - p_) - p_;
    norm(del);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ans += x * x % mod;
        ans %= mod;

        ans += 2 * sum % mod * x % mod * del % mod;
        ans %= mod;
        sum += x;
    }
    cout << ans << "\n";
}