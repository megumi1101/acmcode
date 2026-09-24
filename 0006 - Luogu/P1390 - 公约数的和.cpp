#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int inline rd()
{
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int n,m,d,T;
int ph[N],sum[N],pr[N],vis[N];
void init()
{
	ph[1]=1;
	int cnt=0;
	for(int i=2;i<=2e6;i++)
	{
		if(!vis[i])pr[++cnt]=i,ph[i]=i-1;
		for(int j=1;j<=cnt&&i*pr[j]<=2e6;j++)
		{
			vis[i*pr[j]]=1;
			if(i%pr[j]==0){ph[i*pr[j]]=ph[i]*pr[j];break;}
			ph[i*pr[j]]=ph[i]*(pr[j]-1);
		}
	}
	for(int i=1;i<=2e6;i++)sum[i]=sum[i-1]+ph[i];
}
int wk(int x)
{
	int ans=0,r;
	for(int l=1;l<=x;l=r+1)
	{
		r=x/(x/l);
		ans+=(sum[r]-sum[l-1])*(x/l)*(x/l);
	}
	return ans;
}
signed main()
{
	init();n=rd();
	printf("%lld\n",(wk(n)-n*(n+1)/2)/2);
	return 0;
}