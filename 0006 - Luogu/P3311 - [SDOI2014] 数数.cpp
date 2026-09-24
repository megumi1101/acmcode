#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
const int mod = 1e9 + 7;
    struct AC {
        static const char BASE = '0';
        struct Node {
            vector<int> ch;
            int fail;
            Node() {
                ch.assign(10, 0); 
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
            for (int i = 0; i < 10; i++) if (t[0].ch[i]) q.push(t[0].ch[i]);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int i = 0; i < 10; i++) {
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
        string s;
        int m;
        cin >> s >> m;
        AC ac(1000);
        int mxsiz = -1;
        for (int i = 1; i <= m; i++) {
            string ss;
            cin >> ss;
            ac.ins(ss);
        }
        ac.build();
        int siz = s.size();
        vector<vector<vector<int>>> f(ac.cnt + 5, vector<vector<int>> (s.size() + 5, vector<int>(2, -1)));
        auto dfs = [&](auto &&dfs, int u, int len, bool qd, bool lim) -> int {
            if (len >= siz) return 1;
            if (!lim && f[u][len][qd] != -1) return f[u][len][qd];
            int up = 9;
            int res = 0;
            if (lim) up = s[len] - '0';
            for (int i = 0; i <= up; i++) {
                int v = ac.t[u].ch[i];
                if (qd && i == 0) v = u;
                if (ac.vis[v]) continue;
                res += dfs(dfs, v, len + 1, qd && i == 0, lim && i == up);
                if (res >= mod) res -= mod;
            }
            if (!lim) f[u][len][qd] = res;
            return res;
        };
        
        int ans = dfs(dfs, 0, 0, 1, 1);
        ans += mod;
        ans -= 1;
        if (ans >= mod) ans -= mod;
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