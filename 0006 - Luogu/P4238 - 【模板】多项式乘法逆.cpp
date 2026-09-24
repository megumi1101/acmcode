#include <bits/stdc++.h>
using namespace std;
#define int long long

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

} // namespace FPS
using namespace FPS;
namespace Xbbbz {

const int inf = 1e18;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Poly f(a);
        Poly g = f.inv(n);
        for (int i = 0; i < n; i++) cout << g.a[i] << " ";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
#undef int
int main() {
    return Xbbbz::main(), 0;
}
