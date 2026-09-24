#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
const int mod = 1e4 + 7;
    struct AC {
        static const char BASE = 'A';
        struct Node {
            vector<int> ch;
            int fail;
            Node() {
                ch.assign(26, 0); 
                fail = 0;
            }
        };

        int Maxnode, cnt;
        vector<Node> t;
        vector<int> vis, end;

        AC(int maxnode) {
            init(maxnode);
        }
        void init(int maxnode) {
            cnt = 0;
            Maxnode = maxnode;
            t.assign(Maxnode, Node());
        }
        
        int newnode() {
            cnt++;
            if (cnt >= Maxnode) {
                Maxnode = Maxnode *3 /2 + 100;
                t.resize(Maxnode);
            }
            t[cnt] = Node();
            return cnt;
        }
        void ins(const string &s) {
            int u = 0;
            for (char c : s) {
                int v = c - BASE;
                if (!t[u].ch[v]) t[u].ch[v] = newnode();
                u = t[u].ch[v];
            }
            end.push_back(u);
        }

        void build() {
            queue<int> q;
            for (int i = 0; i < 26; i++) if (t[0].ch[i]) q.push(t[0].ch[i]);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int i = 0; i < 26; i++) {
                    int v = t[u].ch[i];
                    if (v) {
                        t[v].fail = t[t[u].fail].ch[i];
                        q.push(v);
                    }
                    else {
                        t[u].ch[i] = t[t[u].fail].ch[i];
                    }
                }
            } 

            vis.assign(Maxnode, 0);
            vector<vector<int>> ed(cnt + 5);
            for (int i = 1; i <= cnt; i++) {
                ed[t[i].fail].push_back(i);
            }
            for (auto x: end) vis[x] = 1;
            auto dfs = [&](auto &&dfs, int u) -> void {
                for (int v : ed[u]) {
                    vis[v] |= vis[u];
                    dfs(dfs, v);
                }
            };
            dfs(dfs, 0);
        }

    };
    void sol() {
        int n, m;
        cin >> n >> m;
        AC ac(1000);
        int mxsiz = -1;
        for (int i = 1; i <= n; i++) {
            string ss;
            cin >> ss;
            ac.ins(ss);
        }
        ac.build();
        vector<vector<int>> f(ac.cnt + 5, vector<int> (m + 5, -1));
        auto dfs = [&](auto &&dfs, int u, int len) -> int {
            if (len >= m) return 1;
            if (f[u][len] != -1) return f[u][len];
            int res = 0;
            for (int i = 0; i < 26; i++) {
                int v = ac.t[u].ch[i];
                if (ac.vis[v]) continue;
                res += dfs(dfs, v, len + 1);
                if (res >= mod) res -= mod;
            }
            return f[u][len] = res;
        };
        
        int ans = 1;
        for (int i = 1; i <= m; i++) {
            ans *= 26;
            ans %= mod;
        }
        ans -= dfs(dfs, 0, 0);
        ans += mod;
        ans %= mod;
        cout <<  ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}