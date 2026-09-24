#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> ed(n + 1);
        for (int i = 2; i <= n; i++) {
            int x; cin >> x;
            ed[x].emplace_back(i);
        }
        int s = 10000000;
        vector<int> w(n + 1);
        auto dfs = [&] (auto &&dfs, int u, int dep) -> void {
            w[dep]++;
            if (!ed[u].size()) {
                s = min(s, dep);
            }
            for (auto v : ed[u]) {
                dfs(dfs, v, dep + 1);
            }
        };
 
        dfs(dfs, 1, 1);
        
        bitset<1001> B;
        B.reset();
        B[0] = 1;
        int sum = 0;
        for (int i = 1; i <= s; i++) {
            B = B | B << w[i];
            sum += w[i];
        }
        
        int x = k, y = n - k;
        if (x > y) swap(x, y);
        for (int i = 0; i <= x; i++) {
            if (B[i] == 1 && sum - i <= y) {
                cout << s << "\n";
                return;
            }
        }
        cout << s - 1 << "\n";
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
