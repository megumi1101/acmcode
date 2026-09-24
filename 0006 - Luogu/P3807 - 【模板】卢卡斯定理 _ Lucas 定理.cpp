#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {
#define int long long

    // 快速幂
    static inline long long qpow(long long a, long long e, long long mod){
        long long r = 1 % mod;
        while(e){
            if(e & 1) r = (__int128)r * a % mod;
            a = (__int128)a * a % mod;
            e >>= 1;
        }
        return r;
    }

    // 预处理 factorial / invfactorial（大小 p ）
    // 注意：只有当 p 不是非常大时（几百万量级）才可行。
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

    void sol() {
        int n, m, p;
        cin >> n >> m >> p;
        Lucas luc (p);
        cout << luc.C(n + m, m) << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
} // namespace Xbbbz

int main() {
    return Xbbbz :: main(), 0;
}

