#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n;
    string s;
    cin >> n >> s;
 
    string t = s;
    for (int i = 1; i + 1 < n; i++) {
        if (s[i - 1] == s[i + 1] && s[i - 1] == '1') {
            s[i] = '1';
        }
    }
    int cnt = 0;
    for (auto c : s) if (c == '1') cnt++;
 
    for (int i = 1; i + 1 < n; i++) {
        if (s[i - 1] == s[i + 1] && s[i - 1] == '1') {
            s[i] = '0';
        }
    }
    int res = 0;
    for (auto c : s) if (c == '1') res++;
 
    cout << res << " " << cnt << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
