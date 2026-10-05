#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    vector<int> stk, L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && a[stk.back()] >= a[i]) {
            L[i] = stk.back();
            stk.pop_back();
        }
        if (!stk.empty()) {
            R[stk.back()] = i; 
        }
        stk.push_back(i);
    }
    int rt = stk[0]; 
    int u = rt;
    if (a[u] != b[1]) {
        cout << "0\n";
        return 0;
    }

    vector<pair<int, int>> p;
    int lst = 0;
    int pos = 2;
    while (u && pos <= m) {
        if (a[u] == b[pos]) {
            pos++;
            p.push_back({lst, u - 1});
        }
        lst = u;
        u = R[u];
    }

    if ((int)p.size() != m - 1) {
        cout << "0\n";
        return 0;
    }

    int ans = 1;
    for (auto [l, r] : p) {
        ans = ans * (r - l + 1) % mod;
    }
    cout << ans << "\n";
}