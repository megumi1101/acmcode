#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz{
    #define int long long
    const int inf = 1e18;
    void sol () {
        int n, k;
        cin >> n >> k;
        int a[n + 5];
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort (a + 1, a + 1 + n);
        int x = a[n - 1] + a[n];
        int ans = k / x * 2;
        k %= x;
        if (k > 0)ans++;
        if (k > a[n])ans++;
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) sol();
    }
 
    #undef int
}
 
int main() {
    return xbbbz::main(),0;
}
