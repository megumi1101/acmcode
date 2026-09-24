#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
#define db double
    const int N = 5e3 + 10;
    double g[N][N];
    void init() {
        int n = N - 10;
        g[1][1] = 1.0;
        g[2][1] = 0.5;
        for (int i = 3; i <= n; i++) {
            g[i][1] = 1.0 / (db)i;
            for (int j = 2; j <= i; j++) {
                g[i][j] = g[i - 2][j - 2] * db(j - 2) / (db)i + g[i - 2][j - 1] * db(i - j) / (db)i;
            }
        }
    }
    vector<int> ed[N];
    void sol() {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) ed[i].clear();
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back(y);
        }
        vector<double> f(n + 5);
        f[n] = 1.0;
        for (int i = n - 1; i >= 1; i--) {
            sort(ed[i].begin(), ed[i].end(), [&](int a, int b) {return f[a] > f[b];});
            int sz = ed[i].size();
            for (int j = 0; j < sz; j++) {
                int v = ed[i][j];
                f[i] += f[v] * g[sz][j + 1];
            }
        }
        cout << fixed << setprecision(12) << f[1] << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        init();
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
