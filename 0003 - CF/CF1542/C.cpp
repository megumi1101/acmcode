#include <bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int mod = 1e9+7;
    int f[1005],g[1005];
    int gcd(int a,int b) {
        return b?gcd(b,a%b):a;
    }
    int lcm(int a,int b) {
        return a*b/gcd(a,b);
    }
    void init() {
        for(int i=1;i<=1000;i++)f[i]=1e17;
        f[2] = 1; f[3] = 2;
        g[2] = 2; g[3] = 5;
        for(int i=4;i<=1000;i++) {
            f[i] = lcm(i-1,f[i-1]); 
            g[i] = g[i-1]*(f[i]/f[i-1])+1;
            g[i] %= mod;
            if(f[i] >= 1e16)break;
        }
    }
    int sol(int x) {
        int now=2,res=0;
        while(x>=f[now]) {
            now++;
        }
        now--;
        for(;now>=2;now--) {
            res += x/f[now]*g[now];
            res%=mod;
            x%=f[now];
        }
        return res;
    }
    void main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int T;
        init();
        cin>>T;
        int n;
        while(T--){
            cin>>n;cout<<sol(n)<<"\n";
        }
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
