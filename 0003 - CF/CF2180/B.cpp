#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e9;
void sol() {
    int n;
    cin >> n;
    string ans;
    cin >> ans;
    for (int i = 1; i < n; i++) {
        string s;
        cin >> s;
        if (ans + s < s + ans) {
            ans = ans + s;
        } else {
            ans = s + ans;
        }
    }
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
 
    int T;
    cin >> T;
    while (T--) {
        sol();
    }
    
}
