#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

int fap(int a, int b) { 
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return fap(x, mod - 2);
}

void norm(int &x) {
    x %= mod;
    if (x < mod) x += mod;
}
signed main() {
    int m;
    cin >> m;
    vector<int> s(m);
    for (auto &i : s) cin >> i;
    sort(s.rbegin(), s.rend());

    s.push_back(0);
    vector<int> suf(m + 1);
    suf[m] = 1;
    for (int i = m - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] * s[i] % mod;
    }

    int ans = 0;
    for (int i = 1; i < m; i++) {
        if (s[i + 1] == s[i]) continue;
        int coef = (i + 1) / 2;
        coef = coef * inv(i) % mod;
        int t = fap(s[i], i) - fap(s[i + 1], i);
        norm(t);
        t = t * suf[i + 1] % mod;
        t = t * coef % mod;
        ans = (ans + t) % mod;
    }

    cout << ans << "\n";
}