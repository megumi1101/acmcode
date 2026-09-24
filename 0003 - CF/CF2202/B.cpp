#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
void sol() {
    int n;
    string s;
    cin >> n >> s;
    if (n & 1) {
        if (s[0] == 'b') {
            cout << "NO\n";
            return;
        }
    }
 
    for (int i = n - 1; i >= 1; i -= 2) {
        if ((s[i] == 'a' && s[i - 1] == 'a') || (s[i] == 'b' && s[i - 1] == 'b')) {
            cout << "NO\n";
            return;
        } 
    }
    cout << "YES\n";
 
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
