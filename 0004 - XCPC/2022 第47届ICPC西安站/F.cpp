// QOJ user: lnxbb
// Contest: 2022 ç¬?7å±ŠICPCè¥¿å®‰ç«?// Problem: #5118. Hotel (5118)
// Submission: https://qoj.ac/submission/1659552
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
const int inf = 1e9;
    void sol() {
        int n, m, k;
        cin >> n >> m >> k;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            int res = inf;
            sort(s.begin(), s.end());
            
            res = min(res, 3 * m);
            if (s[0] == s[1] || s[1] == s[2]) res = min({res, m + k, 2 * k});
            res = min(res, 3 * k);
            ans += res;
        }
        cout << ans;
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}
</code>