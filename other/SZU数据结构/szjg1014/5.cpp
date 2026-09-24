#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
constexpr int inf = 1e9;
struct SAM {
    static constexpr int SIGMA = 128;
    struct Node {
        int len;
        int link;
        int mn = inf;
        int mx = -inf;
        array<int, SIGMA> next;
        Node() : len{}, link{}, next{} {}
    };
    vector<Node> t;
    SAM() { init();}
    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }
    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }
    int extend(int p, int c) {
        if (t[p].next[c]) {
            int q = t[p].next[c];
            if (t[q].len == t[p].len + 1) {
                return q;
            }
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = t[q].link;
            t[r].next = t[q].next;
            t[q].link = r;
            while (t[p].next[c] == q) {
                t[p].next[c] = r;
                p = t[p].link;
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        while (!t[p].next[c]) {
            t[p].next[c] = cur;
            p = t[p].link;
        }
        t[cur].link = extend(p, c);
        return cur;
    }
    
    void build (string &s) {
        int u = 1;
        for (int i = 0; i < s.size(); i++) {
            auto &c = s[i];
            u = extend(u, c);
            t[u].mn = min(t[u].mn, i);
            t[u].mx = max(t[u].mx, i);
        }
    }

    int get() {
        vector<int> order(t.size() - 1);
        for (int i = 1; i < t.size(); i++) order[i - 1] = i;
        sort(order.begin(), order.end(), [&](int a, int b) {
            return t[a].len > t[b].len;
        });
        for (int u : order) {
            int fat = t[u].link;
            t[fat].mn = min(t[fat].mn, t[u].mn);
            t[fat].mx = max(t[fat].mx, t[u].mx);
        }
        int ans = 0;
        for (int u : order) {
            int res = min(t[u].len, t[u].mx - t[u].mn);
            ans = max(ans, res);
        }
        if (ans == 0) ans = -1;
        return ans;
    }
};


    void sol() {
        SAM sam;
        string s;
        cin >> s;
        sam.build(s);
        cout << sam.get() << "\n";
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