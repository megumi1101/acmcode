#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    const int N=3e5+10;
    const int mod=1e9+7;
    int fac[N],facn[N],inv[N],p2n[N];
    void init() {
        fac[0]=facn[0]=p2n[0]=1;
        fac[1]=facn[1]=inv[1]=1; 
        for(int i=2;i<=(int)3e5;i++) {
            inv[i] = inv[mod%i] * (mod-mod/i) % mod;
            fac[i] = fac[i-1] * i % mod;
            facn[i] = facn[i-1] * inv[i] % mod;
        }
        for(int i=1;i<=(int)3e5;i++) {
            p2n[i] = p2n[i-1] * inv[2] %mod;
        }
    }
    int C(int x,int y) {
        return fac[x]*facn[y]%mod*facn[x-y]%mod;
    }
    int get(int x) {
        int res=0;
        for(int i=0;i<=x;i++) {
            if((x-i)%2==0) {
                (res += C(x,i)  *fac[x-i] %mod *facn[(x-i)/2] %mod) %=mod;
            }
        }
        return res;
    }
    void sol() {
        int n,k;
        cin>>n>>k;
        int res=k;
        for(int i=1;i<=k;i++) {
            int x,y;
            cin>>x>>y;
            if(x!=y)res++;
        }
        cout<<get(n-res)<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        init();
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
