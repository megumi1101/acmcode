#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
    void sol(int now) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int l = -1, r = -1;
        int sumx = 0, sumy = 0;
        for (auto &x : a) {cin >> x; sumx += x; r = max(r, x + 1);}
        for (auto &x : b) {cin >> x; sumy += x; l = max(l, x + 1);}
        sort(b.begin(), b.end());
 
        if (sumx < sumy) {
            cout << "-1\n";
            return;
        }
 
        if (sumx == sumy) {
            sort(a.begin(), a.end());
            bool fg = 0;
            for (int i = 0; i < n; i++) if (b[i] != a[i]) {fg = 1; break;}
            if (!fg) cout << r << "\n";
            else cout << -1 << "\n";
            return;
        }
 
        vector<int> qrys;
 
        int k = sumx - sumy;
        for (int i = 1; i * i <= k; i++) {
            if (k % i == 0) {
                if (k / i >= l && k / i <= r) qrys.push_back(k / i);
                if (i >= l && i <= r) qrys.push_back(i);
            }
        }
        for (auto p : qrys) {
            auto c = a;
            for (auto &x : c) x %= p;
            sort(c.begin(), c.end());
            bool fg = 0;
            for (int i = 0; i < n; i++) if (b[i] != c[i]) {fg = 1; break;}
            if (fg) continue;
            cout << p << "\n";
            return;
        }
        cout << "-1\n";
 
        
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        for (int i = 1; i <= T; i++) {
            sol(i);
        }
    }
}
#undef int
 
int main() {
    return Xbbbz::main(), 0;
}
