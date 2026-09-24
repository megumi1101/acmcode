#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;
void sol () {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> vis(2 * n);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < a.size(); i++) {
        int x = 2 * (n - i) - 1;
        if (a[i] > x) {
            cout << "0\n";
            return;
        }
        vis[a[i]] = 1;
    }
    vector<int> f(n + 1);
    f[0] = 1;

    for (int i = 1; i < 2 * n; i++) {
        vector<int> nf(n + 1);
        if (!vis[i]) {
            nf = f;
        }
        for (int j = 0; j < n; j++) {
            (nf[j + 1] += f[j]) %= mod;
        }
        f = move(nf);
        if (i & 1) {
            for (int j = 0; j <= (i - 1) / 2; j++) {
                f[j] = 0;
            }
        }
    }

    cout << f[n] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
}

/*
3
1 1
2
2 1
2
6 3
1 4 5
*/