#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<char> ed[k + 5];
        for (int i = 0; i < k + 5; i++)ed[i].clear();
        int vis[26];
        if (k & 1) {
            for (int i = 0; i < n; i++) {
                ed[abs(i % k - k / 2)].push_back(s[i]);
            }
        }
        else {
            for (int i = 0; i < k / 2; i++) {
                for (int j = i; j < n; j += k) {
                    ed[i].push_back(s[j]);
                }
                for (int j = k - i - 1; j < n; j += k) {
                    ed[i].push_back(s[j]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= k / 2; i++) {
            int res = 0;
            memset(vis, 0, sizeof(vis));
            for (char c : ed[i]) {
                vis[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                res = max (res, vis[i]);
            }
            ans += res;
        }
        ans = n - ans;
        cout << ans << "\n";
    }
    void main () {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while(T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
/*
1
8 4
abbbabba
*/
