#include <bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int mod = 998244353;
    void main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        vector<int>f(1000005), sumf(1000005),d(1000005);
        for(int i=1;i<=1000000;i++)
		    for(int j=i;j<=1000000;j+=i)++d[j];
        f[1]=1,sumf[1]=1;
        for(int i=2;i<=1000000;i++) {
            f[i] = d[i] + sumf[i-1];f[i]%=mod;
            sumf[i] = sumf[i-1] + f[i];sumf[i]%=mod;
        }
        int n;
        cin>>n;
        cout<<f[n];
    }
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
