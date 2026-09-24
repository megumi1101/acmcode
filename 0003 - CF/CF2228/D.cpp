#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<pair<int, int>> prs(n);
    vector<int> px(n + 5);
    vector<int> allx;
    vector<int> ally;
    for (auto& [x, y] : prs) {
        cin >> x >> y;
        allx.push_back(x);
        ally.push_back(y);
    }
    sort(allx.begin(), allx.end());
    sort(ally.begin(), ally.end());
    allx.erase(unique(allx.begin(), allx.end()), allx.end());
    ally.erase(unique(ally.begin(), ally.end()), ally.end());
 
    sort(prs.begin(), prs.end());
    
    int siz = allx.size();
    vector<int> premn(n + 5, 1e9), premx(n + 5), sufmx(n + 5), sufmn(n + 5 ,1e9);
    for (auto &[x, y] : prs) {
        x = lower_bound(allx.begin(), allx.end(), x) - allx.begin() + 1;
        y = lower_bound(ally.begin(), ally.end(), y) - ally.begin() + 1;
        premn[x] = min(premn[x], y);
        premx[x] = max(premx[x], y);
        sufmn[x] = min(sufmn[x], y);
        sufmx[x] = max(sufmx[x], y);
    }
 
    long long ans = 0;
    
    for (int i = 1; i <= siz; i++) {
        premn[i] = min(premn[i - 1], premn[i]);
        premx[i] = max(premx[i - 1], premx[i]);
    }
    for (int i = siz; i >= 1; i--) {
        sufmn[i] = min(sufmn[i + 1], sufmn[i]);
        sufmx[i] = max(sufmx[i + 1], sufmx[i]);
    }
 
 
    for (int i = 1; i < siz; i++) {
        int l = max(sufmn[i + 1], premn[i]);
        int r = min(sufmx[i + 1], premx[i]);
        if (l < r) {
            ans += r - l;
        }
    }
 
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
/*
1
4
1 4
4 1
1 1
4 4
*/
