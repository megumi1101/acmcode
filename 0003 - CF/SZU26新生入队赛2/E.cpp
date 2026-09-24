#include <bits/stdc++.h>

using namespace std;

#define int long long

mt19937_64 rng(random_device{}());
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    auto ask = [&](int l, int r) -> bool {
        cout << l << " " << r << endl;
        string s;
        cin >> s;
        if (s == "Yes") return 1;
        else return 0;
    };

    int l = 1, r = n;
    while (1) {
        if (r - l + 1 <= 6 * k) {
            int siz = r - l + 1;
            int t = rng() % siz;
            if (ask(l + t, l + t)) {
                return 0;
            }
        } else {
            int mid = (l + r) / 2;
            if (ask(l, mid)) {
                if (l == mid) {
                    return 0;
                }
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l = max(1LL, l - k);
        r = min(n, r + k);
    }
}