#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == s[i + 1]) cnt++;
    }
    if (cnt <= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
6
0 0
3 0
6 0
6 3
6 6
1 1
*/
