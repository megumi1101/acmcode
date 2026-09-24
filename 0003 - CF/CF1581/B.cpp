#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    const int inf = 1e18;
    const int mod = 1e9 + 7;
    const int N = 2e5 + 10;
    const int inv2 = mod - mod / 2;
    int fac[N];
    void sol() {
        int n, m, k;
        cin >> n >> m >> k;
        int ans;
        if (m >= n - 1)  ans = 2;
        if (m >= n * (n - 1) / 2) ans = 1;
        if (n == 1) ans = 0;
        if (m > n * (n - 1) / 2 || m < n - 1) ans = inf;
        if (k - 1 > ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
 
    void main() {
        int T;
        cin>>T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
