#include<bits/stdc++.h>
using namespace std;
int t,fa[30303],sum[30303],tot[30303];
int find(int x)
{
	if(fa[x]==x)return x;
	int tt=fa[x];
	fa[x]=find(fa[x]);
	tot[x]+=tot[tt];
	return fa[x];
}
int he(int x,int y)
{
	int u=find(x);
	int v=find(y);
	fa[u]=v;
	tot[u]=sum[v];
	sum[v]+=sum[u];
	sum[u]=0;
}
int main()
{
	for(int i=1;i<=30000;i++)
	{
		fa[i]=i;
		sum[i]=1;
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		char k;
		int a,b;
		scanf("%s%d%d",&k,&a,&b);
		if(k=='M')
		{
			he(a,b);
		}
		else
		{
			int u=find(a);
			int v=find(b);
			if(u==v)
			{
				printf("%d\n",abs(tot[a]-tot[b])-1);
			}
			else
			{
				printf("-1\n");
			}
		}
	}
	return 0;
}