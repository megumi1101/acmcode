// QOJ user: xbbbz
// Contest: 2023 Á¨?8Â±äICPCÊµéÂçóÁ´?// Problem: #7897. Largest Digit (7897)
// Submission: https://qoj.ac/submission/1453369
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
    void sol() {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int x = l1 + l2;
        int y = r1 + r2;
        int tx = x, ty = y;
        int res = 0;
        while (tx) {
            res = max(res, tx % 10);
            tx /= 10;
        }
        while (ty) {
            res = max(res, ty % 10);
            ty /= 10;
        }
        int z = x % 10;
        int now = 0;
        while (z < 9) {
            now++;
            z++;
            if (x + now > y) break;
            res = max(res, z);
        }
        cout << res << "\n";
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
3 3
1 1 1
*/
</code>