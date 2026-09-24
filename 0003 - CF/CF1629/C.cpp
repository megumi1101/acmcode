#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
 
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1), mex(n + 1);
        vector<int> vis(n + 1);
        int me = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = n; i >= 1; i--) {
            vis[a[i]] = 1;
            while (vis[me]) me++;
            mex[i] = me;
        }
        int l = 1;
        vector<int> ans;
        fill(vis.begin(), vis.end(), 0);
        while (l <= n) {
            int x = mex[l];
            ans.push_back(x);
            int r = l - 1;
            me = 0;
            while (me != x) {
                r++;
                vis[a[r]] = 1;
                while (vis[me]) me++;
            }
            for (int i = l; i <= r; i++) {
                vis[a[i]] = 0;
            }
            if (x == 0) r++;
            l = r + 1;
        }
        cout << ans.size() << "\n";
        for (auto x:  ans) cout << x << " ";
        cout << "\n";
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
    return Xbbbz::main(), 0;
}
