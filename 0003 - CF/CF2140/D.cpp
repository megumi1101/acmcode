#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int n; 
        cin >> n;
        vector<pair<int,int> > a(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int l, r; 
            cin >> l >> r;
            a[i] = {l, r};
            ans += (2 * r - l);
        }
        
        sort(a.begin(), a.end(), [&](auto i, auto j) {return i.first + i.second < j.first + j.second; });
        if (n & 1) {
            int res = -a[n / 2].second;
            for (int i = 0; i < n / 2; i++) res -= a[i].first + a[i].second;
            int mn = res;
            for (int i = 0; i < n / 2; i++) {
                mn = max(mn, res - a[n / 2].first + a[i].first);
            }
            for (int i = n / 2 + 1; i < n; i++) {
                mn = max(mn, res + a[n / 2].second - a[i].second);
            }
            ans = ans + mn;
        }
        else {
            for (int i = 0; i < n / 2; i++) ans -= a[i].first + a[i].second;
        }
 
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz :: main(), 0;
}
