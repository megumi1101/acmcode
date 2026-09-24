#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
    void sol() {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> p(n + 1), a(n + 1);
        p[0] = 0;
        for (int i = 1; i <= n; i++) p[i] = i;
        p[r] = p[l - 1];
        for (int i = 1; i <= n; i++)
            a[i] = p[i - 1] ^ p[i];  
 
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
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
    return Xbbbz::main(), 0;
}
