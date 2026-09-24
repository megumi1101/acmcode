#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e9;
const int mod = 998244353;
    void sol() {
        int n;
        cin >> n;
        set<int> s;
        vector<int> a(n), b(n), ans(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        vector<tuple<int, int, int>> c;
        c.reserve(n);
        for (int i = 0; i < n; i++) {
            c.emplace_back(a[i], b[i], i);
            s.insert(b[i]);
        }
        sort(c.begin(), c.end());
        int mx = 0, mn = inf;
        for (int i = n - 1; i >= 0; i--) {
            auto[_, x, id] = c[i];
            if (mn == inf) {
                mx = mn = x;
                ans[id] = 1;
                s.erase(s.find(x));
            } else {
                if (s.upper_bound(mx) != s.end()) ans[id] = 1;
                if (x < mn) mn = x;
                if (x > mx) mx = mn;
                s.erase(s.find(x));
            }
        }
        // 
        for (int i = 0; i < n; i++) cout << ans[i];
        cout << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
