#include <bits/stdc++.h>
 
using namespace std;
 
const int mod1 = 998244391;
const int mod2 = 998244389;
const int B = 100007;
const int N = 6e5 + 5;
struct Base {
    array<int, N> pow{};
    Base(int mod) {
        pow[0] = 1;
        for (int i = 1; i < N; ++i) pow[i] = 1LL * pow[i - 1] * B % mod;
    }
    const int operator[](int idx) const { return pow[idx]; }
} p1(mod1), p2(mod2);
 
struct Hash {
    vector<int> h1, h2; // 前缀哈希，h[0] = 0
 
    void build(const vector<int>& s) {
        int n = (int)s.size();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            h1[i + 1] = ( (long long)h1[i] * B + (s[i]) ) % mod1;
            h2[i + 1] = ( (long long)h2[i] * B + (s[i]) ) % mod2;
        }
    }
 
    static int merge(int x, int y) { return (x << 31) | y; } 
 
    int calc(int l, int r) const {
        int len = r - l + 1;
        int res1 = ( h1[r + 1] - 1LL * h1[l] * p1[len] % mod1 + mod1 ) % mod1;
        int res2 = ( h2[r + 1] - 1LL * h2[l] * p2[len] % mod2 + mod2 ) % mod2;
        return merge(res1, res2);
    }
};
 
void sol() {
    int n, k;
    cin >> n >> k;
    vector v(2, vector(n + 1, 0)) ;
 
    int c00 = 0, c01 = 0, c10 = 0, c11 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[0][i];
        if (v[0][i]) c01++;
        else c00++;
    }
    vector<vector<int>> ed(n + 1);
 
    
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
    }
    vector<int> vis(n + 1);
 
    vector cnt(2, vector(2, vector(2 * k + 1, 0)));
    auto dfs =[&](auto &&dfs, int u, int d, int op) -> void {
        if (vis[u]) return;
        cnt[op][v[op][u]][d]++;
        vis[u] = 1;
        for (auto v : ed[u]) dfs(dfs, v, (d + 1) % k, op);
    };
    dfs(dfs, 1, 0, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[1][i];
        if (v[1][i]) c11++;
        else c10++;
    }
    for (auto &v : ed) v.clear();
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
    }
    fill(vis.begin(), vis.end(), 0);
    dfs(dfs, 1, 0, 1);
    
 
    if (c00 + c10 != c01 + c11) {
        cout << "NO\n";
        return;
    }
    if (c00 == 0 || c01 == 0) {
        cout << "YES\n";
        return;
    }
 
 
    for (auto &v0 : cnt) {
        for (auto &a : v0) {
            for (int i = 0; i <= k; i++) {
                a[i + k] = a[i];
            }
        }
    }
    Hash h00, h01, h10, h11;
    h00.build(cnt[0][0]);
    h01.build(cnt[0][1]);
    h10.build(cnt[1][0]);
    h11.build(cnt[1][1]);
 
 
    for (int i = 0; i < k; i++) {
        if (h01.calc(i + 1, i + k) == h10.calc(2, k + 1) && h11.calc(1, k) == h00.calc(i + 2, i + k + 1)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
