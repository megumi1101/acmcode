#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
int LNDS(const vector<int>& a){
    vector<int> tails; 
    for(int x : a){
        auto it = upper_bound(tails.begin(), tails.end(), x); 
        if(it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return (int)tails.size();
}
const int inf = 1e18;
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x, x--;
        b.push_back(n);
        a.push_back(inf);
        auto sol = [&](int l, int r, int dn, int up) -> int {
            if (up < dn) return -1;
            vector<int> c;
            for (int i = l; i <= r; i++) a[i] -= (i - l) + 1;
            for (int i = l; i <= r; i++) if (a[i] >= dn && a[i] <= up) c.push_back(a[i]);
            return (r - l + 1) - LNDS(c);
        };
 
        int lst = -1;
        int ans = 0;
        for (auto &x : b) {
            // cerr << "-1\n";
            int l = lst + 1;
            int r = x - 1;
            int dn, up;
            if (l == 0) dn = -inf;
            else dn = a[lst];
            up = a[x] - (x - lst);
            
            // cerr << l << " " << r << " " << dn << " " << up << "\n";
            int tmp = sol(l, r, dn, up);
            if (tmp == -1) {
                cout << "-1\n";
                return;
            }
            ans += tmp;
            // cerr << tmp << "\n";
            lst = x;
        }
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
 
#undef int
int main() {
    return Xbbbz::main(), 0;
}
