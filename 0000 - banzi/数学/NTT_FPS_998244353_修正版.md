# NTT / FPS 手敲板子（998244353）

| 用法 | 用途 | 条件 / 说明 |
| --- | --- | --- |
| `power(a, e)` | 模意义下的快速幂 | `e >= 0` |
| `ntt(a, 0)` / `ntt(a, 1)` | NTT / 逆 NTT | 原地修改 |
| `mul(a, b)` | 多项式乘法 | 自动取模；非空时返回 `a.size() + b.size() - 1` 项 |
| `cut(a, n)` | 截断或补零到 `n` 项 | 相当于 `resize(n)` |
| `deriv(a)` | 求导 | 少一项，空数组仍为空 |
| `integ(a)` | 积分 | 多一项，常数项为 `0` |
| `inv(a, n)` | 多项式求逆 | `a[0] != 0` |
| `ln(a, n)` | 多项式对数 | `a[0] == 1` |
| `NTT::exp(a, n)` | 多项式指数 | `a[0] == 0` |
| `fpow(a, e, n)` | 多项式快速幂 | `e >= 0`，支持前导零，约定零次幂为 `1` |

注意事项：

- `poly` 是 `vector<int>`，系数从低次到高次。FPS 输入须在 `[0, P)`，负数用 `(x % P + P) % P` 处理。
- `n >= 0`；FPS 返回恰好 `n` 项，保留末尾零；`n = 0` 返回空数组。
- NTT 长度须为正的二次幂，且不超过 $2^{23}$。

## 常用代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace NTT {

    const int P = 998244353, G = 3;

    int power(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % P;
            a = a * a % P, b >>= 1;
        }
        return res;
    }

    void ntt(vector<int> &a, bool inv) {
        int n = a.size();
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            while (j & bit) j ^= bit, bit >>= 1;
            j ^= bit;
            if (i < j) swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) {
            int wn = power(G, (P - 1) / len);
            if (inv) wn = power(wn, P - 2);
            for (int i = 0; i < n; i += len) {
                int w = 1;
                for (int j = 0; j < len / 2; j++) {
                    int x = a[i + j];
                    int y = a[i + j + len / 2] * w % P;
                    a[i + j] = (x + y) % P;
                    a[i + j + len / 2] = (x - y + P) % P;
                    w = w * wn % P;
                }
            }
        }
        if (inv) {
            int in = power(n, P - 2);
            for (int &x : a) x = x * in % P;
        }
    }

    vector<int> mul(vector<int> a, vector<int> b) {
        if (a.empty() || b.empty()) return {};
        int need = a.size() + b.size() - 1, n = 1;
        while (n < need) n <<= 1;
        for (int &x : a) x = (x % P + P) % P;
        for (int &x : b) x = (x % P + P) % P;
        a.resize(n), b.resize(n);
        ntt(a, 0), ntt(b, 0);
        for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % P;
        ntt(a, 1);
        a.resize(need);
        return a;
    }

    using poly = vector<int>;
    poly cut(poly a, int n) { a.resize(n); return a; }

    poly deriv(poly a) {
        for (int i = 1; i < (int)a.size(); i++) a[i - 1] = a[i] * i % P;
        if (!a.empty()) a.pop_back();
        return a;
    }
    poly integ(poly a) {
        static poly iv{0, 1};
        for (int i = iv.size(); i <= (int)a.size(); i++)
            iv.push_back((P - P / i) * iv[P % i] % P);
        a.insert(a.begin(), 0);
        for (int i = 1; i < (int)a.size(); i++) a[i] = a[i] * iv[i] % P;
        return a;
    }
    poly inv(poly a, int n) {
        if (!n) return {};
        poly b{power(a[0], P - 2)};
        for (int m = 2; (int)b.size() < n; m <<= 1) {
            int k = min(m, n);
            auto t = cut(mul(cut(a, k), b), k);
            for (int &x : t) x = (P - x) % P;
            t[0] = (t[0] + 2) % P;
            b = cut(mul(b, t), k);
        }
        return b;
    }
    poly ln(poly a, int n) {
        if (!n) return {};
        a.resize(n);
        auto b = mul(deriv(a), inv(a, n));
        return cut(integ(cut(b, n - 1)), n);
    }
    poly exp(poly a, int n) {
        a.resize(n);
        poly b{1};
        for (int m = 2; (int)b.size() < n; m <<= 1) {
            int k = min(m, n);
            auto t = ln(b, k);
            for (int i = 0; i < k; i++) t[i] = (a[i] - t[i] + P) % P;
            t[0] = (t[0] + 1) % P;
            b = cut(mul(b, t), k);
        }
        return cut(b, n);
    }
} // namespace NTT
```

```cpp
namespace NTT {
poly fpow(poly a, int e, int n) {
    poly b(n);
    if (!n) return b;
    if (!e) { b[0] = 1; return b; }
    int t = 0;
    while (t < (int)a.size() && !a[t]) t++;
    if (t == (int)a.size() || (t && e > (n - 1) / t)) return b;
    int shift = t * e, c = a[t], ic = power(c, P - 2);
    a.erase(a.begin(), a.begin() + t);
    a.resize(n - shift);
    for (int &x : a) x = x * ic % P;
    a = ln(a, n - shift);
    for (int &x : a) x = x * (e % P) % P;
    a = exp(a, n - shift);
    c = power(c, e);
    for (int i = 0; i < (int)a.size(); i++) b[i + shift] = a[i] * c % P;
    return b;
}

vector<int> mulall(vector<vector<int>> f, int limit = -1) {
      // limit = -1：不截断
      // limit = k ：只保留前 k 项，即次数 < k
      // 例如只需要 0..M 次，就传 M + 1
    if (f.empty()) return {1};
    auto cut = [&](vector<int> &a) {
        if (limit != -1 && (int)a.size() > limit) {
            a.resize(limit);
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < (int)f.size(); i++) {
        cut(f[i]);
        if (f[i].empty()) return {};
        pq.push({(int)f[i].size(), i});
    }
    while (pq.size() > 1) {
        auto [s1, x] = pq.top(); pq.pop();
        auto [s2, y] = pq.top(); pq.pop();
        auto c = mul(f[x], f[y]);
        cut(c);

        int id = f.size();
        f.push_back(move(c));
        pq.push({(int)f[id].size(), id});
    }
    return f[pq.top().second];
}


} // namespace NTT
```
