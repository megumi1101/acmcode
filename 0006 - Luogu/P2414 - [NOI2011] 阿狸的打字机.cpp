#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int N = 2e5 + 10;
    template <typename T>
    struct Fenwick {
        int n;
        vector<T> a;
        
        Fenwick(int n_ = 0) {
            init(n_);
        }
        
        void init(int n_) {
            n = n_;
            a.assign(n + 5, T{});
        }
        
        void add(int x, const T &v) {
            for (int i = x; i <= n; i += i & -i) {
                a[i] = a[i] + v;
            }
        }
        
        T sum(int x) {
            T ans{};
            for (int i = x; i; i -= i & -i) {
                ans = ans + a[i];
            }
            return ans;
        }
        
        T getsum(int l, int r) {
            return sum(r) - sum(l - 1);
        }
        //查找满足前缀和 <= k 的最大位置
        int select(const T &k) {
            int x = 0;
            T cur{};
            for (int i = 1 << std::__lg(n); i; i /= 2) {
                if (x + i <= n && cur + a[x + i] <= k) {
                    x += i;
                    cur = cur + a[x];
                }
            }
            return x;
        }
    };
    vector<vector<int>> ch(N, vector<int> (26)), ch2;
    vector<int> ne(N), siz(N), idn(N), cnt(N), fa(N), a;
    vector<vector<int>> ed(N);
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    void add(string s) {
        int u = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] != 'P' && s[i] != 'B') {
                int v = s[i] - 'a';
                if(!ch[u][v]) ch[u][v] = ++count;
                fa[ch[u][v]] = u;
                u = ch[u][v];
            }
            else if (s[i] == 'B') {
                u = fa[u];
            }
            else {
                cnt[u]++;
                count3++;
                a.push_back(u);
            }
        }
    }
    void build() {
        ch2 = ch;
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (ch[0][i]) q.push(ch[0][i]);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < 26; i++) {
                int v = ch[u][i];
                if (v) ne[v] = ch[ne[u]][i], q.push(v);
                else ch[u][i] = ch[ne[u]][i];
            }
        }
        for (int i = 1; i <= count; i++) ed[ne[i]].emplace_back(i);
    }
    
    void dfs(int u) {
        idn[u] = count2++;
        siz[u] = 1;
        for (auto v : ed[u]) {
            dfs(v);
            siz[u] += siz[v];
        }
    }
    void sol() {
        string s;
        cin >> s;
        add(s);
        build();
        int m;
        cin >> m;
        vector<vector<pair<int, int>>> p(count3);
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            p[y].emplace_back(i, x);
        }
        int u = 0;
        int ct4 = 0;
        dfs(0);
        Fenwick<int> fen(count2);
        for(int i = 0; i < s.size(); i++) {
            if (s[i] != 'P' && s[i] != 'B') {
                int v = s[i] - 'a';
                u = ch[u][v];
                fen.add(idn[u], 1);               
            }
            else if (s[i] == 'B') {
                fen.add(idn[u], -1);
                u = fa[u];
            }
            else {
                for (auto [id, x] : p[ct4]) {
                    int top = a[x];
                    ans[id] = fen.getsum(idn[top], idn[top] + siz[top] - 1);
                }
                ct4++;
            }
        }
        for (auto x : ans) cout << x << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}