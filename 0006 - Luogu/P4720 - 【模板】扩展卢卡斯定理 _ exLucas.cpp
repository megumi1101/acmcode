#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128_t;

// 安全模乘
inline i64 mul_mod(i64 a, i64 b, i64 mod) {
    return (i128)a * b % mod;
}

// 快速幂 (mod 可能很大)
i64 qpow(i64 a, i64 e, i64 mod) {
    i64 r = 1 % mod;
    while (e) {
        if (e & 1) r = mul_mod(r, a, mod);
        a = mul_mod(a, a, mod);
        e >>= 1;
    }
    return r;
}

// 扩展 gcd
i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (!b) { x = 1; y = 0; return a; }
    i64 x1, y1;
    i64 g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return g;
}

// ----------------- 模 p^k 的组合数 -----------------
struct ExLucas {
    i64 p, pk;
    vector<i64> f;

    ExLucas(i64 prime, int k) {
        p = prime;
        pk = 1;
        for (int i = 0; i < k; i++) pk *= p;
        f.resize(pk);
        f[0] = 1;
        for (i64 i = 1; i < pk; i++) {
            if (i % p == 0) f[i] = f[i - 1];
            else f[i] = mul_mod(f[i - 1], i, pk);
        }
    }

    // fact(n) 去掉 p 因子部分
    i64 fact(i64 n) {
        if (n == 0) return 1;
        i64 res = qpow(f[pk - 1], n / pk, pk);
        res = mul_mod(res, f[n % pk], pk);
        return mul_mod(res, fact(n / p), pk);
    }

    // n! 中 p 的指数
    i64 vp(i64 n) {
        i64 ans = 0;
        while (n) n /= p, ans += n;
        return ans;
    }

    // C(n,m) mod p^k
    i64 C(i64 n, i64 m) {
        if (m < 0 || m > n) return 0;
        i64 a = fact(n);
        i64 b = fact(m);
        i64 c = fact(n - m);
        i64 e = vp(n) - vp(m) - vp(n - m);
        i64 denom = mul_mod(b, c, pk);
        i64 x, y;
        exgcd(denom, pk, x, y);
        x = (x % pk + pk) % pk;
        i64 res = mul_mod(a, x, pk);
        res = mul_mod(res, qpow(p, e, pk), pk);
        return res;
    }
};

// ----------------- 中国剩余定理 CRT -----------------
i64 CRT(const vector<i64>& a, const vector<i64>& m) {
    i64 M = 1;
    for (auto v : m) M *= v;
    i64 ans = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        i64 Mi = M / m[i];
        i64 x, y;
        exgcd(Mi, m[i], x, y);
        x = (x % m[i] + m[i]) % m[i];
        ans = (ans + (i128)a[i] * Mi % M * x % M) % M;
    }
    return (ans % M + M) % M;
}

// ----------------- 示例 -----------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, m, M;
    cin >> n >> m >> M;  // 输入 n, m, 模数 M

    vector<i64> mods, rems;
    i64 tmp = M;
    for (i64 p = 2; p * p <= tmp; p++) {
        if (tmp % p == 0) {
            int k = 0;
            i64 pk = 1;
            while (tmp % p == 0) tmp /= p, pk *= p, k++;
            ExLucas luc(p, k);
            rems.push_back(luc.C(n, m));
            mods.push_back(pk);
        }
    }
    if (tmp > 1) { // 剩余质因子
        ExLucas luc(tmp, 1);
        rems.push_back(luc.C(n, m));
        mods.push_back(tmp);
    }

    cout << CRT(rems, mods) % M << "\n";
}
