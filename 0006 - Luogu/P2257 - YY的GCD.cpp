#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+5;
int inline rd()
{
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int n,m,d,T;
int mu[N],sum[N],pr[N],vis[N],f[N];
void init()
{
	mu[1]=1;
	int cnt=0;
	for(int i=2;i<=1e7;i++)
	{
		if(!vis[i])pr[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&i*pr[j]<=1e7;j++)
		{
			vis[i*pr[j]]=1;
			if(i%pr[j]==0){mu[i*pr[j]]=0;break;}
			mu[i*pr[j]]=-mu[i];
		}
	}
	for(int i=1;i<=cnt;i++)
		for(int j=1;pr[i]*j<=1e7;j++)
			f[j*pr[i]]+=mu[j];
	for(int i=1;i<=1e7;i++)sum[i]=sum[i-1]+f[i];
}
int wk(int x,int y)
{
	int ans=0,r;
	for(int l=1;l<=min(x,y);l=r+1)
	{
		r=min(x/(x/l),y/(y/l));
		ans+=(sum[r]-sum[l-1])*(x/l)*(y/l);
	}
	return ans;
}
signed main()
{
	init();T=rd();
	while(T--)
	{
		n=rd(),m=rd();
		printf("%lld\n",wk(n,m));
	}
	return 0;
}