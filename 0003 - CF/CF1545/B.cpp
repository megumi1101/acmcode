#include <bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N=1e5+10;
    const int mod=998244353;
    int fac[N], facn[N], inv[N];
    void init() {
        fac[0] = facn[0] = 1;
        fac[1] = facn[1] = inv[1] = 1;
        for(int i=2;i<=1e5;i++) {
            fac[i] = fac[i-1]*i%mod;
            inv[i] = (mod-mod/i)*inv[mod%i]%mod;
            facn[i] = facn[i-1]*inv[i]%mod;
        }   
    }
    int C(int a, int b) {
        return fac[a]*facn[b]%mod*facn[a-b]%mod;
    }
    void sol() {
        int n;
        cin>>n;
        string s;
        cin>>s;
        s=' '+s;
        int res0=0, res1=0;
        int tmp=0;
        for(int i=1;i<s.size();i++) {
            if(s[i]=='0') {
                res0++;
                res1+=tmp/2;
                tmp=0;
            }
            else tmp++;
        }
        res1+=tmp/2;
        cout<<C(res0+res1,res0)<<"\n";
    }
    void main() {
        int T;
        cin>>T;
        init();
        while(T--) sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
