#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e9;
void sol() {
    int n, k;
    cin >> n >> k;
    if (k & 1) {
        for (int i = 0; i < k; i++) {
            cout << n << " ";
        }
    } else {
        int t = (63 - __builtin_clzll(n));
        int x = 1 << t;
        vector<int> ans(k);
        for (int i = 0; i < k - 1; i++) ans[i] += (1 << t);
        int now = 0;
        for (int bit = t - 1; bit >= 0; bit--) {
            if ((n >> bit) & 1) {
                if (now < k) now++;
                for (int i = 0; i < k; i++) {
                    if (i == now - 1) continue;
                    ans[i] += (1 << bit);
                }
            } else {
                int tmp = (now + 1) / 2 * 2;
                for (int i = 0; i < tmp - 1; i++) ans[i] += (1 << bit);
                if (tmp) ans[k - 1] += (1 << bit);
            }
        }
        for (auto x : ans) cout << x << " ";
    }
    cout << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
 
    int T;
    cin >> T;
    while (T--) {
        sol();
    }
    
}
