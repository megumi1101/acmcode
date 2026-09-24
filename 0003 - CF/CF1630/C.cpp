#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1), fst(n + 1), lst(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (fst[a[i]]) lst[a[i]] = i;
            else fst[a[i]] = i;
        }
        
        vector<pair<int, int>> eg, dg;
        for (int i = 1; i <= n; i++) {
            if (fst[i] && lst[i]) {
                eg.emplace_back(fst[i], lst[i]);
            }
        }
 
        sort(eg.begin(), eg.end());
 
        for (int i = 0; i < eg.size(); i++) {
            int nxt = i + 1;
            while (nxt < eg.size() && eg[nxt].second <= eg[i].second) nxt++;
            dg.push_back(eg[i]);
            i = nxt - 1;
        }
        int l = -1, r = -1;
        int res = 0;
        int ans = 0;
 
        for (int i = 0; i < dg.size(); i++) {
            int nxt = i + 1;
            l = dg[i].first, r = dg[i].second;
            while (nxt < dg.size() && dg[nxt].first < r) {
                while (nxt < dg.size() && dg[nxt].first < r) nxt++;
                i = nxt - 1;
                r = dg[i].second;
                res++;
            }
            ans += r - l - 1;
        }
        
        cout << ans - res;
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz :: main(), 0;
}
