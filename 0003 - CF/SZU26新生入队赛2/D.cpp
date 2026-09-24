#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

vector<int> pr, minp;
void init(int n) {
    minp.assign(n + 5, 0);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) pr.push_back(i), minp[i] = i;
        for (int j : pr) {
            int m = i * j;
            if (m > n) break;
            minp[m] = j;
            if (i % j == 0) {
                break;
            }
        }
    }
}

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 1;

    auto get = [](int x, int up) {
        int res = 0;

        int t = x;
        vector<int> p;
        for (auto x : pr) {
            if (x * x > t) break;
            if (t % x == 0) {
                p.push_back(x);
            }
            while (t % x == 0) t /= x;
        }
        if (t != 1) p.push_back(t);

        int siz = p.size();
        for (int i = 0; i < (1 << siz); i++) {
            int tmp = 1;
            for (int bit = 0; bit < siz; bit++) {
                if (i >> bit & 1) tmp *= p[bit];
            }
            if (popcount((unsigned int)i) & 1) {
                res -= up / tmp;    
            } else {
                res += up / tmp;
            }
        }
        
        return res;
    };

    for (int i = 2; i <= n; i++) {
        int x = a[i - 1], d = a[i];
        if (x % d) {
            cout << "0\n";
            return;
        }
        x /= d;
        int up = m / d;
        ans = ans * get(x, up) % mod;
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init(1e6);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}