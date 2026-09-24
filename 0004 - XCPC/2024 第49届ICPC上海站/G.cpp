// QOJ user: xbbbz
// Contest: 2024 ç¬?9å±ŠICPCä¸Šæµ·ç«?// Problem: #9043. Geometry Task (9043)
// Submission: https://qoj.ac/submission/1540521
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 2e18;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        for (auto &i : c) cin >> i;

        sort(c.begin(), c.end());

        auto isok = [&](int mid) -> bool {
            vector<int> sml, big;
            sml.reserve(n), big.reserve(n);
            for (int i = 0; i < n; i++) {
                int x = mid - b[i];
                int y = a[i];
                if (y == 0) {
                    if (x <= 0) sml.push_back(inf);
                } else if (x == 0) {
                    if (y >= 0) big.push_back(0);    
                    if (y < 0) sml.push_back(0);    
                } 
                else if (x > 0 && y > 0) {
                    big.push_back((x - 1) / y + 1);
                } else if (x < 0 && y > 0) {
                    big.push_back(x / y);
                } else if (x > 0 && y < 0) {
                    sml.push_back(-((x - 1) / -y + 1));
                } else if (x < 0 && y < 0) {
                    sml.push_back(x / y);
                }
            } 
            sort(sml.begin(), sml.end());
            sort(big.begin(), big.end(), [&](int i, int j){return i > j;});

            int posl = -1;
            int posr = n;
            for (auto &y : sml) {
                if (y >= c[posl + 1]) posl++;
            }
            for (auto &y : big) {
                if (y <= c[posr - 1]) posr--;
            }
            int cnt = posl + 1 + n - posr;
            return cnt >= (n + 1) / 2;
        };

        int l = -2e18, r = 2e18, ans = -2e18;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (isok(mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        cout << ans << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
/*
3
5
0 5 -2 1 2
9 -4 0 10 5
-4 -1 4 -2 4
10
-6 3 1 0 6 -2 -4 3 0 10
22 65 11 1 -34 -1 -39 -28 25 24
10 9 1 -2 -5 8 -7 -10 -7 -7
1
101
48763
651
*/
</code>