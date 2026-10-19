### FWT（OR / AND / XOR 卷积）

求 $c_k=\sum_{i\circ j=k}a_i b_j$，其中 $\circ$ 为按位 OR、AND 或 XOR。`op=0/1/2` 分别对应三种运算；`f=1/-1` 表示正/逆变换。长度补到不小于两个输入长度的最小二次幂，时间 $O(N\log N)$、空间 $O(N)$。

`FWT_Mod` 默认模数 `998244353`，输入系数先归一化到 `[0,mod)`；XOR 要求模数为奇数，模数取常见的 32 位正数以保证乘法不溢出。`FWT_Raw` 不取模，XOR 逆变换中的除法恰整除；所有中间结果须在 `int` 范围内（公共头已设 `int=ll`）。单独调用 `transform` 时，数组非空且长度为二次幂。

```cpp
struct FWT_Mod {
    int mod, inv2;
    FWT_Mod(int m = 998244353) : mod(m), inv2((m + 1) / 2) {}

    // op: 0-OR, 1-AND, 2-XOR | f: 1-正变换, -1-逆变换
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

    vector<int> conv(vector<int> a, vector<int> b, int op) {
        int n = 1;
        while (n < max(a.size(), b.size())) n <<= 1;
        a.resize(n); b.resize(n);
        transform(a, op, 1); transform(b, op, 1);
        for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % mod;
        transform(a, op, -1);
        return a;
    }
};

struct FWT_Raw {
    // op: 0-OR, 1-AND, 2-XOR | f: 1-正变换, -1-逆变换
    void transform(vector<int>& a, int op, int f) {
        int n = a.size();
        for (int l = 2; l <= n; l <<= 1) {
            int m = l >> 1;
            for (int i = 0; i < n; i += l) for (int j = 0; j < m; j++) {
                int &x = a[i + j], &y = a[i + j + m], u, v;
                if (op == 0) y += (f == 1 ? x : -x);
                else if (op == 1) x += (f == 1 ? y : -y);
                else {
                    u = x, v = y;
                    if (f == 1) x = u + v, y = u - v;
                    else x = (u + v) / 2, y = (u - v) / 2;
                }
            }
        }
    }

    vector<int> conv(vector<int> a, vector<int> b, int op) {
        int n = 1;
        while (n < max(a.size(), b.size())) n <<= 1;
        a.resize(n); b.resize(n);
        transform(a, op, 1); transform(b, op, 1);
        for (int i = 0; i < n; i++) a[i] *= b[i];
        transform(a, op, -1);
        return a;
    }
};
```

```cpp
FWT_Mod fwt;
auto c = fwt.conv({1, 2}, {3, 4}, 2); // XOR: {11, 10}
```
