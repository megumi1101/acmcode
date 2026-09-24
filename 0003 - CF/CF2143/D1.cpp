#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 1e9 + 7;
 
    struct Fen {
        int n;
        vector<int> a;
        Fen (int n) {
            this->n = n;
            init(n);
        }
        void init(int n) {
            a.assign(n + 5, 0);
        }
        void add(int x, int v) {
            x++;
            for (int i = x; i <= n; i += i & -i) {
                a[i] += v;
                a[i] %= mod;
            }
        }
        int sum(int x) {
            x++;
            int res = 0;
            for (int i = x; i; i -= i & -i) {
                res += a[i];
                res %= mod;
            }
            return res;
        }
        int getsum(int l, int r) {
            return (sum(r) - sum(l - 1) + mod) % mod;
        }
    };
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<vector<int>> f(n + 5, vector<int> (n + 5, 0));
        vector<vector<int>> nf(n + 5, vector<int> (n + 5, 0));
        vector<Fen> fen1(n + 5, Fen(n + 1)), fen2(n + 5, Fen(n + 1));
        f[0][0] = 1;
        fen1[0].add(0, 1);
        fen2[0].add(0, 1);
        for (int i = 1; i <= n; i++) {
            vector<int> tmp1(n + 1), tmp2(n + 1);
            for (int j = 0; j <= n; j++) tmp1[j] = fen2[j].sum(a[i]);
            for (int j = 0; j <= n; j++) tmp2[j] = fen1[j].sum(a[i]);
            for (int j = 0; j < a[i]; j++) {
                (f[a[i]][j] += tmp1[j]) %= mod;
                fen2[j].add(a[i], tmp1[j]);
                fen1[a[i]].add(j, tmp1[j]);
            }
            for (int j = a[i] + 1; j <= n; j++) {
                (f[j][a[i]] += tmp2[j]) %= mod;
                fen2[a[i]].add(j, tmp2[j]);
                fen1[j].add(a[i], tmp2[j]);
            }
            // nf = f;
            // for (int j = 0; j <= n; j++) {
            //     for (int k = 0; k <= j; k++) {
            //         if (a[i] >= j) (nf[a[i]][k] += f[j][k]) %= mod;
            //         if (a[i] < j && a[i] >= k) (nf[j][a[i]] += f[j][k]) %= mod;
            //     }
            // }
            // f = nf;
        }
        int ans = 0;
        cerr << f[0][0] << "\n";
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                (ans += f[i][j]) %= mod;
        
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(),0;
}
