#include <bits/stdc++.h>
 
using namespace std;
 
 
void sol() {
    int n;
    cin >> n;
    vector<vector<int>> ed(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
 
    vector<int> p;
    string s;
    cin >> s;
    s = " " + s;
    int cnt3 = 0;
    for (int i = 2; i <= n; i++) {
        if (ed[i].size() == 1) p.push_back(i);
        else if (s[i] == '?') cnt3++;
    }
    
    
    int op = 0;
    int ans = 0;
    if (s[1] != '?') {
        for (auto x : p) {
            if (s[x] == '?') {
                if (op == 0) ans++;
                op ^= 1;
            }
            else if (s[x] != s[1]) ans++;
            
        }
    } else {
        op = 1;
        int cnt = 0;
        int cnt2 = 0;
        for (auto x : p) {
            if (s[x] == '0') cnt++;
            else if (s[x] == '1') ans++;
            else cnt2++;
        }
        
        if (ans == cnt) {
            ans += (cnt2 + (cnt3 % 2)) / 2;
        }
        else {
            ans = max(ans, cnt);
            ans += cnt2 / 2;
        }
    }
 
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
