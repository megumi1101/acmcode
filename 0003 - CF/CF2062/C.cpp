#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 2e18;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        int ans = 0;
        for (auto &i: a) cin >> i, ans += i;
        if (n == 1) {
            cout << a[0] << "\n";
            return;
        }
        vector<int> b, c;
        b.push_back(a[0]);
        c.push_back(a.back());
        for (int t = n - 1; t >= 2; t--) {
            vector<int> na(t);
            for (int i = 0; i < t; i++) {
                na[i] = a[i + 1] - a[i];
            }
            a = na;
            b.push_back(a[0]);
            b.push_back(-a[0]);
            c.push_back(a.back());
            c.push_back(-a.back());
        }
 
        for (int i = 0; i < b.size(); i++) {
            ans = max({ans, b[i] - c[i], c[i] - b[i]});
        }
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
int main() {
    return Xbbbz::main(),0;
}
