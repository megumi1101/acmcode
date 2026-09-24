#include <bits/stdc++.h>

using namespace std;

#define int long long

int mul(int a, int b, int mod) {
    return (__int128)a * b % mod;
}

int fap(int a, int b, int mod) {
    a %= mod;
    if (a < 0) a += mod;

    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return res;
}

bool Miller_rabin(int p) {
    static int pr[] = {
        2, 3, 5, 7, 11, 13,
        17, 19, 23, 29, 31, 37
    };

    if (p < 40) {
        for (int a : pr) {
            if (a == p) return true;
        }
        return false;
    }

    int u = p - 1, power = 0;
    while (!(u & 1)) {
        u >>= 1;
        power++;
    }

    for (int a : pr) {
        int x = fap(a, u, p), y = 0;
        for (int i = 1; i <= power; i++, x = y) {
            y = mul(x, x, p);
            if (y == 1 && x != 1 && x != p - 1) {
                return false;
            }
        }
        if (x != 1) return false;
    }

    return true;
}

int mod, w;

struct C {
    int x, y;
};

C operator * (const C &a, const C &b) {
    return {
        (mul(a.x, b.x, mod) + mul(mul(a.y, b.y, mod), w, mod)) % mod,
        (mul(a.x, b.y, mod) + mul(a.y, b.x, mod)) % mod
    };
}

C fap(C a, int b) {
    C res{1, 0};
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int Cipolla(int n, int p) {
    n %= p;
    if (n < 0) n += p;

    if (n == 0 || p == 2) return n;
    if (fap(n, (p - 1) / 2, p) != 1) {
        return -1;
    }
    mod = p;
    int a = 0;
    while (true) {
        w = (mul(a, a, p) - n + p) % p;
        if (fap(w, (p - 1) / 2, p) == p - 1) {
            break;
        }
        a++;
    }

    return fap(C{a, 1}, (p + 1) / 2).x;
}

mt19937_64 rng(random_device{}());
void sol() {
    int p;
    cin >> p;

    
    vector<int> pp{1, 9, 25, 49, 121, 169, 289};
    for (int i = 1; i <= 100000; i+=2) {
        for (auto ii : pp) {
            int q = ii + i * 4 * p;
            if (!Miller_rabin(q)) continue;
            int x1 = Cipolla(p % q, q);
            if (x1 != -1 && mul(x1, x1, q) == p % q) {
                cout << x1 % q << ' ';
                cout << (int)sqrt(ii) % p << ' ';
                cout << q << '\n';
                return;
            }
        }
        
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}