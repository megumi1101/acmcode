#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> p;
const int mod = 998244353;
void add (int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void init() {
    int n = 3000;
    p.resize(n + 5);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % j == 0) p[i].push_back(j);
        }
    }
}
 
void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector f(n + 1, vector(m + 1, 0));
 
    if (a[1] > 1) {
        cout << "0\n";
        return;
    }
    f[1][1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) if (f[i][j]) {
            for (auto x : p[j]) {
                if (j + x <= m && (a[i + 1] == 0 || a[i + 1] == j + x)) {
                    add(f[i + 1][j + x], f[i][j]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) add(ans, f[n][i]);
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    init();
    int T;
    cin >> T;
    while (T--) sol();
}
