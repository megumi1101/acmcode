## 双模hash
从 0 开始
```cpp
struct Base {
    array<int, N> pow{};
    Base(int mod) {
        pow[0] = 1;
        for (int i = 1; i < N; ++i) pow[i] = 1LL * pow[i - 1] * B % mod;
    }
    const int operator[](int idx) const { return pow[idx]; }
} p1(mod1), p2(mod2);

struct Hash {
    vector<int> h1, h2; // 前缀哈希，h[0] = 0

    void build(const string& s) {
        int n = (int)s.size();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            h1[i + 1] = ( (long long)h1[i] * B + (s[i] - 'a' + 1) ) % mod1;
            h2[i + 1] = ( (long long)h2[i] * B + (s[i] - 'a' + 1) ) % mod2;
        }
    }

    static int merge(int x, int y) { return (x << 31) | y; } 

    // 0-based 闭区间 [l, r]
    int calc(int l, int r) const {
        int len = r - l + 1;
        int res1 = ( h1[r + 1] - 1LL * h1[l] * p1[len] % mod1 + mod1 ) % mod1;
        int res2 = ( h2[r + 1] - 1LL * h2[l] * p2[len] % mod2 + mod2 ) % mod2;
        return merge(res1, res2);
    }
};
```
```cpp
const int mod = 998244391;
// mt19937 rng(random_device{}());
// const int B = uniform_int_distribution<int>(256, mod - 2)(rng);
const int B = 31415927;
struct Hash {
    vector<int> h, pw;

    void build(const string &s) {
        int n = s.size();
        h.resize(n + 1);
        pw.resize(n + 1);
        pw[0] = 1;
        for (int i = 0; i < n; i++) {
            pw[i + 1] = 1LL * pw[i] * B % mod;
            h[i + 1] = (1LL * h[i] * B + s[i]) % mod;
        }
    }

    // 0-based [l, r]
    int calc(int l, int r) {
        return (h[r + 1] - 1LL * h[l] * pw[r - l + 1] % mod + mod) % mod;
    }
};
```