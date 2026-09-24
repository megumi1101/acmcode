#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
const int inf = 1e9;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1), b;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = inf;
        bool fg = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] % 3 != 0) {
                fg = 0;
                break;
            }
        }
        if (fg) {
            int res = 0;
            for (int i = 1; i <= n; i++) {
                res = max (res, a[i] / 3);
            }
            ans = min(ans, res);
        }
 
 
        fg = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] % 3 == 2) {
                fg = 0;
                break;
            }
        }
        if (fg) {
            int res = 0;
            for (int i = 1; i <= n; i++) {
                res = max (res, a[i] / 3);
            }
            res++;
            ans = min(ans, res);
        }
 
 
        fg = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] % 3 == 1) {
                fg = 0;
                break;
            }
        }
        if (fg) {
            int res = 0;
            for (int i = 1; i <= n; i++) {
                res = max (res, a[i] / 3);
               
            }
            res++;
            ans = min(ans, res);
        }
 
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > 3) {
                if (a[i] % 3) {
                    res = max(res, a[i] / 3);
                } else {
                    res = max(res, (a[i] - 3) / 3);
                }
            }
            
        }
        res += 2;
        ans = min(ans, res);
 
 
        fg = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                fg = 0;
                break;
            }
        }
        if (fg) {
            int res = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] % 3 == 0) {
                    res = max(res, a[i] / 3);
                } else if (a[i] % 3 == 1) {
                    res = max(res, (a[i] - 4) / 3);
                } else {
                    res = max(res, (a[i] - 2) / 3);
                }
               
            }
            res += 2;
            ans = min(ans, res);
        }
 
        cout << ans << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
