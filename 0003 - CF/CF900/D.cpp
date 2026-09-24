// LUOGU_RID: 92652364
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7,N=1e5+10;
int X,Y,cnt,p[N];
bool pd[N];
void add(int &x,int y){if((x+=y)>=mod)x-=mod;}
int fap(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;b>>=1;
	}
	return res;
}
void init()
{
	for(int i=2;i<=1e5;i++)
	{
		if(!pd[i])p[++cnt]=i;
		for(int j=1;(j<=cnt)&&p[j]*i<=1e5;j++)
		{
			pd[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
int mu(int x)
{
	int res=0;
	for(int i=1;i<=cnt&&p[i]*p[i]<=x;i++)
	{
		if(x%p[i])continue;
		int ret=0;
		while(x%p[i]==0){ret++;x/=p[i];}
		if(ret>1)return 0;
		++res;
	}
	if(x>1)++res;
	if(res&1)return mod-1;
	else return 1;
}
signed main()
{
	init();
	scanf("%lld%lld",&X,&Y);
	if(Y%X){puts("0");return 0;}
	int n=Y/X,ans=0;
	for(int i=1;i*i<=n;i++)
	{	
		if(n%i==0)
		{
			add(ans,mu(n/i)*fap(2,i-1)%mod);
			if(i*i!=n)add(ans,mu(i)*fap(2,n/i-1)%mod);
		}
	}
	printf("%lld",ans);
	return 0;
}
 
