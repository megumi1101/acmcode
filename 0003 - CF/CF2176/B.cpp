#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9;
void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += s;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '0') cnt++;
        else {ans = max(ans, cnt);
            cnt = 0;
            
        }
    }
 
    ans = max(ans, cnt);
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
 
    int T;
    cin >> T;
    while (T--) {
        sol();
    }
    
}
