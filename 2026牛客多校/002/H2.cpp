#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

using ull = unsigned long long;
void sol() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> vis(1 << n);
    vis[a] = 1, vis[b] = 1; 
    if ((popcount((ull)a) & 1) != (popcount((ull)b) & 1)) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        int mx = (1 << n);
        for (int i = 0; i < mx; i++) {
            if (vis[i]) continue;
            for (int j = i + 1; j < mx; j++) {
                if (vis[j]) continue;
                if (popcount(ull(i ^ j)) == 2) {
                    vis[i] = 1;
                    vis[j] = 1;
                    cout << i << " " << j << "\n";
                    break;
                }
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    
}