#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int inline rd()
{
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int n,m,d;
int mu[N],sum[N],pr[N],vis[N];
void init()
{
	mu[1]=1;
	int cnt=0;
	for(int i=2;i<=1e6;i++)
	{
		if(!vis[i])pr[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&i*pr[j]<=1e6;j++)
		{
			vis[i*pr[j]]=1;
			if(i%pr[j]==0){mu[i*pr[j]]=0;break;}
			mu[i*pr[j]]=-mu[i];
		}
	}
	for(int i=1;i<=1e6;i++)sum[i]=sum[i-1]+mu[i];
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
	init();
	n=rd(),m=rd(),d=rd();
	n/=d,m/=d;
	printf("%lld\n",wk(n,m));
	return 0;
}