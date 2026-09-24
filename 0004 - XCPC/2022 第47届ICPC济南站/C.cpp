// QOJ user: lnxbb
// Contest: 2022 Á¨?7Â±äICPCÊµéÂçóÁ´?// Problem: #5139. DFS Order 2 (5139)
// Submission: https://qoj.ac/submission/1608798
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int mod = 998244353;
vector<int> fac, inv, ifac;
void init() {
    int n = 500;
    fac.assign(n + 1, 1);
    inv.assign(n + 1, 1);
    ifac.assign(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }
}
    void sol() {
        int n;
        cin >> n;
        vector<vector<int>> ed(n + 1);
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }

        vector<int> siz(n + 1, 1);
        int sum = 1;

        auto dfs = [&](auto &&self, int u, int fat) -> void {
            if (u == 1) sum *= fac[ed[u].size()];
            else if (ed[u].size() > 1) (sum *= fac[ed[u].size() - 1]) %= mod; 
            for (auto v : ed[u]) {
                if (v == fat) continue;
                self(self, v, u);
                siz[u] += siz[v];
            }
        };
        dfs(dfs, 1, 0);

        vector ans(n + 1, vector<int>(n + 1, 0));
        ans[1][1] = sum;
        auto dfs2 = [&](auto &&self, int u, int fat) -> void {
            int ct = ed[u].size();
            if (u != 1) ct--;
            vector f(ct + 1, vector<int>(siz[u], 0));
            f[0][0] = 1;
            for (auto v : ed[u]) {
                if (v == fat) continue;
                for (int i = ct; i > 0; i--) {
                    for (int j = siz[u] - 1; j > 0; j--) {
                        if (j >= siz[v])
                            (f[i][j] += f[i - 1][j - siz[v]]) %= mod;
                    }
                }
            }
            
            // cerr << "u == " << u << "\n";
            // for (int i = 0; i <= ct; i++) {
            //     for (int j = 0; j < siz[u]; j++) {
            //         cerr << f[i][j] << " ";
            //     }
            //     cerr << "\n";
            // }
            // cerr << "\n";

            for (auto v : ed[u]) {
                if (v == fat) continue;
                auto g = f;
                int div = ifac[ct];
                vector<int> pre(siz[u]);
                pre[0] = fac[ct - 1];
                for (int i = 1; i <= ct; i++) {
                    for (int j = 0; j < siz[u]; j++) {
                        if (j >= siz[v]) {
                            g[i][j] -= g[i - 1][j - siz[v]];
                            g[i][j] += mod;
                            g[i][j] %= mod; 
                        }
                        if (g[i][j]) (pre[j] += fac[i] * fac[ct - i - 1] % mod * g[i][j] % mod) %= mod;
                    }
                }


                // for (int i = 0; i <= ct; i++) {
                //     for (int j = 0; j < siz[u]; j++) {
                //         cerr << g[i][j] << " ";
                //     }
                //     cerr << "\n";
                // }
                // cerr << "\n";


                for (int j = 0; j < siz[u]; j++) {
                    for (int i = 1; i <= n; i++) {
                        if (i + j + 1<= n) (ans[v][i + j + 1] += ans[u][i] * pre[j] % mod * div % mod) %= mod;
                    }
                }
            }

            for (auto v : ed[u]) {
                if (v == fat) continue;
                self(self, v, u);
            }
        };
        dfs2(dfs2, 1, 0);


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        init();
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
</code>