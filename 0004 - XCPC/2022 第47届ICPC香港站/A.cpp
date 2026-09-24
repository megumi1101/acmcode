// QOJ user: lnxbb
// Contest: 2022 ç¬?7å±ŠICPCé¦™æ¸¯ç«?// Problem: #5455. TreeScript (5455)
// Submission: https://qoj.ac/submission/1549213
// Language: C++26

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    void sol() {
        int n;
        cin >> n;
        vector<vector<int>> ed(n + 1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i == 0) continue;
            ed[x].push_back(i + 1);
        }

        vector<int> f(n + 1);
        auto dfs = [&](auto &&dfs, int u) -> void {
            f[u] = 1;
            int mx = -1, smx = -1;
            for (auto v : ed[u]) {
                dfs(dfs, v);
                if (f[v] > mx) {
                    smx = mx;
                    mx = f[v];
                } else if (f[v] > smx) {
                    smx = f[v];
                }
            }
            f[u] = max(f[u], mx + (mx == smx));
        };

        dfs(dfs, 1);
        cout << f[1] << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
</code>