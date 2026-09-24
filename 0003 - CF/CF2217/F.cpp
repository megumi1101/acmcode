#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int x1, x2;
    cin >> x1 >> x2;
 
    if (x1 > x2) {
        cout << "1 1\n";
        return;
    }
 
 
    vector<int> ans(x1);
    for (int K = 0; K < x1; K++) {
        int X = (x2 - 1 - K) / 2;
        
        if (X < 0) {
            ans[K] = 0;
            continue;
        }
 
        ans[K] = (1ll << __builtin_popcountll(K)) *
        ([&](this auto&& self, int pos, int lim) -> int {
            if (pos < 0) return 1;
            if (!lim) {
                int mask = (1ll << (pos + 1)) - 1;
                return 1ll << (__builtin_popcountll((~K) & mask));
            }
            
            int res = 0;
            int up = 1;
            if (lim) up = (X >> pos) & 1;
            for (int i = 0; i <= up; i++) {
                if (i == 1 && ((K >> pos) & 1)) continue;
                res += self(pos - 1, lim && (i == up));
            }
 
            return res;
        } (19, 1) );
    }
 
    int mnpos = 0;
    for (int i = 0; i < x1; i++) {
        if (ans[mnpos] > ans[i]) {
            mnpos = i;
        }
    }
    cout << mnpos + 1 << " " << x1 << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
