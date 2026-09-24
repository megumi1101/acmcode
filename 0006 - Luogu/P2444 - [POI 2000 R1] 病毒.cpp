#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    struct AC {
        static const char BASE = '0';
        struct Node {
            int ch[2];
            int fail;
            Node() {
                ch[0] = ch[1] = fail = 0;
            }
        };

        int Maxnode, cnt;
        vector<Node> t;
        vector<int> vis, end, f, vis2;

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
                Maxnode = Maxnode *3 /2 + 1000;
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
            

            for (int i = 0; i < 2; i++) if (t[0].ch[i]) q.push(t[0].ch[i]);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int i = 0; i < 2; i++) {
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
            vis2.assign(Maxnode, 0);
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
            f.assign(Maxnode, -1);
        }

        void dfs(int u) {
            if (vis2[u] == 1) {
                cout << "TAK";
                exit(0);
            }
            vis2[u] = 1;
            for (int i = 0; i < 2; i++) {
                int v = t[u].ch[i];
                if (!vis[v] && vis2[v] != -1) {
                    dfs(v);
                }
            }
            vis2[u] = -1;
        }
    };

    void sol() {
        int n;
        cin >> n;
        AC ac(20000);
        int mxsiz = -1;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            mxsiz = max(mxsiz, (int)s.size());
            ac.ins(s);
        }
        ac.build();
        ac.dfs(0);
        cout << "NIE";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();

    }
}

int main() {
    return Xbbbz::main(), 0;
}