// QOJ user: lnxbb
// Contest: 2022 �?7届ICPC香港�?// Problem: #5466. Permutation Compression (5466)
// Submission: https://qoj.ac/submission/1570565
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
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
    //查找满足前缀�?<= k 的最大位�?    int select(const T &k) {
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
const int inf = 1e9;
    void sol() {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n + 1), b(m + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];       
        vector<int> v(k);

        for (auto &i : v) cin >> i;
        vector<int> vis(n + 1, 1);
        int pos = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == b[pos]) {
                vis[i] = 0;
                pos++;
            }
            if (pos == m + 1) break;
        }
        if (pos <= m) {
            cout << "NO\n";
            return;
        }

        vector<int> tl(n + 1, 0);
        
        Fenwick<int> fen(n + 1);
        vector<pair<int, int>> st;
        vector<int> tr(n + 1, n + 1);
        
        for (int i = 1; i <= n; i++) {
            st.push_back({a[i], i});
        }
        sort(st.rbegin(), st.rend());
        set<int> seet;
        seet.insert(0);
        seet.insert(n + 1);
        for (auto[_, i] : st) {
            if (!vis[i]) {
                seet.insert(i);
            } else {
                auto itr = seet.lower_bound(i);
                auto itl = prev(itr);
                tl[i] = *itl;
                tr[i] = *itr;
            }
        }
        vector<pair<int, int>> pp;
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            if (vis[i]) pp.emplace_back(a[i], i);
        }
        sort(pp.rbegin(), pp.rend());

        for (auto[_, x] : pp) {
            
            sum[x] = fen.getsum(tl[x] + 1, tr[x] );
            // cerr << x << " " << sum[x] << "\n";
            fen.add(x, 1);
        }
        
        sort(v.begin(), v.end());
        vector<int> s;
        for (int i = 1; i <= n; i++) if (vis[i]) s.push_back(max(tr[i] - tl[i] - sum[i] - 1, 1));
        for (int i = 1; i <= n; i++) if (vis[i]) {
            // cerr << tr[i] - tl[i] - sum[i] - 1 << "\n";
            // cerr << tl[i] << " " << tr[i] << " " << sum[i] << "\n";
        }
        sort(s.begin(), s.end());
        for (int i = s.size() - 1; i >= 0; i--) {
            while (!v.empty() && s[i] < v.back()) v.pop_back();
            if (v.empty()) {
                cout << "NO\n";
                return;
            }
            v.pop_back();
        }

        cout << "YES\n";
        
    }
    void main() {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
}
/*
1
4 1 3
1 4 2 3
2
4 4 2
*/


</code>