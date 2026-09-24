```cpp
#define int long long

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