#include <bits/stdc++.h>

using namespace std;

namespace xbbbz {
    #define int long long
    const int mod = 998244353;

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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int t = gcd(a, c);
        int res1 = gcd(t, a / t);
        int res2 = gcd(t, c / t);
        factor.clear();
        get_factor(res1);
        get_factor(res2);
        sort(factor.begin(), factor.end());
        factor.erase(unique(factor.begin(), factor.end()), factor.end());
        for (auto x : factor) {
            while (t % x == 0) t /= x;
        }
        int ans = fap(t, min(b, d), mod) % mod;
        for (auto x : factor) {
            __int128 cnt1 = 0,  cnt2 = 0;
            while (a % x == 0) a /= x, cnt1++;
            while (c % x == 0) c /= x, cnt2++;
            cnt1 *= (__int128) b;
            cnt2 *= (__int128) d;
            int y = min(cnt1, cnt2) % (mod - 1);
            ans *= fap(x, y, mod) % mod;
            ans %= mod;
        }
        cout << ans << "\n";
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
/*
 5
 2 3 3 2
 4 2 8 1
 6 2 9 1
 7 1 11 1
 10000000000000 1 10000000000000 1
*/