#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<set<int>> sa(n + 5), sb(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sa[a[i]].insert(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sb[b[i]].insert(i);
    }
    vector<int> f(n + 5, n + 1);
 
    auto nxt = [&](set<int> &s, int pos) {
        auto it = s.upper_bound(pos);
        if (it == s.end()) return n + 1;
        return *it;
    };
 
    auto calc = [&](int pos, int need) {
        if (need > n) return n + 1;
        int na = nxt(sa[need], pos);
        int nb = nxt(sb[need], pos);
        if (na != nb) return min(na, nb);
        if (na == n + 1) return n + 1;
        return f[na];
    };
 
    for (int i = n; i >= 1; i--) {
        if (a[i] == b[i]) {
            f[i] = calc(i, a[i] + 1);
        }
    }
 
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        ans += calc(l - 1, 1) - l;
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
