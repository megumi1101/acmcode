#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    const int inf = 1e18;
    const int mod = 1e9 + 7;
    const int N = 2e5 + 10;
    const int inv2 = mod - mod / 2;
    int fac[N];
    void init() {
        fac[0] = fac[1] = 1;
        for (int i = 2; i < N; i++) {
            fac[i] = fac[i - 1] * i % mod;
        }
 
    }
    void sol() {
        int n;
        cin >> n;
        cout << fac[2 * n] * inv2 % mod << "\n";
    }
 
    void main() {
        init();
        int T;
        cin>>T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
