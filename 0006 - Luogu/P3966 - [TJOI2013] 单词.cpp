#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    struct AC {
        static const int SIGMA = 26;
        static const char BASE = 'a';
        int Maxnode;
        struct Node {
            vector<int> ch;
            int ct, fail;
            Node() {
                fail = 0, ct = 0;
                ch.assign(26, 0);
            }
        };
        
        vector<Node> t;
        int cnt, maxnode;

        AC (int maxnode) {
            init(maxnode);
        }

        void init(int maxnode) {
            Maxnode = maxnode;
            t.assign(Maxnode, Node());
            cnt = 0;
        }

        int newnode () {
            cnt++;
            if (cnt >= Maxnode) {
                Maxnode = Maxnode * 3 / 2 + 1000;
                t.resize(Maxnode);
            }
            t[cnt] = Node();
            return cnt;
        }

        int ins(const string &s) {
            int u = 0;
            for (char c : s) {
                int v = c - BASE;
                if (!t[u].ch[v]) t[u].ch[v] = newnode();
                u = t[u].ch[v];
                t[u].ct++;
            }
            return u;
        }

        void build (vector<int> &a) {
            queue<int> q;
            for (int i = 0; i < 26; i++) if (t[0].ch[i]) q.push(t[0].ch[i]), a.push_back(t[0].ch[i]);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int i = 0; i < 26; i++) {
                    int v = t[u].ch[i];
                    if (v) t[v].fail = t[t[u].fail].ch[i], q.push(v), a.push_back(v);
                    else t[u].ch[i] = t[t[u].fail].ch[i]; 
                }
            }
        }
    };
    
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1), p;
        AC ac(100000);
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            a[i] = ac.ins(s);
        }
        ac.build(p);
        reverse(p.begin(), p.end());
        for (auto x : p) {
            ac.t[ac.t[x].fail].ct += ac.t[x].ct;
        }
        for (int i = 1; i <= n; i++) {
            cout << ac.t[a[i]].ct << "\n";
        }
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