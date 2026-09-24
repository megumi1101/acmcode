#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e9;


void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int alld = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        alld = gcd(alld, a[i]);
    }

    for (int i = 1; i <= n; i++) {
        a[i] /= alld;
    }

    auto check = [&](int p) -> bool {
        vector<int> c;
        c.push_back(0);
        for (int i = 1; i <= n; i++) {
            if (a[i] % p != 0) {
                c.push_back(a[i]);
            }
        }

        int n = (int)c.size() - 1;
        vector<int> pre(n + 5), suf(n + 5);
        for (int i = 1; i <= n; i++) {
            pre[i] = gcd(c[i], pre[i - 1]);
        }
        for (int i = n; i >= 1; i--) {
            suf[i] = gcd(c[i], suf[i + 1]);
        }
        
        for (int i = 1; i <= n; i++) {
            if (gcd(pre[i - 1], suf[i + 1]) != 1) {
                return 1;
            }
        }
        return 0;
    };

    auto get = [&](int x) -> bool {
        vector<int> prs;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                prs.push_back(i);
                while (x % i == 0) x /= i;
            }
        }
        if (x > 1) prs.push_back(x);

        for (auto x : prs) {
            if (check(x)) {
                return 1;
            }
        }
        return 0;
    };

    if (get(a[1]) || get(a[2])) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}