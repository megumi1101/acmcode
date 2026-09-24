#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    vector<int> tmp[2];
    int vis[N][2];
    void sol() {
        int n, k;
        cin >> n >> k;
        int l[n + 5], r[n + 5];
        int a[n + 5];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> l[i] ;
        }
        for (int i = 1; i <= n; i++) {
            cin  >> r[i];
        }
        for (int i = 1; i <= n; i++) {
            a[i] = min(l[i], r[i]);
            ans += l[i] + r[i];
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n - k + 1; i++) ans -= a[i];
        cout << ans + 1 << "\n";
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
    return Xbbbz::main(), 0;
}
/*
1 3
5 4 3
*/
