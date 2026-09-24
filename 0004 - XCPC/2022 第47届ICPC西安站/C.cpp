// QOJ user: lnxbb
// Contest: 2022 ç¬?7å±ŠICPCè¥¿å®‰ç«?// Problem: #5115. Clone Ranran (5115)
// Submission: https://qoj.ac/submission/1659661
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 2e18;
    void sol() {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = inf;
        for (int i = 0; i <= 30; i++) {
            int x = 1 << i;
            ans = min(ans, ((c - 1) / x + 1) * b + i * a);
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
    return Xbbbz::main(),0;
}
</code>