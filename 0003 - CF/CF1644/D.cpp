#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
 
    int fap(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            b >>= 1; 
            a = a * a % mod;
        }
        return res;
    }
 
    void sol() {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        vector<int> qx(q + 1), qy(q + 1);
        for (int i = 1; i <= q; i++) {
            cin >> qx[i] >> qy[i];
        }
 
        int ty = 1, ct = 0;
        set<int> vis; 
        for (int i = q; i >= 1; i--) {
            if (!vis.count(qx[i])) {
                vis.insert(qx[i]);
                ct++;
            }
            if (ct == n) {
                ty = i;
                break;
            }
        }
 
        int tx = 1; ct = 0;
        vis.clear();
        for (int i = q; i >= 1; i--) {
            if (!vis.count(qy[i])) {
                vis.insert(qy[i]);
                ct++;
            }
            if (ct == m) {
                tx = i;
                break;
            }
        }
 
        set<int> visx, visy;
        map<int,int> lst;
 
        for (int i = tx; i <= q; i++) visx.insert(i);
        for (int i = ty; i <= q; i++) visy.insert(i);
 
        lst.clear();
        for (int i = 1; i <= q; i++) {
            if (lst.count(qx[i])) visx.erase(lst[qx[i]]);
            lst[qx[i]] = i;
        }
 
        lst.clear();
        for (int i = 1; i <= q; i++) {
            if (lst.count(qy[i])) visy.erase(lst[qy[i]]);
            lst[qy[i]] = i;
        }
 
        ct = 0;
        for (int i = 1; i <= q; i++) {
            if (visx.count(i) || visy.count(i)) ct++;
        }
 
        cout << fap(k, ct) << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T; cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
