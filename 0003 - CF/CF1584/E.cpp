#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    map<int, int> mp0, mp1;
    void sol() {
        mp0.clear();
        mp1.clear();
        int n;
        cin >> n;
        int a[n + 5];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        mp0[0] = 1;
        int res = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int op = (i & 1);
            res = -res + a[i];
            if (op) {
                ans += mp1[res];
                ans += mp0[-res];
            }
            else {
                ans += mp1[-res];
                ans += mp0[res];
            }
            if (op) {
                while (mp1.size()) {
                    auto it = mp1.end();
                    it = prev(it);
                    if (it->first > res) {
                        mp1.erase(it);
                    }
                    else break;
                }
                while (mp0.size()) {
                    auto it = mp0.begin();
                    if (it->first < -res) {
                        mp0.erase(it);
                    }
                    else break;
                }    
            }
            else {
                while (mp0.size()) {
                    auto it = mp0.end();
                    it = prev(it);
                    if (it->first > res) {
                        mp0.erase(it);
                    }
                    else break;
                }
                while (mp1.size()) {
                    auto it = mp1.begin();
                    if (it->first < -res) {
                        mp1.erase(it);
                    }
                    else break;
                }   
            }
            if (op) mp1[res]++;
            else mp0[res]++;
            // cout <<  res << " res \n";
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) sol();
    }   
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}
/*
1 3
5 4 3
*/
