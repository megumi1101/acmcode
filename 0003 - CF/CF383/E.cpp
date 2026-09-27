#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, inf = 1e9;

signed main() {
    int n;
    cin >> n;

    int sz = 24;
    vector<int> cnt(1 << sz);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int res = 0;
        for (int j = 0; j < 3; j++) {
            res |= (1 << (s[j] - 'a'));
        }
        cnt[res]++;
    }

    for (int bit = 0; bit < sz; bit++) {
        for (int i = 0; i < (1 << sz); i++) {
            if ((i >> bit) & 1) {
                cnt[i] += cnt[i ^ (1 << bit)];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << sz); i++) {
        ans ^= (n - cnt[i]) * (n - cnt[i]);
    }
    cout << ans << "\n";
}