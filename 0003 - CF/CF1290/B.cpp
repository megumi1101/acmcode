#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 2e5 + 10;
    const int inf = 1e18;
    void sol () {
        string s;
        cin >> s;
        int n = s.size();
        s = " " + s;
        vector<vector<int>> cnt(n + 5, vector<int> (26, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                cnt[i][j] = cnt[i - 1][j] + (s[i] - 'a' == j);
            }
        }
        int m;
        cin >> m;
        while (m--) {
            int l, r;
            cin >> l >> r;
            int res = 0;
            for (int j = 0; j < 26; j++) {
                if (cnt[r][j] - cnt[l - 1][j] > 0) res++;
            }
            if (res > 2) {
                cout << "Yes\n";
                continue;
            }
            if (l == r){
                cout << "Yes\n";
                continue;
            } 
            if (s[l] != s[r]) {
                cout << "Yes\n";
                continue;
            }
            cout << "No\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
