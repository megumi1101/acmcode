#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    const double EPS = 1e-12;

    while (T--) {
        int n, m; 
        cin >> n >> m;

        vector<string> names(n);
        for (int i = 0; i < n; ++i) cin >> names[i];

        unordered_map<string,int> id;
        id.reserve(n * 2);
        for (int i = 0; i < n; ++i) id[names[i]] = i;

        vector<vector<double>> w(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; ++i) w[i][i] = 1.0;

        for (int e = 0; e < m; ++e) {
            string a, b; double r;
            cin >> a >> r >> b;
            int u = id[a], v = id[b];
            w[u][v] = max(w[u][v], r);
        }

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i) if (w[i][k] > 0)
                for (int j = 0; j < n; ++j) if (w[k][j] > 0)
                    w[i][j] = max(w[i][j], w[i][k] * w[k][j]);

        bool ok = false;
        for (int i = 0; i < n; ++i) if (w[i][i] > 1.0 + EPS) { ok = true; break; }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
