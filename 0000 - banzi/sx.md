- [组合数学](#组合数学)
  - [lucas](#lucas)
  - [exlucas](#exlucas)
  - [二项式反演](#二项式反演)
  - [常见OGF](#常见ogf)
  - [幂次求和](#幂次求和)
- [dp](#dp)
  - [斜率优化](#斜率优化)
  - [数位dp](#数位dp)
- [多项式大全](#多项式大全)
  - [FFT](#fft)
  - [NTT](#ntt)
- [二进制常用小技巧](#二进制常用小技巧)
  - [求lg取整\&\&stein求gcd\&\&手写bitset](#求lg取整stein求gcd手写bitset)
- [线性代数](#线性代数)
  - [求解线性方程组](#求解线性方程组)
  - [矩阵求逆](#矩阵求逆)
  - [线性基](#线性基)
  - [前缀线性基](#前缀线性基)
- [my计算几何](#my计算几何)
- [数论基础](#数论基础)
  - [素数](#素数)
    - [素数分布](#素数分布)
    - [素数间隔](#素数间隔)
    - [Miller\_rabin](#miller_rabin)
  - [筛法](#筛法)
    - [线性筛](#线性筛)
    - [线性筛求约数个数](#线性筛求约数个数)
    - [线性筛求约数和](#线性筛求约数和)
  - [裴蜀定理](#裴蜀定理)
  - [费马小定理](#费马小定理)
  - [欧拉定理](#欧拉定理)
    - [扩展欧拉定理：](#扩展欧拉定理)
  - [威尔逊定理](#威尔逊定理)
    - [hdu2973 YAPTCHA](#hdu2973-yaptcha)
  - [线性求逆元](#线性求逆元)
  - [拓展欧几里得算法](#拓展欧几里得算法)
    - [线性丢番图方程](#线性丢番图方程)
  - [CRT(中国剩余定理)](#crt中国剩余定理)
    - [excrt](#excrt)
  - [分解质因数](#分解质因数)
    - [朴素做法](#朴素做法)
    - [Pollard\_Rho](#pollard_rho)
  - [欧拉函数](#欧拉函数)
    - [试除法求欧拉函数](#试除法求欧拉函数)
  - [BSGS](#bsgs)
  - [扩展 BSGS 算法](#扩展-bsgs-算法)
  - [整除分块](#整除分块)
  - [狄利克雷卷积](#狄利克雷卷积)
  - [莫比乌斯反演](#莫比乌斯反演)
  - [杜教筛](#杜教筛)
  - [基于值域预处理的快速GCD](#基于值域预处理的快速gcd)

# 组合数学
## lucas
C(n, m) % P
* 预处理 $P$：$O(P)$。
* 单次组合数：$O(\log_p n)$。

**定理内容：**
设 $p$ 是质数，$m,n$ 是非负整数。
把 $m,n$ 都写成 **p 进制展开**：

$$
m = m_k p^k + m_{k-1} p^{k-1} + \cdots + m_1 p + m_0
$$

$$
n = n_k p^k + n_{k-1} p^{k-1} + \cdots + n_1 p + n_0
$$

其中每个 $m_i, n_i \in [0, p-1]$。

那么有：

$$
\binom{m}{n} \equiv \prod_{i=0}^k \binom{m_i}{n_i} \pmod{p}.
$$

```cpp
struct Lucas {
    long long p;
    vector<long long> fact, invfact;
    bool ready = false;

    Lucas(long long prime = -1) { if (prime > 0) init(prime); }

    void init(long long prime){
        p = prime;
        fact.resize(p);
        invfact.resize(p);
        fact[0] = 1;
        for (long long i = 1; i < p; ++i) fact[i] = fact[i-1] * i % p;
        invfact[p-1] = qpow(fact[p-1], p-2, p);           // 费马小定理
        for (long long i = p-2; i >= 0; --i) invfact[i] = invfact[i+1] * (i+1) % p;
        ready = true;
    }

    // 计算 C(n, k) (0 <= n,k < p) ，要求已 init
    inline long long comb_small(long long n, long long k) const {
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % p * invfact[n-k] % p;
    }

    // Lucas 主过程：适用于任意大的 n, k
    // 先把 n, k 用 p 进制逐位拆分，做按位的组合数相乘
    long long C(long long n, long long k) const {
        if (!ready) return -1;           // 未 init
        if (k < 0 || k > n) return 0;
        long long res = 1;
        while (n > 0 || k > 0) {
            long long ni = n % p;
            long long ki = k % p;
            if (ki > ni) return 0;       // 任一位不够选 → 结果 0
            res = res * comb_small(ni, ki) % p;
            n /= p; k /= p;
        }
        return res;
    }
};
```


## exlucas
C(n, m) % M
* 分解 $M$：$O(\sqrt{M})$。
* 单次组合数：$O(\log_p n)$。
```cpp
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

// ---------------- 模 p^k 的组合数 -----------------
struct ExLcas {
    i64 p,pk;
    vectori64> f;

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
```

## 二项式反演

$$
f(n) = \sum_{i=m}^n \binom{n}{i} g(i) 
\;\;\;\Longleftrightarrow\;\;\;
g(n) = \sum_{i=m}^n (-1)^{n-i} \binom{n}{i} f(i).
$$


$$
f(n) = \sum_{i=n}^m \binom{i}{n} g(i) 
\;\;\;\Longleftrightarrow\;\;\;
g(n) = \sum_{i=n}^m (-1)^{i-n} \binom{i}{n} f(i).
$$

记 \(f(n)\) 表示“钦定选 \(n\) 个”，\(g(n)\) 表示“恰好选 \(n\) 个”，  
则对于任意 \(i \geq n\)，\(g(i)\) 在 \(f(n)\) 中被计算了 \(\binom{i}{n}\) 次，  

故
\[
f(n) = \sum_{i=n}^m \binom{i}{n} g(i).
\]


## 常见OGF
$$
\frac{1}{1-x} = 1 + x + x^2 + x^3 + \cdots = \sum_{n\ge0} x^n
$$


$$
\frac{1}{(1-x)^k} = \sum_{n\ge0} \binom{n+k-1}{k-1} x^n
$$


$$
\frac{x^k}{(1-x)^{k+1}} = \sum_{n\ge k} \binom{n}{k} x^n
$$

---
$$
\frac{1}{\sqrt{1-4x}} = \sum_{n\ge0} \binom{2n}{n} x^n
$$

* 表示：长度为 $2n$ 的 Dyck 路径计数、括号匹配等问题常出现。
  
---

$$
\frac{x}{1-x-x^2} = \sum_{n\ge0} F_n x^n
$$

* 表示：斐波那契数列的生成函数。
---
$$
\frac{1-\sqrt{1-4x}}{2x} = \sum_{n\ge0} C_n x^n,\quad C_n=\frac{1}{n+1}\binom{2n}{n}
$$

* 表示：卡特兰数（括号序列、树结构、格点路径等）。
---
$$
-\frac{\ln(1-x)}{1-x} = \sum_{n\ge1} H_n x^n,\quad H_n=\sum_{k=1}^n \frac{1}{k}
$$

* 表示：调和数生成函数，用于渐近分析。
---
$$
\prod_{k=1}^\infty \frac{1}{1-x^k} = \sum_{n\ge0} p(n)x^n
$$

* 表示：将整数 $n$ 拆分成若干正整数之和的方式数 $p(n)$。


给你最常用的 **幂次数列求和（Faulhaber）公式**，从 $n^1$ 到 $n^8$ 都列成闭式，顺便给出通用公式。

## 幂次求和
$$
\begin{aligned}
\sum_{k=1}^{n} k
&= \frac{n(n+1)}{2},\\[4pt]
\sum_{k=1}^{n} k^2
&= \frac{n(n+1)(2n+1)}{6},\\[4pt]
\sum_{k=1}^{n} k^3
&= \left(\frac{n(n+1)}{2}\right)^2,\\[4pt]
\sum_{k=1}^{n} k^4
&= \frac{n(n+1)(2n+1)(3n^2+3n-1)}{30},\\[4pt]
\sum_{k=1}^{n} k^5
&= \frac{n^2(n+1)^2(2n^2+2n-1)}{12},\\[4pt]
\sum_{k=1}^{n} k^6
&= \frac{n(n+1)(2n+1)\big(3n^4+6n^3-3n+1\big)}{42},\\[4pt]
\sum_{k=1}^{n} k^7
&= \frac{n^2(n+1)^2\big(3n^4+6n^3-n^2-4n+2\big)}{24},\\[4pt]
\sum_{k=1}^{n} k^8
&= \frac{n(n+1)(2n+1)\big(5n^6+15n^5+5n^4-15n^3-n^2+9n-3\big)}{90}.
\end{aligned}
$$

通用公式（Faulhaber）

设 $B_j$ 为伯努利数（取 $B_1=-\tfrac12$ 的约定），则

$$
\boxed{\;\sum_{k=1}^{n} k^m
= \frac{1}{m+1}\sum_{j=0}^{m} (-1)^j \binom{m+1}{j}\, B_j\, n^{\,m+1-j}\;}
$$

另一种等价表达（用第二类斯特林数）

记 $\{m\!\!\mid\!\! k\}$ 为第二类斯特林数、$(x)_{\underline{r}}=x(x-1)\cdots(x-r+1)$ 为降阶阶乘，则

$$
\boxed{\;\sum_{k=1}^{n} k^m
= \sum_{r=0}^{m} \big\{m\!\mid\! r\big\}\,\frac{(n+1)_{\underline{r+1}}}{r+1}
= \sum_{r=0}^{m} \big\{m\!\mid\! r\big\}\, r!\, \binom{n+1}{r+1}\;}
$$




# dp
## 斜率优化
四种情况一览

最小值 + x 递增：HullMin::query_inc(x)
最小值 + x 递减：HullMin::query_dec(x)
最大值 + x 递增：HullMax::query_inc(x)（内部是最小值壳 + 取反）
最大值 + x 递减：HullMax::query_dec(x)

```cpp
struct Line {
    long long m, b;
    long long f(long long x) const {
        __int128 v = (__int128)m * x + b;
        return (long long)v;
    }
};

static inline bool bad_lower(const Line& a, const Line& b, const Line& c){
    // 下凸壳（求最小值）判 b 冗余： (b-b_a)(m_b-m_c) >= (b_c-b_b)(m_a-m_b)
    __int128 L = (__int128)(b.b - a.b) * (b.m - c.m);
    __int128 R = (__int128)(c.b - b.b) * (a.m - b.m);
    return L >= R;
}

struct HullMin {               // 维护“最小值”的下凸壳
    std::deque<Line> q;
    void add(long long m, long long b){     // 斜率按一个方向单调加入（增或减都行）
        Line c{m,b};
        if (!q.empty() && q.back().m == m) { // 同斜率：保留截距更小的
            if (b >= q.back().b) return;
            q.pop_back();
        }
        while (q.size() >= 2 && bad_lower(q[q.size()-2], q.back(), c)) q.pop_back();
        q.push_back(c);
    }
    long long query_inc(long long x){       // x 递增
        while (q.size() >= 2 && q[0].f(x) >= q[1].f(x)) q.pop_front();
        return q[0].f(x);
    }
    long long query_dec(long long x){       // x 递减
        while (q.size() >= 2 && q.back().f(x) >= q[q.size()-2].f(x)) q.pop_back();
        return q.back().f(x);
    }
};

// “最大值”四种情况：用取反技巧复用下凸壳（最稳）
struct HullMax {
    HullMin H;                               // 在 H 里存 (-m, -b)
    void add(long long m, long long b){ H.add(-m, -b); }
    long long query_inc(long long x){ return -H.query_inc(x); } // x 递增
    long long query_dec(long long x){ return -H.query_dec(x); } // x 递减
};
```



斜率优化加二分(要求加入的斜率单调)

```cpp
// ===== 核心：最小值 + 斜率严格递减（任意顺序查询，二分） =====
struct LineInt {
    long long m, b;
    long long xLeft;   // 该线在壳中开始生效的最小整数 x
};

static inline long long floor_div128(__int128 a, __int128 b){
    // floor(a / b)   (b 允许为负；C++ / 向零取整需修正)
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return (long long)(a / b);
    return (long long)((a - (b - 1)) / b);
}
static inline long long ceil_div128(__int128 a, __int128 b){
    // ceil(a / b)
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return (long long)((a + (b - 1)) / b);
    return (long long)(a / b);
}

struct CHTMinBinInt {              // 要求：add 时 m 严格递减
    static constexpr long long NINF = (long long)-4e18;
    std::vector<LineInt> H;

    // 计算“new 从何处起优于 old”的最小整数 x
    static long long firstBetterX(const LineInt& oldL, const LineInt& neuL){
        // 使 neu(x) <= old(x)：
        // (m2 - m1) * x <= (b1 - b2)
        __int128 A = (__int128)oldL.b - neuL.b;
        __int128 B = (__int128)neuL.m - oldL.m;   // 对“递减”来说：B < 0
        // x >= ceil(A / B) （B 可能为负也 OK）
        return ceil_div128(A, B);
    }

    void clear(){ H.clear(); }
    int  size() const { return (int)H.size(); }

    void add(long long m, long long b){
        LineInt nl{m, b, NINF};
        if (!H.empty() && H.back().m == m){       // 同斜率：保留截距更小（求最小值）
            if (b >= H.back().b) return;
            H.pop_back();
        }
        while (!H.empty()){
            long long x = firstBetterX(H.back(), nl);
            if (x <= H.back().xLeft) H.pop_back(); // 末尾线完全被新线覆盖
            else { nl.xLeft = x; break; }
        }
        if (H.empty()) nl.xLeft = NINF;
        H.push_back(nl);
    }

    long long query(long long x) const {          // 任意顺序查询
        // 找到 xLeft <= x 的最后一条线
        int l = 0, r = (int)H.size() - 1, ans = r;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (H[mid].xLeft <= x){ ans = mid; l = mid + 1; }
            else r = mid - 1;
        }
        __int128 v = (__int128)H[ans].m * x + H[ans].b;
        return (long long)v;
    }
};

// ===== 四种封装：统一接口 add(m,b) / query(x) =====
// 1) 最小值 + 斜率递减（本体）
using CHTMinSlopeDec = CHTMinBinInt;

// 2) 最小值 + 斜率递增（映射：m'=-m, x'=-x）
struct CHTMinSlopeInc {
    CHTMinBinInt base;
    void add(long long m, long long b){ base.add(-m, b); }
    long long query(long long x) const { return base.query(-x); }
    void clear(){ base.clear(); }
    int  size() const { return base.size(); }
};

// 3) 最大值 + 斜率递减
//    max(m*x+b) = - min(m*(-x) + (-b))  → 传 (m, -b)，查 -x，再取反
struct CHTMaxSlopeDec {
    CHTMinBinInt base;
    void add(long long m, long long b){ base.add(m, -b); }
    long long query(long long x) const { return -base.query(-x); }
    void clear(){ base.clear(); }
    int  size() const { return base.size(); }
};

// 4) 最大值 + 斜率递增
//    max(m*x+b) = - min((-m)*x + (-b))  → 传 (-m, -b)，查 x，取反
struct CHTMaxSlopeInc {
    CHTMinBinInt base;
    void add(long long m, long long b){ base.add(-m, -b); }
    long long query(long long x) const { return -base.query(x); }
    void clear(){ base.clear(); }
    int  size() const { return base.size(); }
};

// long double 实现

// struct CHTMinBinLD { // 最小值 + 斜率严格递减
//     struct Line {
//         long long m, b;
//         long double xLeft; // 该线在壳中开始生效的 x（断点）
//     };

//     static inline long double INF() {
//         return std::numeric_limits<long double>::infinity();
//     }

//     // 交点：a(x) == b(x) 的 x，右侧由 b 更优（斜率递减：a.m > b.m）
//     static inline long double intersect(const Line& a, const Line& b) {
//         // 分母 b.m - a.m < 0；用 long double 防精度
//         return (long double)(a.b - b.b) / (long double)(b.m - a.m);
//     }

//     std::vector<Line> H; // xLeft 单调递增

//     void clear() { H.clear(); }
//     int  size()  const { return (int)H.size(); }

//     void add(long long m, long long b) {
//         Line nl{m, b, -INF()};
//         if (!H.empty() && H.back().m == m) {
//             // 同斜率：求最小值保留截距更小的
//             if (b >= H.back().b) return;
//             H.pop_back();
//         }
//         while (!H.empty()) {
//             long double x = intersect(H.back(), nl);
//             if (x <= H.back().xLeft) H.pop_back(); // 末尾线被完全覆盖
//             else { nl.xLeft = x; break; }
//         }
//         if (H.empty()) nl.xLeft = -INF();
//         H.push_back(nl);
//     }

//     // 整数 x 查询，返回 long long（内部用 128 位避免溢出）
//     long long query(long long x) const {
//         // 要求：调用前 H 非空
//         long double X = (long double)x;
//         int l = 0, r = (int)H.size() - 1, ans = r;
//         while (l <= r) {
//             int mid = (l + r) >> 1;
//             if (H[mid].xLeft <= X) { ans = mid; l = mid + 1; }
//             else r = mid - 1;
//         }
//         __int128 v = (__int128)H[ans].m * x + H[ans].b;
//         return (long long)v;
//     }

//     // 浮点 x 查询，返回 long double（可选）
//     long double query_ld(long double x) const {
//         int l = 0, r = (int)H.size() - 1, ans = r;
//         while (l <= r) {
//             int mid = (l + r) >> 1;
//             if (H[mid].xLeft <= x) { ans = mid; l = mid + 1; }
//             else r = mid - 1;
//         }
//         return (long double)H[ans].m * x + (long double)H[ans].b;
//     }
// };

```
## 数位dp
eg
```cpp
int dfs(int len,bool lim,int sum,int nowsum,int qm){
    if(!lim && f[qm][nowsum][len] != -1) return f[qm][nowsum][len];
    if(len == 0) {
        if((sum == nowsum) && (qm == 0)) return 1;
        else return 0;
    }
    int res = 0;
    int up = 9;
    if(lim) up = a[len];
    for(int i = 0; i <= up; i++){
        if(nowsum+i>sum)continue;
        res+=dfs(len-1,lim && (i == a[len]), sum, nowsum+i, (qm + (i * m10[len-1] % sum)) % sum);
    }
    if(!lim)f[qm][nowsum][len]=res;
    return res;
}
for(int i=1;i<=162;i++){
    ans+=sol(B,i)-sol(A-1,i);
}


int dfs(int last,int len,bool lim,bool qd){
    if(!lim&&f[last][len][qd]!=-1)return f[last][len][qd];
    if(len==0)return 1;
    int up=9;
    int res=0;
    if(lim)up=a[len];
    for(int i=0;i<=up;i++){
        if(qd)res+=dfs(i,len-1,lim&&(i==a[len]),i==0);
        else{
            if(abs(i-last)<2)continue;
            res+=dfs(i,len-1,lim&&(i==a[len]),0);
        } 
    }
    if(!lim)f[last][len][qd]=res;
    return res;
}

int dfs(int len,int last1,int last2,bool lim,bool qd,bool meng){
    if(!lim&&f[len][last1][last2][qd][meng]!=-1)return f[len][last1][last2][qd][meng];
    if(len==0){
        if(meng)return 1;
        return 0;
    }
    int up=lim?a[len]:9;
    int res=0;
    for(int i=0;i<=up;i++){
        if((meng)||(!qd&&(last1==i))||(!qd&&(last2==i)))res+=dfs(len-1,i,last1,lim&&(i==up),0,1),res%=mod;
        else res+=dfs(len-1,i,qd?11:last1,lim&&(i==up),qd&&(i==0),meng);
    }
    if(!lim)f[len][last1][last2][qd][meng]=res%mod;
    return res%mod;
}
```


# 多项式大全
## FFT
```cpp
#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    const int N = 1e6 + 10;
    const double PI = acos(-1.0);
    vector<int> R(N << 2);
    struct cpx {
        double x, y;
        cpx(double x = 0, double y = 0) :x(x), y(y) {}
    };

    cpx operator+(cpx a, cpx b) { 
        return cpx(a.x + b.x, a.y + b.y); 
    }

    cpx operator-(cpx a, cpx b) { 
        return cpx(a.x - b.x, a.y - b.y); 
    }

    cpx operator*(cpx a, cpx b) { 
        return cpx(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); 
    }

    void fft(vector<cpx> &a, int n, int op) {
        for(int i = 0; i < n; ++i)
            R[i] = R[i / 2] / 2 + ((i & 1) ? n / 2 : 0);
        
        for(int i = 0; i < n; ++i)
            if(i < R[i]) swap(a[i], a[R[i]]);
        
        for(int m = 2; m <= n; m <<= 1) {        
            cpx w1(cos(2 * PI / m), sin(2 * PI / m) * op);
            for(int i = 0; i < n; i += m) {       
                cpx wk(1, 0);
                for(int j = 0; j < m / 2; ++j) { 
                    cpx x = a[i + j], y = a[i + j + m / 2] * wk;
                    a[i + j] = x + y; 
                    a[i + j + m / 2] = x - y; 
                    wk = wk * w1;
                }
            }
        }
    }

    
    void sol() {
        int n, m;
        cin >> n >> m;
        int tmp = 1;
        for (; tmp <= n + m; tmp <<= 1);
        vector<cpx> a(tmp + 5), b(tmp + 5);
        for (int i = 0; i <= n; i++) cin >> a[i].x;
        for (int i = 0; i <= m; i++) cin >> b[i].x;
        fft(a, tmp, 1);
        fft(b, tmp, 1);
        for (int i = 0; i < tmp; i++) a[i] = a[i] * b[i];
        fft(a, tmp, -1);
        for (int i = 0; i <= n + m; i++) {
            cout << (int)(a[i].x / tmp + 0.5) << " ";
        }
    }

    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        // init();
        while (T--) {
            sol();
        }
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
```

## NTT
```cpp
Poly();                           // 空多项式 0
Poly(int a0);                     // 常数多项式 a0（若 a0=0 得到空）
Poly(const vector<int>& v);       // 以系数构造（自动去尾零）

int size() const;                 // 当前项数
int operator[](int i) const;      // 越界返回 0
int& coef(int i);                 // 可写访问（自动扩容）

Poly mulxk(int k) const;          // × x^k（前插 k 个 0）
Poly divxk(int k) const;          // 去掉最低 k 项（相当于 /x^k 向下取整）
Poly modxk(int k) const;          // 截断到 x^k 以下

Poly deriv() const;   // 求导：O(n)
Poly integr() const;  // 积分：O(n)，常数项=0

Poly inv(int m) const;          // f^{-1} mod x^m
// 前置：size()>0 且 a[0]!=0
// 复杂度：~O(m log m)

Poly log(int m) const;          // ln f mod x^m
// 前置：a[0]==1（常见约定）
// 复杂度：~O(m log m)

Poly exp(int m) const;          // exp(f) mod x^m
// 前置：f[0]==0
// 复杂度：~O(m log m)

Poly sqrt(int m, int c0=1) const; // s^2=f mod x^m
// 前置：c0^2 ≡ f[0] (mod P)（需给出正确常数根）
// 复杂度：~O(m log m)

Poly pow_u1(long long e, int m) const; // f^e, 要求 f[0]==1
Poly pow(long long e, int m) const;    // 通用：会自动处理前导零次数 t 与常数因子
// 复杂度：~O(m log m)

friend pair<Poly,Poly> divmod(Poly A, Poly B); // A = B*Q + R, deg R < deg B
friend Poly operator/(const Poly& A, const Poly& B); // Q
friend Poly operator%(const Poly& A, const Poly& B); // R
// 复杂度：~O(n log n)

Poly mulT(Poly b) const;         // 反转技巧：reverse(b) 与 *this 卷积后右移 n-1（多点求值/余式用）
vector<int> eval(vector<int> xs) const; // 多点求值 f(xs[i])
// 复杂度：~O(n log^2 n)

vector<int> convolution(const vector<int>& A, const vector<int>& B);
// 直接返回 A*B 的系数数组（NTT 卷积）




// ===== One-Dimensional FPS / NTT Library (mod 998244353) =====
// Single-header, C++17 OK
namespace FPS {
constexpr int P = 998244353;      // 119 * 2^23 + 1
constexpr int G = 3;

inline int norm(long long x){ x%=P; if(x<0) x+=P; return (int)x; }
int power(int a, long long e){
    long long r = 1, x = a;
    while(e){
        if(e & 1) r = r * x % P;
        x = x * x % P; e >>= 1;
    }
    return (int)r;
}

// ---------- NTT (iterative), shareable roots/rev ----------
static vector<int> rev;
static vector<int> roots{0,1};

void dft(vector<int> &a){
    int n = (int)a.size();
    if((int)rev.size() != n){
        int k = __builtin_ctz(n) - 1;       // log2(n) - 1
        rev.assign(n,0);
        for(int i=0;i<n;i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<k);
    }
    for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    if((int)roots.size() < n){
        int k = __builtin_ctz((int)roots.size());
        roots.resize(n);
        while((1<<k) < n){
            int e = power(G, (P-1)>>(k+1));
            for(int i=1<<(k-1); i<(1<<k); ++i){
                roots[i<<1] = roots[i];
                roots[i<<1|1] = (int)((long long)roots[i]*e%P);
            }
            ++k;
        }
    }
    for(int k=1; k<n; k<<=1){
        for(int i=0; i<n; i+= (k<<1)){
            for(int j=0; j<k; ++j){
                int u = a[i+j];
                int v = (int)((long long)a[i+j+k] * roots[k+j] % P);
                int x = u + v; if(x>=P) x-=P;
                a[i+j] = x;
                x = u - v; if(x<0) x += P;
                a[i+j+k] = x;
            }
        }
    }
} 
void idft(vector<int> &a){
    int n = (int)a.size();
    if(n==0) return;
    reverse(a.begin()+1, a.end()); // reuse forward DFT roots
    dft(a);
    int inv_n = power(n, P-2);
    for(int &x : a) x = (int)((long long)x * inv_n % P);
}

// ---------- Poly (1D) ----------
struct Poly {
    vector<int> a; // coef[0] + coef[1] x + ...

    Poly() {}
    Poly(int a0){ if(a0) a = {a0}; }
    Poly(const vector<int> &v): a(v){ shrink(); }

    inline void shrink(){ while(!a.empty() && a.back()==0) a.pop_back(); }
    inline int size() const { return (int)a.size(); }
    inline int operator[](int i) const { return (0<=i && i<size()) ? a[i] : 0; }
    inline int &coef(int i){ if(i >= (int)a.size()) a.resize(i+1); return a[i]; }

    // basic transforms with x^k
    Poly mulxk(int k) const { Poly r; r.a.assign(k,0); r.a.insert(r.a.end(), a.begin(), a.end()); return r; }
    Poly divxk(int k) const { if(size()<=k) return {}; return Poly(vector<int>(a.begin()+k, a.end())); }
    Poly modxk(int k) const { k=min(k,size()); return Poly(vector<int>(a.begin(), a.begin()+k)); }

    // +, -, *
    friend Poly operator+(const Poly &A, const Poly &B){
        Poly R; int n=max(A.size(),B.size()); R.a.resize(n);
        for(int i=0;i<n;i++){ int x=A[i]+B[i]; if(x>=P) x-=P; R.a[i]=x; }
        R.shrink(); return R;
    }
    friend Poly operator-(const Poly &A, const Poly &B){
        Poly R; int n=max(A.size(),B.size()); R.a.resize(n);
        for(int i=0;i<n;i++){ int x=A[i]-B[i]; if(x<0) x+=P; R.a[i]=x; }
        R.shrink(); return R;
    }
    friend Poly operator*(Poly A, Poly B){
        if(A.size()==0 || B.size()==0) return {};
        int need = A.size() + B.size() - 1;
        int n=1; while(n<need) n<<=1;
        A.a.resize(n); B.a.resize(n);
        dft(A.a); dft(B.a);
        for(int i=0;i<n;i++) A.a[i] = (int)((long long)A.a[i]*B.a[i]%P);
        idft(A.a);
        A.a.resize(need);
        A.shrink(); return A;
    }
    Poly& operator+=(const Poly& o){ return *this = *this + o; }
    Poly& operator-=(const Poly& o){ return *this = *this - o; }
    Poly& operator*=(const Poly& o){ return *this = *this * o; }

    // derivative & integral (indefinite, const term = 0)
    Poly deriv() const {
        if(size()==0) return {};
        vector<int> r(max((int)0,size()-1));
        for(int i=1;i<size();++i) r[i-1] = (int)((long long)a[i]*i%P);
        return Poly(r);
    }
    Poly integr() const {
        vector<int> r(size()+1); r[0]=0;
        for(int i=0;i<size();++i) r[i+1] = (int)((long long)a[i]*power(i+1, P-2)%P);
        return Poly(r);
    }

    // Newton inversion: require a[0] != 0, return f^{-1} mod x^m
    Poly inv(int m) const {
        assert(size() && a[0]!=0);
        Poly x(power(a[0], P-2));
        int k=1;
        while(k<m){
            k<<=1;
            Poly f = modxk(k);
            x = (x * (Poly(2) - f * x)).modxk(k);
        }
        return x.modxk(m);
    }

    // log: ln f (mod x^m). Usually require f[0] = 1.
    Poly log(int m) const {
        assert(size() && a[0]==1);
        return (deriv() * inv(m)).integr().modxk(m);
    }

    // exp: solve g with ln g = f (mod x^m). Require f[0] = 0.
    Poly exp(int m) const {
        assert(size()==0 || a[0]==0);
        Poly x(1); int k=1;
        while(k<m){
            k<<=1;
            // x <- x * (1 - ln x + f)  (mod x^k)
            Poly t = x.log(k);
            t = Poly(1) - t + modxk(k);
            x = (x * t).modxk(k);
        }
        return x.modxk(m);
    }

    // sqrt: solve s^2 = f (mod x^m). Need a[0] be quadratic residue; pass c0 = sqrt(a0).
    Poly sqrt(int m, int c0 = 1) const {
        // caller should ensure (1LL*c0*c0 - a0) % P == 0 and a0==c0^2
        Poly x(c0);
        int inv2 = (P+1)/2;
        int k=1;
        while(k<m){
            k<<=1;
            // x <- (x + f / x) / 2
            Poly xi = x.inv(k);
            x = (x + (modxk(k) * xi).modxk(k)) * inv2;
            x = x.modxk(k);
        }
        return x.modxk(m);
    }

    // fast power for formal series with f[0] = 1: g = f^e (mod x^m)
    Poly pow_u1(long long e, int m) const {
        assert(size()==0 || a[0]==1);
        if(m==0) return {};
        if(e==0) return Poly(1).modxk(m);
        return (this->log(m) * Poly((int)(e%P))).exp(m);
    }

    // general power (handle leading term shift). Returns f^e mod x^m.
    // If f = x^t * u, u[0]!=0, then f^e = x^{t e} * u^e.
    Poly pow(long long e, int m) const {
        if(m==0) return {};
        if(e==0) return Poly(1).modxk(m);
        if(size()==0) return {}; // 0^e = 0 for e>0

        // find the first non-zero
        int t=0; while(t<size() && a[t]==0) ++t;
        if(1LL*t*e >= m) return {}; // all terms truncated
        // u(x) = f(x)/x^t, with u[0]!=0
        Poly u = divxk(t);
        int u0 = u.a[0];
        int inv_u0 = power(u0, P-2);
        // normalize to u[0] = 1
        for(int &x : u.a) x = (int)((long long)x * inv_u0 % P);
        Poly w = u.log(m - t*(int)e);
        for(int &x : w.a) x = (int)((long long)x * (e%P) % P);
        w = w.exp(m - t*(int)e);
        // recover constant: (u0)^e
        int c = power(u0, e%(P-1)); // P is prime -> by Fermat on F_p^*
        for(int &x : w.a) x = (int)((long long)x * c % P);
        return w.mulxk((int)(t*e)).modxk(m);
    }

    Poly pow_big(const std::string& K, int m) const {
        if (m == 0) return {};
        // trim leading zeros
        auto trim = [](const std::string& s)->std::string{
            size_t p = s.find_first_not_of('0');
            return (p == std::string::npos) ? "0" : s.substr(p);
        };
        std::string k = trim(K);
        if (k == "0") return Poly(1).modxk(m);   // k=0 => 1
        if (size() == 0) return {};              // 0^k (k>0) => 0

        // 分解 f = x^t * u，u[0]!=0
        int t = 0; while (t < size() && a[t] == 0) ++t;
        if (t == size()) return {}; // f == 0

        long long shift = 0;
        if (t > 0) {
            long long bound = (m - 1) / t;                // 需要 t*k <= m-1
            // 是否 k > bound（十进制字符串和整数的比较）
            auto exceed = [&](const std::string& s)->bool{
                std::string b = std::to_string(bound);
                if (s.size() != b.size()) return s.size() > b.size();
                return s > b;
            };
            if (exceed(k)) return {};                     // 全被截断
            // 此时 k <= bound，安全转 64 位
            long long k64 = 0; for (char c: k) k64 = k64*10 + (c-'0');
            shift = 1LL * t * k64;                        // < m
        }

        // 归一化 u[0]=1
        Poly u = divxk(t);
        int u0 = u.a[0], invu0 = power(u0, P-2);
        for (int &x : u.a) x = (long long)x * invu0 % P;

        int need = m - (int)shift;
        if (need <= 0) return {};

        // 计算 (k mod P) 与 (k mod P-1)
        auto smod = [](const std::string& s, int mod)->int{
            long long r = 0; for (char c: s) r = (r*10 + (c-'0')) % mod; return (int)r;
        };
        int k_mod_p  = smod(k, P);
        int k_mod_p1 = smod(k, P-1);

        // w = exp( (k mod P) * ln u )  (mod x^need)
        Poly w = u.log(need);
        for (int &x : w.a) x = (long long)x * k_mod_p % P;
        w = w.exp(need);

        // 乘回常数因子 (u0)^k
        int c = power(u0, k_mod_p1);
        for (int &x : w.a) x = (long long)x * c % P;

        // 补上位移 x^{t*k}
        return w.mulxk((int)shift).modxk(m);
    }

    // Euclidean division: A = B * Q + R, deg R < deg B
    friend pair<Poly,Poly> divmod(Poly A, Poly B){
        A.shrink(); B.shrink();
        assert(B.size());
        if(A.size() < B.size()) return {Poly(), A};
        int n = A.size(), m = B.size();
        Poly Ar = A; reverse(Ar.a.begin(), Ar.a.end());
        Poly Br = B; reverse(Br.a.begin(), Br.a.end());
        int need = n - m + 1;
        Poly Q = (Ar.modxk(need) * Br.inv(need)).modxk(need);
        reverse(Q.a.begin(), Q.a.end());
        Poly R = A - B * Q;
        R.shrink();
        if(R.size() >= B.size()){
            // numerical safety (shouldn't happen if operations exact)
            R = R.modxk(B.size()-1);
        }
        return {Q, R};
    }
    friend Poly operator/(const Poly& A, const Poly& B){ return divmod(A,B).first; }
    friend Poly operator%(const Poly& A, const Poly& B){ return divmod(A,B).second; }

    // reverse-multiply trick (for remainder / multipoint)
    Poly mulT(Poly b) const {
        if(b.size()==0) return {};
        int n = b.size();
        reverse(b.a.begin(), b.a.end());
        return ((*this) * b).divxk(n-1);
    }

    // multipoint evaluation: return f(x_i)
    vector<int> eval(vector<int> xs) const {
        if(size()==0) return vector<int>(xs.size(), 0);
        int m = (int)xs.size();
        int n = 1; while(n<m) n<<=1;
        vector<Poly> seg(2*n);
        // build product tree
        for(int i=0;i<n;i++){
            if(i<m) seg[n+i] = Poly(vector<int>{norm(P- xs[i]), 1}); // (x - xi)
            else seg[n+i] = Poly(vector<int>{1});
        }
        for(int i=n-1;i>=1;--i) seg[i] = seg[i<<1] * seg[i<<1|1];

        // remainders down the tree
        vector<int> ans(m);
        function<void(int,const Poly&)> dfs = [&](int p, const Poly &f){
            if(p >= n){
                int idx = p - n;
                if(idx < m) ans[idx] = (f.size()? f.a[0] : 0);
                return;
            }
            Poly leftR  = f.mulT(seg[p<<1|1]).modxk(seg[p<<1].size()-1);
            Poly rightR = f.mulT(seg[p<<1]).modxk(seg[p<<1|1].size()-1);
            dfs(p<<1, leftR);
            dfs(p<<1|1, rightR);
        };
        Poly rem = this->mulT(seg[1]).modxk(seg[1].size()-1);
        dfs(1, rem);
        return ans;
    }
};

// convenience: convolution on vectors
vector<int> convolution(const vector<int>& A, const vector<int>& B){
    Poly a(A), b(B); Poly c = a*b; return c.a;
}
}
```

# 二进制常用小技巧
## 求lg取整&&stein求gcd&&手写bitset
```cpp
// __builtin_clzll 是 GCC 和 Clang 编译器提供的内置函数，用于计算无符号长整型（unsigned long long）数值的前导零位数（Count Leading Zeros）
//上取整
int lg(int x) {
    return 64 - __builtin_clzll(x - 1);
}
//下取整
int lg(int x) {
    return 63 - __builtin_clzll(x);
}


int gcd(int a, int b) {
    if (a == 0) return llabs(b);
    if (b == 0) return llabs(a);
    int x = llabs(a), y = llabs(b);

    int s = __builtin_ctzll(x | y);
    x >>= __builtin_ctzll(x);
    y >>= __builtin_ctzll(y);
    while (x != y) {
        if (x > y) x ^= y ^= x ^= y;
        y -= x;
        y >>= __builtin_ctzll(y);
    }

    return x << s;
}
```


```cpp
#include <bits/stdc++.h>
struct DynBitset {
    using u64 = unsigned long long;

    int n = 0;                    // 位数
    std::vector<u64> a;           // 低位在低索引块：bit i 在 a[i>>6] 的 (i&63)

    DynBitset() = default;
    explicit DynBitset(int n_, int fill = 0) { init(n_, fill); }

    void init(int n_, int fill = 0) {
    n = std::max(0, n_);
    a.assign((n + 63) >> 6, fill ? ~u64(0) : 0);
    trim();
    }

    int size() const { return n; }

    // —— 内部：清理最后一块多余位 ——
    void trim() {
    if (a.empty()) return;
    int r = n & 63;
    if (r) a.back() &= ((u64(1) << r) - 1);
    }

    // ===== 单点操作 =====
    void set(int pos)   { a[pos >> 6] |=  (u64(1) << (pos & 63)); }
    void reset(int pos) { a[pos >> 6] &= ~(u64(1) << (pos & 63)); }
    void flip(int pos)  { a[pos >> 6] ^=  (u64(1) << (pos & 63)); }
    bool test(int pos) const { return (a[pos >> 6] >> (pos & 63)) & 1; }

    // ===== 整体操作 =====
    void set_all()   { for (auto &x : a) x = ~u64(0); trim(); }
    void reset_all() { for (auto &x : a) x = 0; }
    void flip_all()  { for (auto &x : a) x = ~x; trim(); }

    // ===== 统计 / 查询 =====
    int count() const {
    int s = 0;
    for (u64 x : a) s += __builtin_popcountll((long long)x);
    return s;
    }
    // 不存在返回 -1
    int first_one() const {
    for (int i = 0; i < (int)a.size(); ++i) if (a[i])
        return (i << 6) + __builtin_ctzll((long long)a[i]);
    return -1;
    }
    // 不存在返回 -1
    int last_one() const {
    for (int i = (int)a.size() - 1; i >= 0; --i) if (a[i])
        return (i << 6) + 63 - __builtin_clzll((long long)a[i]);
    return -1;
    }

    // ===== 按位运算 =====
    DynBitset& operator&=(const DynBitset &o) {
    assert(n == o.n); for (size_t i = 0; i < a.size(); ++i) a[i] &= o.a[i]; return *this;
    }
    DynBitset& operator|=(const DynBitset &o) {
    assert(n == o.n); for (size_t i = 0; i < a.size(); ++i) a[i] |= o.a[i]; return *this;
    }
    DynBitset& operator^=(const DynBitset &o) {
    assert(n == o.n); for (size_t i = 0; i < a.size(); ++i) a[i] ^= o.a[i]; return *this;
    }
    friend DynBitset operator&(DynBitset x, const DynBitset &y){ return x &= y; }
    friend DynBitset operator|(DynBitset x, const DynBitset &y){ return x |= y; }
    friend DynBitset operator^(DynBitset x, const DynBitset &y){ return x ^= y; }

    // ===== 位移运算 =====
    DynBitset& operator<<=(int k) {
    if (k <= 0 || n == 0) return *this;
    int blk = k >> 6, sh = k & 63;
    std::vector<u64> b(a.size(), 0);
    for (int i = 0; i < (int)a.size(); ++i) {
        int j = i + blk;
        if (j >= (int)a.size()) break;
        b[j] |= (a[i] << sh);
        if (sh && j + 1 < (int)a.size()) b[j + 1] |= (a[i] >> (64 - sh));
    }
    a.swap(b); trim(); return *this;
    }

    DynBitset& operator>>=(int k) {
    if (k <= 0 || n == 0) return *this;
    int blk = k >> 6, sh = k & 63;
    std::vector<u64> b(a.size(), 0);
    for (int i = 0; i < (int)a.size(); ++i) {
        int j = i - blk;
        if (j < 0) continue;
        b[j] |= (a[i] >> sh);
        if (sh && j - 1 >= 0) b[j - 1] |= (a[i] << (64 - sh));
    }
    a.swap(b); trim(); return *this;
    }

    // ===== 输出转字符串（低位在前，如需高位在前可反转）=====
    std::string to_string() const {
    std::string s; s.reserve(n);
    for (int i = 0; i < n; ++i) s.push_back(test(i) ? '1' : '0');
    return s;                   // 低位 -> s[0]
    }
};

```

# 线性代数
## 求解线性方程组
有解返回 1 无穷多解返回 0 无解返回 -1 
最终结果需要除以a[i][i];
高斯约旦消元法
```cpp
int gsyd(int n) {
    int nw = 1;
    for (int j = 1; j <= n; j++) {
        int mxi = nw;
        for (int i = nw + 1; i <= n; i++) {
            if (fabs(a[i][j]) > fabs(a[mxi][j])) mxi = i;    
        }
        if (fabs(a[mxi][j]) < eps) continue;
        swap(a[nw], a[mxi]);
        for (int i = 1; i <= n; i++) {
            if (i == nw) continue;
            double x = a[i][j] / a[nw][j];
            for (int k = j; k <= n + 1; k++) {
                a[i][k] -= x * a[nw][k];
            }
        }
        nw++;
    }
    if (nw == n + 1) return 1;
    else {
        for (int i = nw; i <= n; i++) if (fabs(a[i][n + 1]) > eps) return -1;
        return 0;
    }
}
```
## 矩阵求逆
构造矩阵$(A,I)$
初等行变换求出$(I,A^{-1})$
$mod(1e9 + 7)$ 意义下
```cpp
int gsyd(int n) {
    for (int j = 1; j <= n; j++) {
        int mxi = j;
        for (int i = j + 1; i <= n; i++) {
            if (abs(a[i][j]) > abs(a[mxi][j])) mxi = i;    
        }
        if (abs(a[mxi][j]) == 0) return 0;
        swap(a[j], a[mxi]);
        for (int i = 1; i <= n; i++) {
            if (i == j) continue;
            int x = a[i][j] * fap(a[j][j], mod - 2) % mod;
            for (int k = j; k <= 2 * n; k++) {
                a[i][k] -= x * a[j][k] % mod;
                ((a[i][k] %= mod) += mod) %= mod;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= 2 * n; j++) {
            (a[i][j] *= fap(a[i][i], mod - 2)) %= mod;
        }
    }
    return 1;        
}
```

## 线性基
```cpp
struct LinearBasis {
    int LOG;                       
    vector<int> a;                  
    LinearBasis(int LOG_=61): LOG(LOG_), a(LOG, 0) {}
    void insert(int x){
        for (int i = LOG-1; i >= 0; i--){
            if (((x >> i) & 1LL) == 0) continue;
            if (a[i] == 0) { a[i] = x; return; }
            x ^= a[i];
        }
    }
};
```

## 前缀线性基
```cpp
struct Basis {
    int LOG;
    vector<int> vec; // 每一位的基向量
    vector<int> pos;       // 该向量的来源 tin

    Basis(int LOG_=61): LOG(LOG_), vec(LOG, 0), pos(LOG, 0) {}

    void insert(int x, int id){
        for(int i = LOG-1; i >= 0; --i){
            if(((x >> i) & 1LL) == 0) continue;
            if(vec[i] == 0){
                vec[i] = x; pos[i] = id;
                return;
            }
            if(pos[i] < id){ // 更靠后的来源占位
                swap(vec[i], x);
                swap(pos[i], id);
            }
            x ^= vec[i];
        }
    }
    int query_max(int L) const{
        int res = 0;
        for(int i = LOG-1; i >= 0; --i){
            if(pos[i] >= L && (res ^ vec[i]) > res)
                res ^= vec[i];
        }
        return res;
    }
};
```
# my计算几何
```cpp
const double eps = 1e-8;        // 精度要求
const double PI  = acos(-1.0);  // 圆周率
const double inf = 1e18;        // 无穷大

int sgn(double x) { return x < -eps ? -1 : (x > eps ? 1 : 0); }

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // 向量运算
    Point operator-(const Point &B) const { return Point(x - B.x, y - B.y); }
    Point operator+(const Point &B) const { return Point(x + B.x, y + B.y); }
    double operator^(const Point &B) const { return x * B.y - y * B.x; } // 叉积
    double operator*(const Point &B) const { return x * B.x + y * B.y; } // 点积
    Point operator*(const double &B) const { return Point(x * B, y * B); }
    Point operator/(const double &B) const { return Point(x / B, y / B); }

    // 排序比较
    bool operator<(const Point &B) const { return x < B.x || (x == B.x && y < B.y); }
    bool operator==(const Point &B) const { return sgn(x - B.x) == 0 && sgn(y - B.y) == 0; }
    bool operator!=(const Point &B) const { return sgn(x - B.x) || sgn(y - B.y); }
};

using Vector = Point;

double len(Vector A) { return sqrt(A * A); }

double Angle(Vector A, Vector B) {
    double t = (A * B) / len(A) / len(B);
    // 数值安全
    if (t < -1) t = -1;
    if (t >  1) t =  1;
    return acos(t); // 弧度 [0, π]
}

double Cross(Point a, Point b, Point c) { return (b - a) ^ (c - a); }

vector<Point> Andrew(vector<Point> p) {
    int n = (int)p.size();
    sort(p.begin(), p.end());
    vector<Point> h;
    // 下凸包
    for (int i = 0; i < n; ++i) {
        while ((int)h.size() > 1 && Cross(h[h.size()-2], h.back(), p[i]) <= 0) h.pop_back();
        h.push_back(p[i]);
    }
    int t = (int)h.size();
    // 上凸包
    for (int i = n - 2; i >= 0; --i) {
        while ((int)h.size() > t && Cross(h[h.size()-2], h.back(), p[i]) <= 0) h.pop_back();
        h.push_back(p[i]);
    }
    if (!h.empty()) h.pop_back(); // 去掉与首点重复的末点
    return h;
}
```

# 数论基础
## 素数
### 素数分布
记 $π(x)$ 为 $[1,x]$ 中质数的个数（素数计数函数），可以认为 $π(x)≈xlnx$
### 素数间隔
在 $[1,10^{18}]$ 的范围内，相邻两个质数的差在 $1500$ 以内。根据这个性质，一些有关质数的构造题可以直接暴力枚举解决
### Miller_rabin
```cpp
bool Miller_rabin (int p) {
    static int pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    if (p < 40) {
        for (int a : pr) if (a == p) return 1;
        return 0; 
    }
    int u = p - 1, power = 0;
    while (!(u & 1)) u >>= 1, power++;
    for (int a : pr) {
        int x = fap(a, u, p), y;
        for (int i = 1; i <= power; i++, x = y) {
            if ((y = mul(x, x, p)) == 1 && x != 1 && x != p - 1) return 0;
        }
        if (x != 1) return 0;
    }
    return 1; 
}
```
## 筛法
### 线性筛
```cpp
phi[1] = 1;
mu[1] = 1;
for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr.push_back(i), mu[i] = -1, phi[i] = -1;
    for (int j : pr) {
        int m = i * j;
        if (m > n) break;
        vis[m] = 1;
        if (i % j == 0) {
            phi[m] = j * phi[i];
            mu[m] = 0;
            break;
        }
        else {
            phi[m] = (j - 1) * phi[i];
            mu[m] = -mu[i];
        }
    }
}
```
### 线性筛求约数个数
约数个数定理

若 $n = \prod_{i=1}^{s} p_i^{\alpha_i}$，则 $d(n) = \prod_{i=1}^{s} (\alpha_i + 1)$。

证明：$p_i^{\alpha_i}$ 的约数有 $p_i^0, p_i^1, \ldots, p_i^{\alpha_i}$ 共 $\alpha_i + 1$ 个，
根据乘法原理，$d(n) = \prod_{i=1}^{s} (\alpha_i + 1)$。

筛法求约数个数
$a[i]$ 记录 $i$ 的最小质因子的次数
$d[i]$ 记录 $i$ 的约数个数
若 $i$ 是质数，$a[i] = 1, d[i] = 2$。

在线性筛中，每个合数 $m$ 都是被最小的质因子筛掉的。
设 $p_j$ 是 $m$ 的最小质因子，则 $m$ 通过 $m = p_j \times i$ 筛掉。

(1) 若 $i$ 能被 $p_j$ 整除，则 $p_j$ 一定是 $i$ 的最小质因子。
$a[m] = a[i] + 1;$
$d[i] = (a[i] + 1) \times \cdots, d[m] = (a[m] + 1) \times \cdots$

(2) 若 $i$ 不能被 $p_j$ 整除，则 $i$ 不包含质因子 $p_j$。
$a[m] = 1, d[m] = d[i] \times (1 + 1)$
```cpp
int a[N]; // a[i]记录i的最小质因子的次数
int d[N]; // d[i]记录i的约数个数

void get_d(int n) { // 筛法求约数个数
    d[1] = 1;
    for(int i=2; i<=n; i++) {
        if(!vis[i]) {
            pr[++cnt] = i;
            a[i] = 1; d[i] = 2;
        }
        for(int j = 1; i * pr[j] <= n; j++) {
            int m = i * pr[j];
            vis[m] = 1;
            if (i % pr[j] == 0) {
                a[m] = a[i] + 1;
                d[m] = d[i] / a[m] * (a[m] + 1);
                break;
            } 
            else {
                a[m] = 1; d[m] = d[i] * 2;
            }
        }
    }
}
```
### 线性筛求约数和
问题：

给定一个数 $n$ ($n \leq 1 \times 10^6$)，输出 $1 \sim n$ 每个数的约数和。

约数和定理

若 $n = \prod_{i=1}^{s} p_i^{\alpha_i}$，则 $f(n) = \prod_{i=1}^{s} \sum_{j=0}^{\alpha_i} p_i^j$

证明：$p_i^{\alpha_i}$ 的约数有 $p_i^0, p_i^1, \ldots, p_i^{\alpha_i}$ 共 $\alpha_i + 1$ 个，

其约数和为 $\sum_{j=0}^{\alpha_i} p_i^j$,

根据乘法原理，$f(n) = \prod_{i=1}^{s} \sum_{j=0}^{\alpha_i} p_i^j$

例：$12 = 2^2 \times 3^1$,

$f(12) = \{1 + 2 + 4\} \times \{1 + 3\} = 7 \times 4 = 28$

线性筛求约数和

$g[i]$ 表示 $i$ 的最小质因子的 $1+p^1+...+p^k$

$f[i]$表示 $i$的约数和

若 $i$ 是质数，$g[i] = f[i] = i + 1$.

在线性筛中，每个合数 $m$ 都是被最小的质因子筛掉的。

设 $p_j$ 是 $m$ 的最小质因子，则 $m$ 通过 $m = i \times p_j$ 筛掉。

(1) 若 $i$ 能被 $p_j$ 整除，则 $p_j$ 一定是 $i$ 的最小质因子

$g[i] = p_j^0 + p_j^1 + \cdots + p_j^{\alpha_j}, \quad g[m] = p_j^0 + p_j^1 + \cdots + p_j^{\alpha_j+1}$

$f[i] = g[i] \times \cdots, \quad f[m] = g[m] \times \cdots$

(2) 若 $i$ 不能被 $p_j$ 整除，则 $i$ 不包含质因子 $p_j$。

$g[m] = 1 + p_j$

$f[m] = g[m] \times f[i]$

```cpp
int pr[N], vis[N], cnt;
// g[i] 表示 i 的最小质因子的 1+p^1+...+p^k
int g[N], f[N]; // f[i] 表示 i 的约数和

void get_f(int n) { // 线性筛约数和
    g[1] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            pr[++cnt] = i;
            g[i] = f[i] = i + 1;
        }
        for (int j = 1; j * pr[j] <= n; j++) {
            int m = i * pr[j];
            vis[m] = 1;
            if (i % pr[j] == 0) {
                g[m] = g[i] * pr[j] + 1;
                f[m] = f[i] / g[i] * g[m];
                break;
            } else {
                g[m] = pr[j] + 1;
                f[m] = f[i] * g[m];
            }
        }
    }
}

```

## 裴蜀定理
+ 定理内容:设 $a,b$ 是不全为零的整数，对任意整数 $x,y$，满足 $gcd(a,b) | ax+by$，且存在整数 $x,y$, 使得 $ax+by=gcd(a,b)$.
+ 逆定理: 
  + 若$a,b$的一个公因数为$d$,且存在整数$x,y$,使得$ax+by=d$,则$gcd(a,b)=d$.
  + 特别的,若存在整数$x,y$,使得$ax+by=1$,则$gcd(a,b)=1$;
+ 裴蜀定理可以推广到 $n$ 个整数的情形：设 $a_1, a_2, \dots , a_n$ 是不全为零的整数，则存在整数 $x_1, x_2, \dots, x_n$ , 使得 $a_1 x_1 + a_2 x_2 + \cdots + a_n x_n=\gcd(a_1, a_2, \dots, a_n)$。其逆定理也成立：设 $a_1, a_2, \dots, a_n$ 是不全为零的整数，$d > 0$ 是 $a_1, a_2, \dots, a_n$ 的公因数，若存在整数 $x_1, x_2, \dots, x_n$, 使得 $a_1 x_1 + a_2 x_2 + \cdots + a_n x_n=d$ 则 $d = \gcd(a_1, a_2, \dots, a_n)$。
1. [P4549 【模板】裴蜀定理](https://www.luogu.com.cn/problem/P4549) 
题干:给定一个包含 $n$ 个元素的整数序列 $A$，记作 $A1,A2,A3,...,An​$
求另一个包含 $n$ 个元素的待定整数序列 $X$，记 $S=∑Ai×Xi$​，使得 $S>0$ 且 $S$ 尽可能的小。
题解: 负数$*-1$;再求$n$个数的 $gcd$;
2. [Fox And Jumping ](https://www.luogu.com.cn/problem/CF510D)
题干:给出 $n$ 张卡片，分别有 $l[i]$ 和 $c[i]$​。在一条无限长的纸带上，你可以选择花 $c[i]$​ 的钱来购买卡片 $i$，
从此以后可以向左或向右跳 $l[i]$ 个单位。问你至少花多少元钱才能够跳到纸带上全部位置。若不行，输出 −1。
题解: 
使购买的卡片的gcd=1的最小花费.
用map维护
```cpp
for(int i = 1; i <= n; i++) {
    for(auto it = mp.begin(); it != mp.end(); it++) {
        int res = gcd(it->first, l[i]);
        if(mp[res]) {
            mp[res] = min(mp[res], mp[it->first] + c[i]);
        }
        else{
            mp[res] = mp[it->first]+ c[i];
        }
    }
}
```



## 费马小定理
1. 定义
若 $p$ 为素数， $\gcd(a, p) = 1$ ，则 $a^{p - 1} \equiv 1 \pmod{p}$ 。
另一个形式：对于任意整数 $a$ ，有 $a^p \equiv a \pmod{p}$ .
2. 若$p$为素数,求$a$在%$p$下的逆元 即$a^{p - 2}$
## 欧拉定理
$\gcd(a, m) = 1$ ，则 $a^{\varphi(m)} \equiv 1 \pmod{m}$ 

### 扩展欧拉定理：
不要求 $\gcd(a, m) = 1$ 
$$ a^b \equiv \begin{cases} 
a^b, & b < \varphi(m), \\
a^{b \mod \varphi(m) + \varphi(m)}, & b \geq \varphi(m),
\end{cases} \pmod{m} $$
## 威尔逊定理
$(p - 1)! \equiv -1 \pmod{p}$ 是 $p$ 为质数的充分必要条件。
### [hdu2973 YAPTCHA](https://acm.hdu.edu.cn/showproblem.php?pid=2973)
给定 $n \leq 10^6$，求 $S_n$。

$$
S_n = \sum_{k=1}^{n} \left\lfloor \frac{(3k+6)! + 1}{3k+7} \right\rfloor - \left\lfloor \frac{(3k+6)!}{3k+7} \right\rfloor 
$$

**解**

令 $p = 3k + 7$，则求和项变为：

$$
\left(\frac{(p-1)!+1}{p} - \left\lfloor \frac{(p-1)!}{p} \right\rfloor \right)
$$

若 $p$ 是质数，例 $13, 19, 31 \ldots$

则 $\frac{(p-1)!+1}{p}$ 是整数，

$$
\left\lfloor \frac{(p-1)!}{p} \right\rfloor 必然比 \frac{(p-1)!+1}{p} 小 1，
$$
则
$$
\left(\frac{(p-1)!+1}{p} - \left\lfloor \frac{(p-1)!}{p} \right\rfloor \right) = 1
$$

若 $p$ 是合数，例 $10, 16, 22 \ldots$

则 $\frac{(p-1)!}{p}$ 是整数，

则
$$
\left(\frac{(p-1)!+1}{p} - \left\lfloor \frac{(p-1)!}{p} \right\rfloor \right) = 0
$$

先筛出 $[1,3000007]$ 中形如 $3k + 7$ 的质数，再统计 $[1,n]$ 内合法质数的个数即可。


## 线性求逆元
```cpp
inv[1] = 1;
for (int i = 2; i <= n; i++) {
  inv[i] = (long long)(p - p / i) * inv[p % i] % p;
}
```

## 拓展欧几里得算法
$ax + by = gcd(a,b)$ 的一组解.
```cpp
void exgcd(int a,int b,int &x, int &y) {
    if (b==0) {x=1; y=0;}
    else exgcd(b, a % b, y, x), y -= a / b * x;
}
```
用拓展欧几里得求逆元
$ax \equiv 1 \pmod{p}$
需 $\gcd(a, p) = 1$
```cpp
int x, y;
exgcd(a, p, x, y);
x = (x % p + p) % p;
```
### 线性丢番图方程
线性丢番图方程是 $a_i,c$ 均为整数且形如
$$ a_1x_1 + a_2x_2 + ⋯ + a_nx_n=c $$
它有解当且仅当 $gcd(a_1,a_2,⋯,a_n)∣c$

**如何求出一组特解**
$$
d2=gcd(a1,a2)\\
d3=gcd(a1,a2,a3)=gcd(d2,a3)\\
⋯\\
dn=gcd(a1,a2,⋯,an)=gcd(dn−1,an)
$$
判断是否有解，若 $d_n∣c$，则有解，否则无解
如果有解，就把方程拆成 $n−1$个二元的线性方程
$$
a_1x_1+a_2x_2  = d_2t_2\\
d_2t_2+a_3x_3=d_3t_3\\
⋯\\
d_{n−1}t_{n−1}+a_nx_n=c
$$
然后从最后一个方程开始，用扩展欧几里得求解，得到 $t_{n−1},x_n$
，再代入前面的方程求解，得到 $t_{n−2},x_{n−1}$
，以此类推，得到 $x_1$

例如 $2x+3y+5z=7$，先求出 $gcd(2,3,5)=1$，有解，然后
$2x+3y=t$
$t+5z=7$
求解第二个方程得到 $t=7,z=0$,再代入第一个方程得到 $2x+3y=7$,求解得到 $x=−7,y=7$,方程的一组特解就是 $(−7,7,0)$

## CRT(中国剩余定理)
中国剩余定理 (Chinese Remainder Theorem, CRT) 可求解如下形式的一元线性同余方程组（其中 $b_1, b_2, \cdots, b_k$ 两两互质）：
$\begin{cases} x &\equiv a_1 \pmod {b_1} \\ x &\equiv a_2 \pmod {b_2} \\ &\vdots \\ x &\equiv a_k \pmod {b_k} \\ \end{cases}$
第一步 : 求$M=b_1*b_2,\cdots,*b_k$
第二步 : 求 $c_i=M/b_i$
第三步 : 求 $c_i^{-1} \pmod{b_i}$
答案即为 方程组在模 $M$ 意义下的唯一解为：$x=\sum_{i=1}^k a_ic_ic_i^{-1} \pmod M$

证明：易得$\\
c_ic_i^{-1} \equiv 1 \pmod {b_i} \\
c_ic_i^{-1} \equiv 0 \pmod {b_j} (i \ne j)$
```cpp
int CRT(int n, int* a, int* b) {
    int mul = 1, ans = 0;
    for (int i = 1; i <= n; i++) mul = mul * b[i];
    for (int i = 1; i <= n; i++) {
        int m = mul / b[i], x, y;
        exgcd(m, b[i], x, y);
        ans = (ans + a[i] * m * x % mul) % n;
    }
  return (ans % mul + mul) % mul;
}
```
### excrt
$b_1,b_2,\cdots,b_n$ 不两两互质
$$
x \equiv a_i \pmod {b_i}\\
x \equiv a_j \pmod {b_j}\\
$$
可得 
$$
x = pb_i + a_i = -qb_j + a_j (1)
$$
所以移项得
$$
pb_i+qb_j = a_j-a_i
$$

如果 $gcd(b_i,b_j)|a_j-a_i$ 则有解
可用 $exgcd$ 求出 $p$ 的一个特解
通解 $P = p+kb_j/gcd(b_i,b_j)$ 
将 $P$ 带入 $(1)$ 得
$$
x \equiv pb_i+a_i \pmod {lcm(b[i],b[j])}
$$

[提交记录](https://www.luogu.com.cn/record/205653250)
```cpp
int excrt (int n, int *a, int *b) {
    for (int i = 1; i < n; i++) {
        int j = i + 1;
        int d = gcd(b[i], b[j]);
        if ((a[j] - a[i]) % d) return -1;
        int p, q;
        exgcd(b[i], b[j], p, q);
        p = p * (a[j] - a[i]) / d;
        int mo = b[j] / d;
        p = (p % mo + mo) % mo;
        b[j] = lcm(b[i], b[j]);
        a[j] = (p * b[i] + a[i]) % b[j];    
    }
    return (a[n] % b[n] + b[n]) % b[n];
}
```

## 分解质因数
### 朴素做法

```cpp
for (int i = 2; i * i <= n; i++)
    while (n % i == 0) a.push_back(i), n /= i;
if (n != 1) a.push_back(n);
```
### Pollard_Rho
[提交记录](https://www.luogu.com.cn/record/201666707)
```cpp
#include <bits/stdc++.h>

using namespace std;

namespace xbbbz {
    #define int long long

    int fap (__int128 a, int b, int p) {
        __int128 res = 1;
        while(b) {
            if(b & 1) res = res * a % p;
            a = a * a % p; b /= 2;
        }
        return res;
    }

    int mul (int x, int y, int p) {
        return (__int128) x * y % p; 
    }

    int gcd (int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    bool Miller_rabin (int p) {
        static int pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        if (p < 40) {
            for (int a : pr) if (a == p) return 1;
            return 0; 
        }
        int u = p - 1, power = 0;
        while (!(u & 1)) u >>= 1, power++;
        for (int a : pr) {
            int x = fap(a, u, p), y;
            for (int i = 1; i <= power; i++, x = y) {
                if ((y = mul(x, x, p)) == 1 && x != 1 && x != p - 1) return 0;
            }
            if (x != 1) return 0;
        }
        return 1; 
    }

    int Pollard_Rho (int n) {
        static mt19937_64 gen((random_device())());
        uniform_int_distribution <int> ds(1, n - 1);
        int c = ds(gen);
        auto f = [&] (int x) {return  ((__int128)x * x + c) % n; };
        int x = 0, y = 0, res = 1;
        for(int k = 1; ; k <<= 1, y = x, res = 1) {
            for(int i = 1; i <= k; i++) {
                x = f(x);   
                res = (__int128) abs(x - y) * res % n;
                if(i % 127 == 0) {
                    int d = gcd(res, n);
                    if (d > 1) return d;
                }   
            }
            int d = gcd(res, n);
            if (d > 1) return d;
        }
    }

    vector<int> factor;
    void get_factor (int n) {
        if (n == 1) return;
        if (Miller_rabin(n)) {
            factor.push_back(n);
            return;
        }
        int x = n;
        while (x == n) x = Pollard_Rho(n);
        get_factor(x), get_factor(n / x); 
    }

    void sol() {
        int n;
        cin >> n;
        factor.clear();
        get_factor(n);
        int ans = 0;
        for (int x : factor) ans = max(ans, x);
        if (ans == n) cout << "Prime\n";
        else cout << ans <<"\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }

    #undef int
}

int main() {
    return xbbbz::main(), 0;
}
```
## 欧拉函数


欧拉函数的性质  
1. 若 $p$ 是质数, 则 $\varphi(p)=p-1$
2. 若 $p$ 是质数, 则 $\varphi(p^k)=(p-1)p^{k-1}$
3. 积性函数: 若 $gcd(m,n)=1$, 则 $\varphi(mn)=\varphi(m)\varphi(n)$  

欧拉函数的计算公式  
由唯一分解定理 
$n=\prod_{i=1}^{s}p_i^{\alpha_i}=p_1^{\alpha_1}p_2^{\alpha_2}\cdots p_s^{\alpha_s}$,
    $\varphi(n)=\prod_{i=1}^{s}\varphi(p_i^{\alpha_i})$
    $=\prod_{i=1}^{s}p_i^{\alpha_i-1}(p_i-1)$
    $=\prod_{i=1}^{s}p_i^{\alpha_i}\left(1-\frac{1}{p_i}\right)$
    $=\prod_{i=1}^{s}p_i^{\alpha_i}\times \prod_{i=1}^{s}\left(1-\frac{1}{p_i}\right)$
    $=n\times \prod_{i=1}^{s}\frac{p_i-1}{p_i}$
    $=n\times \frac{p_1-1}{p_1}\times \frac{p_2-1}{p_2}\times \cdots \times \frac{p_s-1}{p_s}$
### 试除法求欧拉函数
```cpp
int phi(int n){ 
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) res = res / n * ( n - 1);
    return res;
}
```
## BSGS
求解高次同余方程  
给定整数 a, b, p. a, p 互质，
求满足 $a^x \equiv b \pmod{p}$ 的最小非负整数 x。


由欧拉定理 $a^x \equiv a^{x \bmod \varphi(p)} \pmod{p}$
可知 $a^x$ 模 $p$ 意义下的最小循环节为 $\varphi(p)$,
因 $\varphi(p) < p$, 故考虑 $x \in [0,p]$，必能找到最小整数 $x$。

如果暴力枚举，时间是 O(p) 的。

令 $x = im - j$，其中 $m = \lceil {\sqrt{p}} \rceil$，$i \in [1,m]$，$j \in [0,m - 1]$
则 $a^{im-j} \equiv b \pmod{p}$,
即 $(a^m)^i \equiv ba^j \pmod{p}$.

先枚举 j，把 $(ba^j,j)$ 去入哈希表，如果 key 重复，用更大的 j 替代旧的
再枚举 i，计算 $(a^m)^i$，到哈希表中查找是否有相等的 key，找到第一个即结束。则最小的 $x = im - j$

枚举 j,i 的次数都是 $\sqrt{p}$ 的，所以时间是 $O(\sqrt{p})$ 的。

```cpp
LL bsgs(LL a, LL b, LL p) {
    a %= p; b %= p;
    if(b == 1) return 0; 
    LL m = ceil(sqrt(p));
    LL t = b;
    unordered_map<int,int> hash;
    hash[b] = 0;

    for(int j = 1; j < m; j++) {
        t = t * a % p; 
        hash[t] = j;
    }

    LL mi = 1;
    for(int i = 1; i <= m; i++)
        mi = mi * a % p; 

    t = 1;
    for(int i = 1; i <= m; i++) {
        t = t * mi % p;
        if(hash.count(t))
            return i * m - hash[t]; 
    }

    return -1; 
}

```
## 扩展 BSGS 算法

高次同余方程求解

给定整数 $a$, $b$, $p$，求满足 $a^x \equiv b \pmod{p}$ 的最小非负整数 $x$。

当 $a$ 和 $p$ 互质时，可以使用 BSGS 算法求解。

当 $a$ 和 $p$ 不互质时，要想法让他们变得互质。

原方程等价于 $a \cdot a^{x-1} \equiv b \pmod{p}$。

设 $d_1 = \gcd(a, p)$。如果 $d_1 \nmid b$，则原方程无解。

否则方程两边同时除以 $d_1$，得 $\frac{a}{d_1} \cdot a^{x-1} \equiv \frac{b}{d_1} \pmod{\frac{p}{d_1}}$。

如果 $a$ 和 $\frac{p}{d_1}$ 仍不互质就再除，

设 $d_2 = \gcd(a, \frac{p}{d_1})$。如果 $d_2 \nmid \frac{b}{d_1}$，则原方程无解。

否则方程两边同时除以 $d_2$，得 $\frac{a}{d_1d_2} \cdot a^{x-2} \equiv \frac{b}{d_1d_2} \pmod{\frac{p}{d_1d_2}}$。

不停的判断下去，直到 $a$ 与 $\frac{p}{d_1 \cdot d_2 \cdots d_k}$ 互质，记 $D = d_1 \cdot d_2 \cdots d_k$，此时可以应用 BSGS 算法求解。

```cpp
LL exbsgs(LL a, LL b, LL p) {
    a %= p; b %= p;
    if (b == 1 || p == 1) return 0; // x = 0
    LL d, k = 0, A = 1;
    while (true) {
        d = gcd(a, p);
        if(d == 1) break;
        if(b % d) return -1; // 无解
        k++; b /= d; p /= d;
        A = A * (a / d) % p; // 求 a^k/D
        if (A == b) return k;
    }
    LL m = ceil(sqrt(p));
    LL t = b;
    unordered_map<int, int> hash;
    hash[b] = 0;
    for(int j = 1; j < m; j++) {
        t = t * a % p; // 求 b*a^j
        hash[t] = j;
    }
    LL mi = 1;
    for(int i = 1; i <= m; i++) {
        mi = mi * a % p; // 求 a^m
    }
    t = A;
    for(int i = 1; i <= m; i++) {
        t = t * mi % p; // 求 (a^m)^i
        if(hash.count(t))
            return i * m - hash[t] + k;
    }
    return -1; // 无解
}
```

## 整除分块
求 $(\sum_{i=1}^{n} f(i) \left\lfloor \frac{n}{i} \right\rfloor)$

先预处理出 $f(i)$ 的前缀和 $s(i) = \sum_{j=1}^{i} f(j)$，再枚举每一块 $[l, r]$，累加每块的贡献。

```cpp
for(int l = 1; l <= n; l = r + 1) {
    r = n / (n / l);
    res += (s(r) - s(l - 1)) * (n / l);
}
```

时间复杂度: $O(\sqrt{n})$

## 狄利克雷卷积
$$(f * g)(n) = \sum_{d|n} f(d)g\left(\frac{n}{d}\right) = \sum_{d|n} f\left(\frac{n}{d}\right)g(d)$$

交换律：$f * g = g * f$
结合律：$(f * g) * h = f * (g * h)$
分配律：$(f + g) * h = (f * h) + (g * h)$

## 莫比乌斯反演
$$
f(n) = \sum_{d|n} g(d) \iff g(n) = \sum_{d|n} \mu(d) f\left(\frac{n}{d}\right) \\
1 * f   = g \iff \mu * g  = f
$$
其中 $f(n)$ 和 $g(n)$ 是积性函数
$f(n)$ 称为 $g(n)$ 的莫比乌斯变换。
$g(n)$ 称为 $f(n)$ 的莫比乌斯逆变换。

常见卷积

$$
1 * \varepsilon  = 1 \iff \mu * 1 = \varepsilon \\
1 *\varphi  = id \iff \mu * id = \varphi \\
1 * id = \sigma \iff \mu * \sigma = id
$$


求 $g = \mu * f$ 
复杂度 O(nloglogn)
```cpp
vector <int> get_g (vector<int> &f) {
    vector<int> g = f;
    for (auto p : pr) {
        for (int i = n / p; i >= 1; i--) {
            g[i * p] = (g[i * p] - g[i] + mod) % mod;
        }
    }
    return g;
} 
```

## 杜教筛

$f, g$, $S(n) = \sum_{i=1}^n f(i)$

$$
g(1)S(n) = \sum_{i=1}^n (f * g)(i) - \sum_{i=2}^n g(i)S\left(\left\lfloor \frac{n}{i} \right\rfloor\right)
$$
求 $S(n) = \sum_{i=1}^n \mu(i)$
求 $S(n) = \sum_{i=1}^n \varphi(i)$
$O(n ^ \frac{2}{3})$
```cpp
#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    const int N = 2e6 + 10;
    int cnt, vis[N], pr[N], mu[N], phi[N], smu[N], sphi[N];
    map<int, int> mpsmu, mpsphi;
    void init(int n) {
        mu[1] = 1;
        phi[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) {
                pr[++cnt] = i;
                mu[i] = -1;
                phi[i] = i - 1;
            }
            for (int j = 1; j <= cnt && i * pr[j] <= n; j++) {
                int m = i * pr[j];
                vis[m] = 1;
                if (i % pr[j] == 0) {
                    phi[m] = phi[i] * pr[j];
                    break;
                }
                mu[m] = -mu[i];
                phi[m] = phi[i] * (pr[j] - 1);
            }
        }
        for (int i = 1; i <= n; i++) {
            smu[i] = smu[i - 1] + mu[i];
            sphi[i] = sphi[i - 1] + phi[i];
        }
    }
    int get_smu(int n) {
        if (n <= N - 10) return smu[n];
        if (mpsmu.find(n) != mpsmu.end()) return mpsmu[n];
        int ans = 1;
        for (int l = 2, r; l <= n; l = r + 1) {
            r = n / (n / l);
            ans -= (r - l + 1) * get_smu(n / l);
        }
        return mpsmu[n] = ans;
    }
    int get_sphi(int n) {
        if (n <= N - 10) return sphi[n];
        if (mpsphi.find(n) != mpsphi.end()) return mpsphi[n];
        int ans = n * (n + 1) / 2;
        for (int l = 2, r; l <= n; l = r + 1) {
            r = n / (n / l);
            ans -= (r - l + 1) * get_sphi(n / l);
        }
        return mpsphi[n] = ans;
    }
    void sol() {
        int n;
        cin >> n;
        cout << get_sphi(n) << " " << get_smu(n) << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        init(N - 10);
        // cout << sphi[2] << " " << smu[1] << "\n";
        while (T--) sol();
    }
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}
```
## 基于值域预处理的快速GCD
```cpp
vector<int> pr, vis;
vector<array<int, 3>> fac;
vector<vector<int>> pre;
void init() {
    int n = 1e6;
    vis.assign(n + 5, 0);
    fac.assign(n + 5, {0, 0, 0});
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            pr.push_back(i);
            fac[i][0] = fac[i][1] = 1;
            fac[i][2] = i;
        }
        for (int j : pr) {
            if (i * j > n) break;
            int m = i * j;
            vis[m] = 1;
            fac[m] = fac[i];
            fac[m][0] *= j;
            if (fac[m][0] > fac[m][1]) fac[m][0] ^= fac[m][1] ^= fac[m][0] ^= fac[m][1]; 
            if (fac[m][1] > fac[m][2]) fac[m][1] ^= fac[m][2] ^= fac[m][1] ^= fac[m][2];
            if (i % j == 0) break; 
        }
    }
    fac[1] = {1, 1, 1};
    int m = 1e3;
    pre.assign(m + 5, vector<int>(m + 5, 0));
    for (int i = 0; i <= m; i++) pre[i][0] = pre[0][i] = i;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= i; j++) {
            pre[i][j] = pre[j][i] = pre[j][i % j];
        }
    }
}

int gcd(int a, int b) {
    int ans = 1;
    for (int i = 0; i < 3; i++) {
        int x = fac[a][i], tmp = 1;
        if (vis[x]) tmp = pre[x][b % x];
        else if (b % x == 0) tmp = x;
        ans *= tmp;
        b /= tmp;
    }
    return ans;
}
```
