#include<bits/stdc++.h>
#define int long long
const int mod=1e9+7;
using namespace std;
int n,m,a[55],k,f[55],qz[55],hz[55],jc[55],ans;
map<int,int> mp;
int fp(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;b>>=1;
    }
    return res;
}
int wk(int p)
{
    if(p<=k+2) return f[p];
    int res=0;
    qz[0]=1;
    for(int i=1;i<=k+2;i++) qz[i]=qz[i-1]*(p-i)%mod;
    hz[k+3]=1;
    for(int i=k+2;i>=1;i--) hz[i]=hz[i+1]*(p-i)%mod;
    for(int i=1;i<=k+2;i++){
        int x=qz[i-1]*hz[i+1]%mod;
        int fu=((k+2-i)&1)?-1:1;
        int y=jc[i-1]*jc[k+2-i]*fu%mod;
        res=(res+f[i]*x%mod*fp(y,mod-2)%mod)%mod;
    }
    return (res+mod)%mod;
}
signed main()
{
    jc[0]=1;
    for(int i=1;i<=52;i++) jc[i]=jc[i-1]*i%mod;
    int T;scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&m);
        k=m+1;
        mp.clear();
        for(int i=1;i<=m;i++)scanf("%lld",&a[i]),mp[a[i]]=1;
        sort(a+1,a+m+1);
        while(mp[n]) n--,k--,m--;
        for(int i=1;i<=k+2;i++) f[i]=(f[i-1]+fp(i,k))%mod;
        ans=wk(n);
        for(int i=1;i<=m;i++) ans=(ans-fp(a[i],k))%mod;
        for(int i=1;i<=m;i++) ans=(ans+wk(n-a[i]))%mod;
        for(int i=1;i<=m;i++)
            for(int j=i-1;j>=1;j--)
                ans=(ans-fp(a[i]-a[j],k))%mod;
        printf("%lld\n",((ans+mod)%mod));
    }
    return 0;
}