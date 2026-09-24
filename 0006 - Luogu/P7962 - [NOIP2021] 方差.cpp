#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10,inf=1e18;
int rd()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int a[N],d[N],s[N],f[N*50],n,mx;
void up(int &x,int y){if(y<x)x=y;}
signed main()
{
	n=rd();a[1]=mx=rd();
	for(int i=2;i<=n;i++)a[i]=rd(),d[i-1]=a[i]-a[i-1],mx=max(mx,a[i]);mx*=n;
	for(int i=1;i<=mx;i++)f[i]=inf;f[0]=s[0]=0;
	sort(d+1,d+n);
	for(int i=1;i<n;i++)
	{
		s[i]=s[i-1]+d[i];
		if(d[i]==0)continue;
		for(int x=mx;x>=0;x--)
		{
			if(f[x]==inf)continue;
			up(f[x+i*d[i]],f[x]+2*x*d[i]+i*d[i]*d[i]);
			up(f[x+s[i]],f[x]+s[i]*s[i]);
			f[x]=inf;
		}
	}
	int ans=inf;
	for(int i=0;i<=mx;i++)
		if(f[i]<inf)up(ans,n*f[i]-i*i);
	printf("%lld",ans);
	return 0;
}
