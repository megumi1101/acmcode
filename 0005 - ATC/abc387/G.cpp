#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;
namespace FPS {
constexpr int P = 998244353;
constexpr int G = 3;

int norm(int x) { x %= P; return x < 0 ? x + P : x; }

int power(int a, int e) {
    int r = 1;
    a = norm(a);
    while (e) {
        if (e & 1) r = r * a % P;
        a = a * a % P; e >>= 1;
    }
    return r;
}

static vector<int> rev;
static vector<int> roots{0, 1};

void dft(vector<int> &a) {
    int n = (int)a.size();
    if (n <= 1) return;
    assert((n & (n - 1)) == 0);
    assert(n <= (1LL << 23));

    if ((int)rev.size() != n) {
        int k = __builtin_ctzll(n) - 1;
        rev.assign(n, 0);
        for (int i = 0; i < n; i++)
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << k);
    }
    for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);

    if ((int)roots.size() < n) {
        int k = __builtin_ctzll((int)roots.size());
        roots.resize(n);
        while ((1LL << k) < n) {
            int e = power(G, (P - 1) >> (k + 1));
            for (int i = (1LL << (k - 1)); i < (1LL << k); i++) {
                roots[i << 1] = roots[i];
                roots[i << 1 | 1] = roots[i] * e % P;
            }
            k++;
        }
    }

    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; j++) {
                int u = a[i + j], v = a[i + j + k] * roots[k + j] % P;
                int x = u + v;
                if (x >= P) x -= P;
                a[i + j] = x;
                x = u - v;
                if (x < 0) x += P;
                a[i + j + k] = x;
            }
        }
    }
}

void idft(vector<int> &a) {
    int n = (int)a.size();
    if (n <= 1) return;
    reverse(a.begin() + 1, a.end());
    dft(a);
    int invn = power(n, P - 2);
    for (int &x : a) x = x * invn % P;
}

vector<int> multiply(vector<int> a, vector<int> b) {
    if (a.empty() || b.empty()) return {};

    int need = (int)a.size() + (int)b.size() - 1, n = 1;
    while (n < need) n <<= 1;

    a.resize(n); b.resize(n);
    dft(a); dft(b);
    for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % P;
    idft(a);

    a.resize(need);
    while (!a.empty() && a.back() == 0) a.pop_back();
    return a;
}

struct Poly {
    vector<int> a;

    Poly() {}
    Poly(int x) { if ((x = norm(x))) a = {x}; }
    Poly(const vector<int> &v) : a(v) {
        for (int &x : a) x = norm(x);
        shrink();
    }

    void shrink() { while (!a.empty() && a.back() == 0) a.pop_back(); }
    int size() const { return (int)a.size(); }
    int operator[](int i) const { return 0 <= i && i < size() ? a[i] : 0; }

    int &coef(int i) {
        if (i >= size()) a.resize(i + 1);
        return a[i];
    }

    Poly modxk(int k) const {
        if (k <= 0) return {};
        k = min(k, size());
        return Poly(vector<int>(a.begin(), a.begin() + k));
    }

    Poly divxk(int k) const {
        if (size() <= k) return {};
        return Poly(vector<int>(a.begin() + k, a.end()));
    }

    Poly mulxk(int k) const {
        if (size() == 0) return {};
        Poly r; r.a.assign(k, 0);
        r.a.insert(r.a.end(), a.begin(), a.end());
        return r;
    }

    friend Poly operator+(const Poly &A, const Poly &B) {
        int n = max(A.size(), B.size());
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = A[i] + B[i];
            if (c[i] >= P) c[i] -= P;
        }
        return Poly(c);
    }

    friend Poly operator-(const Poly &A, const Poly &B) {
        int n = max(A.size(), B.size());
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = A[i] - B[i];
            if (c[i] < 0) c[i] += P;
        }
        return Poly(c);
    }

    friend Poly operator*(const Poly &A, const Poly &B) {
        return Poly(multiply(A.a, B.a));
    }

    friend Poly operator*(Poly A, int c) {
        c = norm(c);
        if (c == 0) return {};
        for (int &x : A.a) x = x * c % P;
        A.shrink();
        return A;
    }

    friend Poly operator*(int c, Poly A) { return A * c; }
    friend Poly operator/(Poly A, int c) { return A * power(c, P - 2); }
    Poly &operator+=(const Poly &o) { return *this = *this + o; }
    Poly &operator-=(const Poly &o) { return *this = *this - o; }
    Poly &operator*=(const Poly &o) { return *this = *this * o; }

    Poly deriv() const {
        if (size() <= 1) return {};
        vector<int> c(size() - 1);
        for (int i = 1; i < size(); i++) c[i - 1] = a[i] * i % P;
        return Poly(c);
    }

    Poly integr() const {
        vector<int> c(size() + 1);

        static vector<int> inv{0, 1};
        if ((int)inv.size() <= size()) {
            int old = inv.size();
            inv.resize(size() + 1);
            for (int i = old; i <= size(); i++)
                inv[i] = (P - P / i) * inv[P % i] % P;
        }

        for (int i = 0; i < size(); i++) c[i + 1] = a[i] * inv[i + 1] % P;
        return Poly(c);
    }

    Poly inv(int m) const {
        assert(m >= 0);
        assert(size() && a[0] != 0);
        if (m == 0) return {};

        Poly x(power(a[0], P - 2));
        int k = 1;
        while (k < m) {
            k <<= 1;
            x = (x * (Poly(2) - modxk(k) * x)).modxk(k);
        }
        return x.modxk(m);
    }

    Poly log(int m) const {
        assert(m >= 0);
        assert((*this)[0] == 1);
        if (m == 0) return {};
        return (deriv() * inv(m)).integr().modxk(m);
    }

    Poly exp(int m) const {
        assert(m >= 0);
        assert((*this)[0] == 0);
        if (m == 0) return {};

        Poly x(1);
        int k = 1;
        while (k < m) {
            k <<= 1;
            x = (x * (Poly(1) - x.log(k) + modxk(k))).modxk(k);
        }
        return x.modxk(m);
    }

    Poly pow(int e, int m) const {
        assert(e >= 0 && m >= 0);
        if (m == 0) return {};
        if (e == 0) return Poly(1).modxk(m);
        if (size() == 0) return {};

        int t = 0;
        while (t < size() && a[t] == 0) t++;
        if (t == size()) return {};

        if (t > 0 && e >= (m + t - 1) / t) return {};
        int shift = t * e;
        int need = m - shift;

        Poly u = divxk(t);
        int c0 = u.a[0];
        int invc0 = power(c0, P - 2);
        u = u * invc0;

        Poly w = (u.log(need) * (e % P)).exp(need);
        w = w * power(c0, e % (P - 1));
        return w.mulxk(shift).modxk(m);
    }
};

pair<Poly, Poly> divmod(Poly A, Poly B) {
    A.shrink(); B.shrink();
    assert(B.size());

    if (A.size() < B.size()) return {Poly(), A};

    int n = A.size(), m = B.size(), need = n - m + 1;

    reverse(A.a.begin(), A.a.end()); reverse(B.a.begin(), B.a.end());

    Poly Q = (A.modxk(need) * B.inv(need)).modxk(need);
    reverse(Q.a.begin(), Q.a.end());
    Q.shrink();

    reverse(A.a.begin(), A.a.end()); reverse(B.a.begin(), B.a.end());

    Poly R = A - B * Q;
    R.shrink();
    return {Q, R};
}

Poly operator/(const Poly &A, const Poly &B) { return divmod(A, B).first; }
Poly operator%(const Poly &A, const Poly &B) { return divmod(A, B).second; }

vector<int> eval(const Poly &f, const vector<int> &xs) {
    int m = xs.size();
    if (m == 0) return {};
    if (f.size() == 0) return vector<int>(m, 0);

    int n = 1;
    while (n < m) n <<= 1;

    vector<Poly> seg(n << 1);
    for (int i = 0; i < n; i++) {
        if (i < m) seg[n + i] = Poly(vector<int>{norm(-xs[i]), 1});
        else seg[n + i] = Poly(1);
    }

    for (int i = n - 1; i; i--) seg[i] = seg[i << 1] * seg[i << 1 | 1];

    vector<int> ans(m);

    function<void(int, Poly)> dfs = [&](int p, Poly cur) {
        if (p >= n) {
            int id = p - n;
            if (id < m) ans[id] = cur[0];
            return;
        }
        dfs(p << 1, cur % seg[p << 1]);
        dfs(p << 1 | 1, cur % seg[p << 1 | 1]);
    };

    dfs(1, f % seg[1]);
    return ans;
}

vector<int> convolution(const vector<int> &a, const vector<int> &b) {
    return multiply(a, b);
}

}

vector<int> fac, ifac, inv, pr, mnp, pn, ipn;

void init(int n) {
    fac.assign(n + 1, 1);
    ifac.assign(n + 1, 1);
    inv.assign(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }

    mnp.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!mnp[i]) {
            mnp[i] = i;
            pr.push_back(i);
        }
        for (auto j : pr) {
            int m = i * j;
            if (m > n || mnp[i] > j) break;
            mnp[m] = i;
        }
    }

    pn.assign(n + 1, 1);
    ipn.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pn[i] = pn[i - 1] * n % mod;
        ipn[i] = ipn[i - 1] * inv[n] % mod;
    }
}

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

signed main() {
    int n;
    cin >> n;

    init(n);
    vector<int> f{1, 1, 0};
    for (int j = 3; j <= n; j++) {
        if (mnp[j] == j) {
            f.push_back(fac[j] * ifac[j] % mod * inv[2] % mod * ipn[j - 1] % mod);
        } else {
            f.push_back(0);
        }
    }

    FPS::Poly F(f);
    for (int i = 0; i <= 3; i++) cerr << F[i] << " ";
    cerr << "\n";
    F = F.pow(n, n + 1);
    int ans = F[n];
    cerr << ans << "\n";
    ans = ans * pn[n - 2] % mod;
    ans = ans * fac[n] % mod;
    cout << ans << "\n";
}