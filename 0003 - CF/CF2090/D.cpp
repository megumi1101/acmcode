#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
vector<int> pr, vis;
void init() {
    int n = 1e5;
    vis.assign(n + 5, 0);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) pr.push_back(i);
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
        vector<int> t(n + 1);
        vector<int> ans;
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) {
                int x = 2 * min(i - 1, n - i) + 1;
                // if (i == 2) cerr << x << "\n";
                if (x >= (n / 3) - 1) {
                    // cerr << 1 << "\n";
                    ans.push_back(i);
                    t[i] = 1;
                    for (int j = 1;; j++) {
                        int t1 = i - j;
                        int t2 = i + j;
                        if (t1 <= 0 || t2 > n) break;
                        t[t1] = 1;
                        t[t2] = 1;
                        ans.push_back(t1);
                        ans.push_back(t2);
                    }
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!t[i]) ans.push_back(i);
        }
        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        init();
        // for (int i : pr) cout << i << " ";
        cin >> T;
        while (T--) sol();
    }
}
#undef int
int main() {
    return Xbbbz::main(),0;
}
