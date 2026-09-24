#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int fa[250505];
int find(int x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int he(int x,int y)
{
	int u=find(fa[x]);
	int v=find(fa[y]);
	fa[u]=v;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n+n+n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
		int z,x,y;
		scanf("%d%d%d",&z,&x,&y);
		if(x>n||y>n)
		{
			ans++;
			continue;
		}
		if(z==1)
		{
			if(find(x+n)==find(y)||find(x+n+n)==find(y))
			{
				ans++;
				continue;
			}
			he(x,y);
			he(x+n,y+n);
			he(x+n+n,y+n+n);
		}
		if(z==2)
		{
			if(find(x)==find(y)||find(x+n+n)==find(y))
			{
				ans++;
				continue;
			}
			he(x+n,y);
			he(x+n+n,y+n);
			he(x,y+n+n);
		}		
	}
	printf("%d",ans);
		return 0;
}