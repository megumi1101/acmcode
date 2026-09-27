```cpp
#define int long long
const int mod = 998244353, inf = 1e9;
vector<int> fac, ifac, inv;

void init(int n) {
    fac.assign(n + 1, 1);
    ifac.assign(n + 1, 1);
    inv.assign(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }
}

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}


#define int long long
const int mod = 998244353;
// s[n][k]：n 个不同元素组成 k 个置换循环的方案数
vector<vector<int>> s;
void init(int n) {
    s.assign(n + 1, vector<int>(n + 1));
    s[0][0] = 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++)
        // 新元素单独成环，或插入已有循环的 i - 1 个位置之一
        s[i][j] = (s[i - 1][j - 1] + (i - 1) * s[i - 1][j]) % mod;
}


#define int long long
const int mod = 998244353;
// s[n][k]：n 个不同元素划分成 k 个非空、无标号集合的方案数
vector<vector<int>> s;
void init(int n) {
    s.assign(n + 1, vector<int>(n + 1));
    s[0][0] = 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++)
        // 新元素单独成集合，或加入已有的 j 个集合之一
        s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % mod;
}
```