#include <bits/stdc++.h>

using namespace std;

#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    // iota(p.begin(), p.end(), 0);
    {
        for (int i = 0; i < n; i++) cin >> p[i];
        sort(p.begin(), p.end()); 
    }
    int ans = 0;
    do {
        vector<int> suf(n);
        suf.back() = p.back();
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i + 1], p[i]);
        }
        vector<int> to(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (p[i] + p[j] == suf[i]) {
                    to[i] = j;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            vector<int> vis(n);
            int u = i;
            int cnt = 0;
            vector<int> t;
            while (u != -1 && !vis[u]) {
                vis[u] = 1;
                t.push_back(u);
                cnt++;
                u = to[u];
            }
            if (cnt == n) {
                ans++;
                cout << ans << ":\n";
                for (auto x : p) cout << x << " ";
                cout << "\n";
                for (auto x : t) cout << p[x] << " ";
                cout << "\n";
                break;
            }
        }
    } while(next_permutation(p.begin(), p.end()));
}