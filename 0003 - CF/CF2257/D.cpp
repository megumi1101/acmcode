#include <bits/stdc++.h>

using namespace std;

#define int long long
#define debug(x) cerr << #x << " = " << x << '\n'

using i128 = __int128_t;

ostream& operator<<(ostream& os, __int128 x) {
    if (x < 0) os << '-', x = -x;
    if (x >= 10) os << x / 10;
    return os << char('0' + x % 10);
}

const int inf = 1e18;
void sol() {
    int S, q;
    cin >> S >> q;

    vector<int> fac;
    for (int i = 1; i * i <= S; i++) {
        if (S % i == 0) {
            fac.push_back(i);
            if (i * i != S) fac.push_back(S / i);
        }
    }
    sort(fac.begin(), fac.end());
    int siz = fac.size();

    vector<int> L(siz + 1), R(siz + 1), hei(siz + 1);
    vector<i128> pre(siz + 1);
    for (int i = 1; i - 1 < fac.size(); i++) {
        L[i] = R[i - 1] + 1;
        R[i] = fac[i - 1];
        hei[i] = S / fac[i - 1];
        pre[i] = (i128) (R[i] - L[i] + 1) * hei[i] + pre[i - 1];
    }
    
    while (q--) {
        int x, y;
        cin >> x >> y;

        int l = 1, r = siz;
        int pl = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (hei[mid] <= y) {
                pl = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        i128 sum = 0;
        int mn = min(L[pl] - 1, x);
        sum += (i128)mn * y;

        if (L[pl] <= x) {
            int pr = lower_bound(R.begin(), R.end(), x) - R.begin() - 1;
            sum += pre[pr] - pre[pl - 1];
            pr++;
            if (pr <= siz) sum += (i128)(x - L[pr] + 1) * hei[pr];
        }

        cout << sum << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}