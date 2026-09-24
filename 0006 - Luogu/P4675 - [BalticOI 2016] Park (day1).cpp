#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,w,h;
struct node
{
	int u,v,dd;
}xd[5000010];
int fa[2010],x[2010],y[2010],r[2010],ans[10][10];
int cnt;
int find(int x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int dis(int i,int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
bool cmp(node a,node b)
{
	return a.dd<b.dd;
}
signed main()
{
	scanf("%d%d%lld%lld",&n,&m,&w,&h);
	for(int i=1;i<=n+4;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&x[i],&y[i],&r[i]);
	}
	for(int i=1;i<4;i++)
	{
		for(int j=i+1;j<=4;j++)
		{
			ans[i][j]=1e12;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			xd[++cnt]=(node){i,j,dis(i,j)-r[i]-r[j]};
		}
	}
	for(int i=1;i<=n;i++)
	{
		xd[++cnt]=(node){i,n+1,x[i]-r[i]};
		xd[++cnt]=(node){i,n+2,y[i]-r[i]};
		xd[++cnt]=(node){i,n+3,w-x[i]-r[i]};
		xd[++cnt]=(node){i,n+4,h-y[i]-r[i]};
	}
	sort(xd+1,xd+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		fa[find(xd[i].u)]=fa[find(xd[i].v)];
		int zz=n+1,xx=n+2,yy=n+3,ss=n+4;
		find(zz),find(xx),find(yy),find(ss);
		if(fa[xx]==fa[zz]||fa[xx]==fa[ss]||fa[xx]==fa[yy])
		{
			ans[1][2]=min(ans[1][2],xd[i].dd);
		}
		if(fa[zz]==fa[xx]||fa[zz]==fa[yy]||fa[ss]==fa[xx]||fa[ss]==fa[yy])
		{
			ans[1][3]=min(ans[1][3],xd[i].dd);
		}
		if(fa[zz]==fa[xx]||fa[zz]==fa[yy]||fa[zz]==fa[ss])
		{
			ans[1][4]=min(ans[1][4],xd[i].dd);
		}
		if(fa[yy]==fa[ss]||fa[yy]==fa[zz]||fa[yy]==fa[xx])
		{
			ans[2][3]=min(ans[2][3],xd[i].dd);
		}
		if(fa[zz]==fa[ss]||fa[zz]==fa[yy]||fa[xx]==fa[ss]||fa[xx]==fa[yy])
		{
			ans[2][4]=min(ans[2][4],xd[i].dd);
		}
		if(fa[ss]==fa[zz]||fa[ss]==fa[xx]||fa[ss]==fa[yy])
		{
			ans[3][4]=min(ans[3][4],xd[i].dd);
		}	
	}
	while(m--)
	{
		int rr,e;
		scanf("%lld%lld",&rr,&e);
		for(int i=1;i<e;i++)
		{
			if(ans[i][e]>=2*rr)
			{
				printf("%d",i);
			}	
		}
		printf("%d",e);
		for(int i=e+1;i<=4;i++)
		{
			if(ans[e][i]>=2*rr)
			{
				printf("%d",i);
			}
		}
		printf("\n");	
	}
}