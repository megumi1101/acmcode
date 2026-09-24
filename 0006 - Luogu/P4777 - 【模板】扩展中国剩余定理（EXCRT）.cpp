#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll bb[101000],aa[101000];
ll mul(ll a,ll b,ll mod)
{
    ll res=0;
    while(b>0)
    {
        if(b&1) res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res;
}
ll gcd(ll x1,ll y1)
{
	return y1?gcd(y1,x1%y1):x1;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;y=0;return a;
	}
	else
	{
		ll dddd=exgcd(b,a%b,x,y);
		ll t=x;
		x=y;
		y=t-a/b*x;
		return dddd;
	}
}
ll excrt()
{
	ll x,y;
	ll mm=bb[1],ans=aa[1];
	for(int i=2;i<=n;i++)
	{
		ll a=mm,b=bb[i],c=((aa[i]-ans)%b+b)%b;
		ll d=gcd(a,b);
		c/=d;ll jj=b/d;
		exgcd(a,b,x,y);
		x=(mul(x,c,jj)+jj)%jj;
		ans+=mm*x;
		mm*=jj;
		ans=(ans%mm+mm)%mm;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&bb[i],&aa[i]);
	}
	printf("%lld",excrt());
	return 0;
}
