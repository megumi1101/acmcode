// QOJ user: xbbbz
// Contest: 2022 ç¬?7å±ŠICPCæ­å·ç«?// Problem: #5301. Modulo Ruins the Legend (5301)
// Submission: https://qoj.ac/submission/1447377
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
    void sol() {
        int n, m;
        cin >> n >> m;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            sum += x;
        }
        sum %= m;
        auto get = [&](auto &&get, int x, int y, int dis) -> int {
            x %= y;
            if (x == 0) x = y;
            int now = 0;
            if (dis % x == 0) {
                return dis / x;
            }
            int t = y / x;
            int tt = t * x;
            if (dis > tt) return t + get(get, x, y, dis - tt);
            else return t + get(get, x, y, y + dis - tt);
        };

        if (n & 1) {
            int d = gcd(n, m);
            int k = (m - sum) / d;
            int tsum = sum + k * d;
            if (tsum != m) tsum += d;
            int ans = tsum - m;

            int dis = m + ans - sum;
            dis %= m;
            cerr << m << " " << ans << " " <<  sum << "\n";
            cout << ans << "\n";
            cout << get(get, n, m, dis) << " 0"  << "\n";
        } else {
            int d = gcd(n / 2, m);
            int k = (m - sum) / d;
            int tsum = sum + k * d;
            if (tsum != m) tsum += d;
            int ans = tsum - m;

            int dis = m + ans - sum;
            dis %= m;
            int tmp = get(get, n / 2, m, dis);
            cout << ans << "\n";
            if (tmp & 1) {
                int k = (n + 1) % (m / d);
                if (tmp < k) tmp += m / d;
                if (tmp & 1) {
                    tmp -= k;
                    cout << tmp / 2 << " 1" << "\n";
                } else {
                    cout  << tmp / 2 << " 0" << "\n";
                }
                
            } else {
                cout  << tmp / 2 << " 0" << "\n";
            }
        }
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
3 3
1 1 1
*/
</code>