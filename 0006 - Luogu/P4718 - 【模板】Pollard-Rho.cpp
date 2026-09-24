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