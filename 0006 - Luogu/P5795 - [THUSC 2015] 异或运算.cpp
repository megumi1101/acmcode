#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int ch[maxn*40][2],sum[maxn*40];
int ls[maxn],rs[maxn],x[maxn],y[maxn],rt[maxn];
int cnt;
int insert(int pre,int val)
{
	int u=++cnt,res=u;
	for(int i=31;i>=0;i--)
	{
		int t=(val>>i)&1;
		ch[u][t^1]=ch[pre][t^1];
		pre=ch[pre][t];
		u=ch[u][t]=++cnt;
		sum[u]=sum[pre]+1;
	}
	return res;
}
int cx(int u,int d,int l,int r,int k)
{
	int ans=0,tmp;
	int t,pp;
	for(int i=u;i<=d;i++)
	{
		rs[i]=rt[r];
		ls[i]=rt[l-1];
	}
	for(int j=31;j>=0;j--)
	{
		tmp=0;
		for(int i=u;i<=d;i++)
		{
			t=(x[i]>>j)&1;
			tmp+=sum[ch[rs[i]][t^1]]-sum[ch[ls[i]][t^1]];
		}
		if(k<=tmp)
		{
			pp=1;	
		}
		else
		{
			pp=0;
			k-=tmp;			
		}
		ans=(ans<<1)|pp;
		for(int i=u;i<=d;i++)
		{
			t=((x[i]>>j)&1)^pp;
			ls[i]=ch[ls[i]][t];
			rs[i]=ch[rs[i]][t];
		}
	}
	return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&y[i]);
		rt[i]=insert(rt[i-1],y[i]);
	}
	//for(int i=1;i<=n;i++)printf("rt[%d]=%d\n",i,rt[i]);
	int p;
	scanf("%d",&p);
	while(p--)
	{
		int u,d,l,r,k;
		scanf("%d%d%d%d%d",&u,&d,&l,&r,&k);
		printf("%d\n",cx(u,d,l,r,k));
	}
	return 0;
}