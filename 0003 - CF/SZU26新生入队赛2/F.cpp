#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Trie {
    struct Node {
        array<int, 2> ch{};
    };

    vector<Node> t;
    int cnt;

    Trie() {
        t.push_back(Node());
        cnt = 0;
    }

    int newnode() {
        t.push_back(Node());
        return ++cnt;
    }

    int ins(int x) {
        int u = 0;
        for (int bit = 29; bit >= 0; bit--) {
            int c = (x >> bit & 1);
            if (!t[u].ch[c]) t[u].ch[c] = newnode();
            u = t[u].ch[c];
        }
        return u;
    }

    int getmin(int x) {
        int u = 0;
        int res = 0;
        for (int bit = 29; bit >= 0; bit--) {
            int c = (x >> bit & 1);
            if (t[u].ch[c]) {
                u = t[u].ch[c];
            } else {
                res ^= (1 << bit);
                u = t[u].ch[c ^ 1];
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    Trie tr0;
    map<int, int> mp;
    for (auto x : s) {
        mp[tr0.ins(x)] = x;
    }

    int siz = tr0.cnt;
    vector<Trie> tr(siz + 5);
    vector<vector<int>> p(siz + 5);

    i64 ans = 0;
    auto &t = tr0.t;
    [&](this auto &&dfs, int u) -> void {
        int v0 = t[u].ch[0], v1 = t[u].ch[1];
        if (!v0 && !v1) {
            int x = mp[u];
            tr[u].ins(x);
            p[u].push_back(x);
            return;
        } else if (v0 && !v1) {
            dfs(v0);
            tr[u] = move(tr[v0]);
            p[u] = move(p[v0]);
        } else if (!v0 && v1) {
            dfs(v1);
            tr[u] = move(tr[v1]);
            p[u] = move(p[v1]);
        } else {
            dfs(v0); dfs(v1);
            int v;
            if (p[v0].size() < p[v1].size()) {
                tr[u] = move(tr[v1]);
                p[u] = move(p[v1]);
                v = v0;
            } else {
                tr[u] = move(tr[v0]);
                p[u] = move(p[v0]);
                v = v1;
            }

            int mn = 2e9;
            for (auto x : p[v]) {
                mn = min(mn, tr[u].getmin(x));
            }
            ans += mn;

            for (auto x : p[v]) {
                p[u].push_back(x);
                tr[u].ins(x);
            }
        }
    } (0);

    cout << ans << "\n";
}