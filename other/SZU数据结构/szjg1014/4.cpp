#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
struct AC {
    static const int SIGMA = 128;
    static const int BASE = 0;
    int Maxnode;
    struct Node {
        vector<int> ch;
        int fail, num;
        Node() {
            fail = 0, num = 0;
            ch.assign(SIGMA, 0);
        }
    };
    
    vector<Node> t;
    int cnt;
    vector<int> ord;

    AC (int maxnode) {
        init(maxnode);
    }

    void init(int maxnode) {
        Maxnode = maxnode;
        t.assign(Maxnode, Node());
        ord.clear();
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
        }
        return u;
    }
    
    int find(string s) {
        int u = 0;
        for (char c : s) {
            int v = c - BASE;
            u = t[u].ch[v];
        }
        return t[u].num;
    }

    void build () {
        queue<int> q;
        for (int i = 0; i < SIGMA; i++) if (t[0].ch[i]) q.push(t[0].ch[i]), ord.push_back(t[0].ch[i]);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < SIGMA; i++) {
                int v = t[u].ch[i];
                if (v) t[v].fail = t[t[u].fail].ch[i], q.push(v), ord.push_back(v);
                else t[u].ch[i] = t[t[u].fail].ch[i]; 
            }
        }
    }
    void query(string s) {
        int u = 0;
        for (char c : s) {
            int v = c - BASE;
            u = t[u].ch[v];
            t[u].num++;
        }
        for (int i = ord.size() - 1; i >= 0; i--) {
            int u = ord[i];
            t[t[u].fail].num += t[u].num;
        }
    }
};
    void sol() {
        map<string, bool> mp;
        AC ac(1000);
        string ss;
        cin >> ss;
        int n;
        cin >> n;
        vector<string> t(n);
        for (auto &s : t) {
            cin >> s;
            if (mp[s]) continue;
            mp[s] = 1;
            ac.ins(s);
        }
        ac.build();
        ac.query(ss);
        for (auto &s : t) {
            cout << s << ":" << ac.find(s) << "\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}