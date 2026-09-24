#include <bits/stdc++.h>
 
using namespace std;
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        int n, k;
        cin >> n >> k;
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            ++cnt[val];
        }
        int ans = 0;
        auto itl = cnt.begin();
        while (itl != cnt.end()) {
            if (itl->second <= k) {
                ++itl;
                continue;
            }
            int L = itl->first;      
            int tot = itl->second;   
            auto itr = itl;
            ++itr;
            if (itr != cnt.end() && itr->first - L - 1 + k < tot) {
                while (itr != cnt.end() && itr->first - L - 1 + k < tot) {
                    tot += itr->second;
                    ++itr;
                }
                ans = max(ans, tot - k);
                itl = itr;  
            }
            else {
                ans = max(ans, tot - k);
                ++itl;
            }
        }
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
