#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> p(8);
    auto dfs = [&](auto &&self, int u) -> void {
        if (u == 7) {
            vector f(9, vector(9, (int)1e9));
            for (int i = 0; i < 7; i++) {
                f[i + 2][p[i]] = 1;
                f[p[i]][i + 2] = 1;
            }

            for (int i = 1; i <= 8; i++) {
                f[i][i] = 0;
            }

            for (int k = 1; k <= 8; k++) {
                for (int i = 1; i <= 8; i++) {
                    for (int j = 1; j <= 8; j++) {
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                    }
                }
            }

            int a1 = 0, a2 = 0, a3 = 0;
            for (int i = 1; i + 1 <= 8; i++) {
                if (f[i][i + 1] == 1) {
                    a1++;
                }
                if (f[i][i + 1] == 2) {
                    a2++;
                }
                if (f[i][i + 1] == 3) {
                    a3++;
                }
            }

            if (a1 == 1 && a2 == 1 && a3 == 5) {
                for (int i = 0; i < 7; i++) {
                    cout << p[i] << " ";
                }
                cout << "\n";
            }
            return;
        } 

        for (int i = 1; i <= 8; i++) {
            if (u + 1 == i) continue;
            p[u] = i;
            self(self, u + 1);
        }
        

    };

    dfs(dfs, 0);
}