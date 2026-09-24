#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n;
    string s;
    cin >> n >> s;
    int pos = 0;
    vector<int> vis(n);
    vis[0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[pos] == 'L') {
            pos--;
        } else {
            pos++;
        }
        vis[pos] = 1;
    }
    int cnt = 0;
    for (auto x : vis) if (x) cnt++;
    cout << cnt << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
