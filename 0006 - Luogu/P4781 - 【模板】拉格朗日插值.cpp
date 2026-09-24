#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
#define int long long
int mod=998244353;
int n,k,x[maxn],y[maxn],ans,s1,s2;
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
int inv(int x){return fp(x,mod-2);}
signed main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld%lld",x+i,y+i);
    for(int i=1;i<=n;i++)
    {
        s1=y[i]%mod;s2=1;
        for(int j=1;j<=n;j++)if(i!=j)s1=s1*(k-x[j])%mod,s2=s2*((x[i]-x[j]%mod)%mod)%mod;
        ans+=s1*inv(s2)%mod;ans=(ans+mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}