#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7, inf = 1e9;

int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main() {
    int n;
    cin >> n;

    int sz = 20;
    vector<int> cnt(1 << sz);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int bit = 0; bit < sz; bit++) {
        for (int i = 0; i < (1 << sz); i++) {
            if (((i >> bit) & 1) == 0) {
                cnt[i] += cnt[i ^ (1 << bit)];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << sz); i++) {
        if (popcount((unsigned long long)i) & 1) {
            ans -= fap(2, cnt[i]) - 1;
        } else {
            ans += fap(2, cnt[i]) - 1;
        }
        ans %= mod;
        if (ans < 0) ans += mod;
    }
    cout << ans << "\n";
}