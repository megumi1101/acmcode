#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
void sol() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a;
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] - '0';
        if (i == 0) {
            a.push_back(s[i] - '1');
        } else {
            a.push_back(s[i] - '0');
        }
    }
    
    int ans = 0;
    sort(a.rbegin(), a.rend());
    for (auto x : a) {
        if (sum <= 9) break;
        sum -= x;
        ans++;
    }
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
