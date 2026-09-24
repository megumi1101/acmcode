#include<bits/stdc++.h>
using namespace std;


namespace xbbbz {
#define int long long

struct AC {
    static const int SIGMA = 26;
    static const char BASE = 'a';
    int Maxnode;
    struct Node {
        vector<int> ch;
        int ct, fail, num;
        Node() {
            fail = 0, ct = 0, num = 0;
            ch.assign(26, 0);
        }
    };
    
    vector<Node> t;
    int cnt, maxnode;
    vector<int> ord;

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
        for (int i = 0; i < 26; i++) if (t[0].ch[i]) q.push(t[0].ch[i]), ord.push_back(t[0].ch[i]);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < 26; i++) {
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
        int n;
        cin >> n;
        AC ac(1000);
        vector<string> t(n);
        for (auto &s : t) {
            cin >> s;
            if (mp[s]) continue;
            mp[s] = 1;
            ac.ins(s);
        }
        ac.build();
        string ss;
        cin >> ss;
        ac.query(ss);
        for (auto &s : t) {
            cout << ac.find(s) << "\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        // init();
        while (T--) {
            sol();
        }
    }
    #undef int 
}

int main() {
    return xbbbz::main(), 0;
}