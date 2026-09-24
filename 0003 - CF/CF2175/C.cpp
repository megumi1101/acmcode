#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
    void sol() {
        string s, t;
        cin >> s >> t;
        vector<int> vis(26);
        for (auto c : t) vis[c - 'a']++;
        for (auto c : s) vis[c - 'a']--;
 
 
        string ans;
        vector<char> a;
        for (int i = 0; i < 26; i++) {
            if (vis[i] < 0) {
                cout << "Impossible\n";
                return;
            }
            for (int j = 0; j < vis[i]; j++)
                a.push_back(i + 'a');
        }
        
        int l = 0;
        int r = 0;
        while (l < a.size() && r < s.size()) {
            if (s[r] <= a[l]) {
                ans += s[r];
                r++;
            } else {
                ans += a[l];
                l++;
            }
        }
 
        while (l < a.size()) {
            ans += a[l];
            l++;
        }
 
        while (r < s.size()) {
            ans += s[r];
            r++;
        }
 
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
 
int main() {
    return Xbbbz::main(), 0;
}
