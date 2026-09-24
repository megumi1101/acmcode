#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (auto &x : a) cin >> x;
        bool fg = 0;
        for (int i = 0; i + 1 < m; i++) {
            if (a[i + 1] != a[i] + 1) {
                fg = 1;
                break;
            }
        }
 
        if (!fg) {
            int mx = a[m - 1];
            int ans = n - mx + 1;
            cout << ans << "\n";
        }
        else {
            int mx = 0;
            for (int i = 0; i + 1 < m; i++) {
                
                if (a[i + 1] != a[i] + 1) {
                    if (a[i + 1] == 1) {
                        if (!mx) mx = a[i];
                        else {
                            if (a[i] != mx + 1) {
                                fg = 0;
                                break;
                            }
                            mx = a[i];
                        }
                    }
                }
                
            }if (a[m - 1] > mx + 1) fg = 0;
                mx++;
                if (n < mx) fg = 0;
                int t = fg;
                cout << t << "\n";
        }
 
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
int main() {
    return Xbbbz::main(),0;
}
