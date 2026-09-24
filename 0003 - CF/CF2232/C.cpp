#include <bits/stdc++.h>

#define int long long

using namespace std;

void sol() {
    int n, x, m;
    cin >> n >> x >> m;
    string s;
    cin >> s;

    int totA = 0;
    for (char c : s) {
        if (c == 'A') totA++;
    }

    auto calc = [&](int k) -> int {
        int tab = 0;
        int emp = 0;
        int ans = 0;
        int cntA = 0;
        for (char c : s) {
            char now = c;
            if (c == 'A') {
                cntA++;
                if (cntA <= k) now = 'I';
                else now = 'E';
            }
            if (now == 'I') {
                if (tab < x) {
                    tab++;
                    ans++;
                    emp += m - 1;
                }
            } else {
                if (emp > 0) {
                    emp--;
                    ans++;
                }
            }
        }
        return ans;
    };

    int l = 0, r = totA - 1;
    int pos = totA;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (calc(mid) <= calc(mid + 1)) {
            l = mid + 1;
        } else {
            pos = mid;
            r = mid - 1;
        }
    }

    int ans = calc(pos);
    for (int k = max(0LL, pos - 3); k <= min(totA, pos + 3); k++) {
        ans = max(ans, calc(k));
    }
    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}