#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    void sol() {
        char typ; int n;
        cin >> typ >> n;                      
        vector<string> name(n+1);
        unordered_map<string,int> id;
        for (int i = 1; i <= n; ++i) {
            cin >> name[i];
            id[name[i]] = i;
        }
        int m; cin >> m;
        vector<vector<int>> a(n+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; ++i) {
            string u, v; cin >> u >> v;
            int x = id[u], y = id[v];
            a[x][y] = 1;
            if (typ == 'U') a[y][x] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1) cout << ' ';
                cout << a[i][j];
            }
            cout << '\n';
        }

        vector<string> iso;
        if (typ == 'D') {
            for (int i = 1; i <= n; ++i) {
                int outd = 0, ind = 0;
                for (int j = 1; j <= n; ++j) outd += a[i][j];
                for (int j = 1; j <= n; ++j) ind  += a[j][i];
                int deg = outd + ind;
                if (deg == 0) { iso.push_back(name[i]); continue; }
                cout << name[i] << ": " << outd << ' ' << ind << ' ' << deg << '\n';
            }
        } else { 
            for (int i = 1; i <= n; ++i) {
                int deg = 0;
                for (int j = 1; j <= n; ++j) deg += a[i][j];
                if (deg == 0) { iso.push_back(name[i]); continue; }
                cout << name[i] << ": " << deg << '\n';
            }
        }

        for (auto &s : iso) cout << s << '\n';
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}