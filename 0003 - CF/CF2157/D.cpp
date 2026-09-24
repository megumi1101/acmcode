#include <bits/stdc++.h>
 
using namespace std;
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        sort(a.begin(), a.end());
            int tl = 0;
            int cntl = 0;
            while (l > a[tl] && tl < n) tl++, cntl++;
 
            int tr = n - 1;
            int cntr = 0;
            while (r < a[tr] && tr >= 0) tr--, cntr++;
            // cerr << cntl << " " << cntr << "\n";
            if (cntl > n / 2) {
                cntr = n - cntl;
            } 
            if (cntr > n / 2) {
                cntl = n - cntr;
            }
            if (cntl <= n / 2 && cntr <= n / 2) {
                cntl = cntr = n / 2;
            }
            // cerr << cntl << " " << cntr << "\n";
            int sum = 0;
            for (int i = 0; i < cntl; i++) sum -= a[i];
            for (int i = n - 1; i >= n - cntr; i--) sum += a[i]; 
            int k = cntl - cntr;
            int ans = min(k * l + sum, k * r + sum);
        cout << ans << "\n";
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
