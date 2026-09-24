#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    vector<int> all;
 
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[i, _] : a) cin >> i, all.push_back(i);
    for (auto &[_, i] : a) cin >> i, all.push_back(i);
 
    int m;
    cin >> m;
    vector<pair<int, int>> b(m);
    for (auto &[i, _] : b) cin >> i, all.push_back(i);
    for (auto &[_, i] : b) cin >> i, all.push_back(i);
 
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (auto &[i, _] : a) i = lower_bound(all.begin(), all.end(), i) - all.begin() + 1;
    for (auto &[_, i] : a) i = lower_bound(all.begin(), all.end(), i) - all.begin() + 1;
    for (auto &[i, _] : b) i = lower_bound(all.begin(), all.end(), i) - all.begin() + 1;
    for (auto &[_, i] : b) i = lower_bound(all.begin(), all.end(), i) - all.begin() + 1;
 
    int mxsiz = all.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    vector tm(2, vector(mxsiz + 2, 0));
    vector f(2, vector(mxsiz + 1, -1));
    vector vis(2, vector(mxsiz + 1, 0));
 
    for (auto [x, y] : a) tm[0][x] = max(tm[0][x], y);
    for (int i = mxsiz; i >= 1; i--) tm[0][i - 1] = max(tm[0][i - 1], tm[0][i]);
    for (auto [x, y] : b) tm[1][x] = max(tm[1][x], y);
    for (int i = mxsiz; i >= 1; i--) tm[1][i - 1] = max(tm[1][i - 1], tm[1][i]);
 
    auto get = [&](auto&&get, int op, int x) -> int {
        if (f[op][x] != -1) return f[op][x];
        if (vis[op][x]) {
            return 1;
        }
        if (!tm[op ^ 1][x + 1]) return 0;
        vis[op][x] = 1;
        int t = get(get, op ^ 1, tm[op ^ 1][x + 1]);
        int res = 1;
        if (t == 0) res = 2;
        else if (t == 2) res = 0;
        vis[op][x] = 0;
        return f[op][x] = res;
    };
 
    vector ans(3, 0);
    for (auto [_, i] : a) ans[get(get, 0, i)]++;
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
