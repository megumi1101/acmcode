#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    string s;
    cin >> n >> s;
    int t = 0;
    for (auto c : s) {
        if (c == '(') t++;
        else t--;
    }
 
    if (t) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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
