#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
void sol() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> all;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
            all.push_back(x);
        }
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (auto &v : a) {
        for (auto &x : v) {
            x = lower_bound(all.begin(), all.end(), x) - all.begin();
        }
    }
 
    vector<int> vis(n + 1);
    vector<int> inq(all.size() + 5);
    vector<int> ans;
    const int inf = 1e9;
    for (int t = 0; t < n; t++) {
        vector<int> mn{inf};
        for (int i = 0; i < n; i++) {            
            vector<int> tmp;
            set<int> s;
            for (int j = a[i].size() - 1; j >= 0; j--) {
                if (inq[a[i][j]]) continue;
                if (s.find(a[i][j]) != s.end()) continue;
                tmp.push_back(a[i][j]);
                s.insert(a[i][j]);
                
            }
            if (tmp.empty()) continue;
            {
                int fg = 0;
                for (int i = 0; i < mn.size() && i < tmp.size(); i++) {
                    if (tmp[i] < mn[i]) {
                        fg = 1;
                        break;
                    } else if (tmp[i] > mn[i]) {
                        fg = -1;
                        break;
                    }
                }
                
                if (fg == 0 && tmp.size() < mn.size()) fg = 1;
                if (fg == 1) mn = tmp;
            }
           
        }
        
        if (mn[0] == inf) continue;
        for (auto x : mn) inq[x] = 1, ans.push_back(x);
    }
    for (auto x : ans) cout << all[x] << " ";
    cout << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
