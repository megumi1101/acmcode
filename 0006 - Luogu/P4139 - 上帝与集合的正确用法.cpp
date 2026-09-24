#include<bits/stdc++.h>
using namespace std;
int t,cnt=0;
int pp,phi[10000005],p[10000005],pd[10000005];
void phii(int n)
{
	phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(pd[i]==0)
		{
			p[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt&&i*p[j]<=n;j++)
		{
			pd[i*p[j]]=1;
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			else
			{
				phi[i*p[j]]=phi[i]*phi[p[j]];
			}
		}
	}
}
int mull(int a,int b,int mod)
{
	int res=0;
	while(b)
	{
		if(b&1) res=(res+a)%mod;
		a=((a%mod)+(a%mod))%mod;
		b>>=1;
	}
	return res;
}
int poow(int a,int b,int mod)
{
	int ret=1;
	while(b)
	{
		if(b&1) ret=mull(ret,a,mod)%mod;
		a=mull(a,a,mod)%mod;
		b>>=1;
	}
	return ret;
}
int solve(int mod)
 {
    if(mod == 1) return 0;
    return poow(2, solve(phi[mod])+phi[mod], mod);
}
int main()
{
	phii(10000000);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&pp);
		printf("%d\n",solve(pp));
	}
	return 0;
}