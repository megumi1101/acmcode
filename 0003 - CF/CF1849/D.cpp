#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        vector<int> b;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                if (cnt2) {
                    b.push_back(2);
                    cnt2 = 0;
                    cnt1 = 0;
                    b.push_back(0);
                    cnt0++;
                } else if (cnt1) {
                    cnt1 = 0;
                    b.push_back(1);
                    b.push_back(0);
                    cnt0++;
                } else {
                    if (cnt0 < 2) {
                        b.push_back(0);
                        cnt0++;
                    } else {
                        ans++;
                    }
                }
            } else if (a[i] == 1) {
                cnt0 = 0;
                cnt1 = 1;
            } else {
                cnt0 = 0;
                cnt2 = 1;
            }
        }
        
        if (cnt1 || cnt2) b.push_back(1);
            
        vector<int> vis(n + 1);
        for (int i = 0; i < b.size(); i++) {
            if (b[i] == 1) {
                vis[i] = 1;
                ans++;
                if (i - 1 < 0 || vis[i - 1] == 1) vis[i + 1] = 1;
                else vis[i - 1] = 1;
            } else if (b[i] == 2) {
                vis[i] = 1;
                ans++;
                if (i - 1 >= 0) vis[i - 1] = 1;
                if (i + 1 < b.size()) vis[i + 1] = 1;
            }
        }
        
        // for (auto x : b) cerr << x << " ";
        cerr << "\n";
        for (int i = 0; i < b.size(); i++) {
            if (vis[i] == 0) ans++;
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
