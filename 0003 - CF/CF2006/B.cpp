#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
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
 
void sol() {
    int n, w;
    cin >> n >> w;
    vector<vector<int>> ed(n + 1);
    vector<int> fa(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        ed[fa[i]].push_back(i);
    }
 
    vector<vector<int>> dif(n + 1), con(n + 1);
    int u = n;
    while (u != 1) {
        dif[u].push_back(1);
        con[1].push_back(u);
        u = fa[u];
    }
    for (int i = 2; i <= n; i++) {
        int j = i;
        for (; j > i - 1; j = fa[j]) {
            dif[j].push_back(i);
            con[i].push_back(j);
        }
 
        int k = i - 1;
        for (; k != j; k = fa[k]) {
            dif[k].push_back(i);
            con[i].push_back(k);
        }
    }
 
    vector<pair<int, int>> p(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> p[i].first >> p[i].second;
    }
    reverse(p.begin(), p.end());
 
    vector<int> ans;
    int sum = 2 * w;
 
    Fenwick<int> fen(n + 5);
    vector<int> vis(n + 1);
    ans.push_back(sum);
    int now = 0;
    int cnt = 0;
    for (auto[x, y] : p) {
        int ct = 0;
        for (auto i : dif[x]) {
 
            if (vis[i]) {ct++; continue;}
            vis[i] = 1;
            sum += now;
        }
        
        sum += (cnt - ct) * y;
        cnt += dif[x].size() - ct;
        now += y;
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 1; i < n; i++) cout << ans[i] << " ";
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
