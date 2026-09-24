// QOJ user: xbbbz
// Contest: 2022 Á¨?7Â±äICPCÊù≠Â∑ûÁ´?// Problem: #5303. No Bug No Game (5303)
// Submission: https://qoj.ac/submission/1450077
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 1e18;
    void sol() {
        int n, k;
        cin >> n >> k;
        vector<array<int, 2>> f(k + 5, {-inf, -inf});
        vector<array<int, 2>> nf(k + 5, {-inf, -inf});
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            nf = f;
            int p;
            cin >> p;
            int x;
            for (int j = 1; j < p; j++) {
                cin >> x;
                for (int s = k; s >= j; s--) {
                    nf[s][1] = max(nf[s][1], f[s - j][0] + x);
                }
            }
            cin >> x;
            for (int s = k; s >= p; s--) {
                nf[s][0] = max(nf[s][0], f[s - p][0] + x);
                nf[s][1] = max(nf[s][1], f[s - p][1] + x);
            }
            f = nf;
        }
        for (int i = 0; i <= k; i++) {
            f[k][0] = max(f[k][0], f[i][0]);
        }
        cout << max(f[k][0], f[k][1]) << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
/*
4 5
2 1 3
2 1 1
2 3 1
2 1 3
*/
</code>