#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
const int inf = 1e9; 
vector<int> vis, pr;
    void init() {
        vis.assign(2e7 + 10, 0);
        int n = 2e7;
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) {
                pr.push_back(i);
            }
            for (int j : pr) {
                if (i * j > n) break;
                int m = i * j;
                vis[m] = 1;
                if (i % j == 0) break; 
            }
        }
    }
    void sol() {
        int n;
        cin >> n;
        vector<long long> cnt(2e7 + 10);
        vector<long long> f(2e7 + 10);
        int m = 2e7;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        for (int j : pr) {
            for (int i = m / j; i >= 0; i--) {
                cnt[i] += cnt[i * j];
            }
        }
        
        for (int i = m; i; i--) {
            f[i] = i * cnt[i];
            for (int j : pr) {
                if (i * j > m) break;
                f[i] = max(f[i], f[i * j] + (cnt[i] - cnt[i * j]) * i);
            }
        }
        cout << f[1] << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        init();
        // cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
