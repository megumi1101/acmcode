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

    int ins(int x, int up) {
        int u = 0;
        for (int bit = up; bit >= 0; bit--) {
            int c = (x >> bit & 1);
            if (!t[u].ch[c]) t[u].ch[c] = newnode();
            u = t[u].ch[c];
        }
        return u;
    }

    int getmin(int x, int up) {
        int u = 0;
        int res = 0;
        for (int bit = up; bit >= 0; bit--) {
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    i64 ans = 0;
    n = a.size();
    
    auto dfs = [&](this auto &&dfs, int l, int r, int bit) -> void {
        if (bit < 0 || l >= r) return;
        int m = l - 1;
        while (m + 1 <= r && (a[m + 1] >> bit & 1) == 0) {
            m++;
        }
        dfs(l, m, bit - 1);
        dfs(m + 1, r, bit - 1);
        if (m < l || m == r) return;
        Trie tr;
        if (m - l + 1 < r - m) {
            for (int i = l; i <= m; i++) tr.ins(a[i], bit);
            int mn = INT_MAX;
            for (int i = m + 1; i <= r; i++) {
                mn = min(mn, tr.getmin(a[i], bit));
            }
            ans += mn;
        } else {
            for (int i = m + 1; i <= r; i++) tr.ins(a[i], bit);
            int mn = INT_MAX;
            for (int i = l; i <= m; i++) {
                mn = min(mn, tr.getmin(a[i], bit));
            }
            ans += mn;
        }
    };

    dfs(0, n - 1, 29);
    cout << ans << "\n";
}