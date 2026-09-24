#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,qn[12],yu[12];
ll mm=1,ans=0;
int gcd(ll x,ll y)
{
	return y?gcd(y,x%y):x; 
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){x=1;y=0;return a;}
	else
	{
		ll d=exgcd(b,a%b,x,y);
		ll t=x;
		x=y;
		y=t-a/b*x;
		return d;
	}	
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&qn[i],&yu[i]);
	}
	for(int i=1;i<=n;i++)
	{
		mm*=qn[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll ri=mm/qn[i];
		ll x,y;
		ll m=qn[i]/gcd(ri,qn[i]);
		exgcd(ri,qn[i],x,y);
		x=(x%m+m)%m;
		ans+=x*ri*yu[i];
		ans%=mm;
	}
	printf("%lld",(ans%mm+mm)%mm);
	return 0;
}