// AtCoder user: lnxbb
// Contest: agc004
// Problem: agc004_e
// Submission: https://atcoder.jp/contests/agc004/submissions/75606199
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    int n, m;
    cin >> n >> m;
    vector<string> s(n + 1);
    vector pre(n + 1, vector(m + 1, 0));

    int posi = -1, posj = -1;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'o') {
                pre[i][j] = 1;
            }
            pre[i][j] += pre[i][j - 1];
            pre[i][j] += pre[i - 1][j];
            pre[i][j] -= pre[i - 1][j - 1];
            if (s[i][j] == 'E') {
                posi = i;
                posj = j;
            }
        }
    }

    auto get = [&](int lx, int rx, int ly, int ry) -> int {
        if (lx > rx || ly > ry) return 0;
        return pre[rx][ry] - pre[lx - 1][ry] - pre[rx][ly - 1] + pre[lx - 1][ly - 1];
    };
    
    int ans = 0;
    short f[105][105][105][105];
    for (int upi = 0; upi <= n; upi++) {
        for (int dni = n + 1; dni > upi; dni--) {
            for (int upj = 0; upj <= m; upj++) {
                for (int dnj = m + 1; dnj > upj; dnj--) {
                    if (upi + 1 <= n && upi + 1 < dni) {
                        int res = 0;
                        if (posi + upi + 1 < dni) res = get(posi + upi + 1, posi + upi + 1, max(upj + 1, posj + dnj - m - 1), min(dnj - 1, posj + upj));
                        f[upi + 1][dni][upj][dnj] = max(f[upi + 1][dni][upj][dnj], short(f[upi][dni][upj][dnj] + res));
                    }

                    if (upj + 1 <= m && upj + 1 < dnj) {
                        int res = 0;
                        if (posj + upj + 1 < dnj) res = get(max(upi + 1, posi + dni - n - 1), min(dni - 1, posi + upi), posj + upj + 1, posj + upj + 1);
                        f[upi][dni][upj + 1][dnj] = max(f[upi][dni][upj + 1][dnj], short(f[upi][dni][upj][dnj] + res));
                    }

                    if (dni - 1 >= 0 && upi + 1 < dni) {
                        int res = 0;
                        if (posi + dni - n - 2 > upi) res = get(posi + dni - n - 2, posi + dni - n - 2, max(upj + 1, posj + dnj - m - 1), min(dnj - 1, posj + upj));
                        f[upi][dni - 1][upj][dnj] = max(f[upi][dni - 1][upj][dnj], short(f[upi][dni][upj][dnj] + res));
                    }

                    if (dnj - 1 >= 0 && upj + 1 < dnj) {
                        int res = 0;
                        if (posj + dnj - m - 2 > upj) res = get(max(upi + 1, posi + dni - n - 1), min(dni - 1, posi + upi), posj + dnj - m - 2, posj + dnj - m - 2);
                        f[upi][dni][upj][dnj - 1] = max(f[upi][dni][upj][dnj - 1], short(f[upi][dni][upj][dnj] + res));

                    }
                    ans = max(ans, (int)f[upi][dni][upj][dnj]);
                }
            }
        }
    }
    cout << ans << "\n";

}

/*
6
0 0
3 0
6 0
6 3
6 6
1 1
*/