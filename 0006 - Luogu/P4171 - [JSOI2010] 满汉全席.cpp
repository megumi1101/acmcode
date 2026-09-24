#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+1000;
int dfn[maxn],cnm[maxn],low[maxn],co[maxn],sta[maxn];
vector<int> a[maxn];
int top,num,col;
bool flag;
void tarjan(int u)
{
	dfn[u]=low[u]=++num;
	sta[++top]=u;
	for(int i=0;i<a[u].size();i++)
	{
		int v=a[u][i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!co[v])
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u])
	{
		co[u]=++col;
		++cnm[col];
		while(sta[top]!=u)
		{
			++cnm[col];
			co[sta[top]]=col;
			top--;
		}
		top--;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		flag=0;
		scanf("%d%d",&n,&m);
		
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(cnm,0,sizeof(cnm));
		memset(co,0,sizeof(co));
		top=num=col=0;
		for(int i=1;i<=m;i++)
		{
			char xx[10],yy[10];
			scanf("%s%s",xx,yy);
			int x,tx,y,ty;
			x=y=0;
			int len1=strlen(xx);
			int len2=strlen(yy);
			for(int i=1;i<len1;i++)
			{
				x+=xx[i]-'0';
				if(i!=len1-1)x*=10;
			}
			for(int i=1;i<len2;i++)
			{
				y+=yy[i]-'0';
				if(i!=len2-1)y*=10;
			}
			tx=(xx[0]=='m');
			ty=(yy[0]=='m');
			a[x+n*tx].push_back(y+n*(ty^1));
			a[y+n*ty].push_back(x+n*(tx^1));
		}
		for(int i=1;i<=2*n;i++)
		{
			if(!dfn[i])
			{
				tarjan(i);
			}
		}
		for(int i=1;i<=n*2;i++)
		{
			a[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			if(co[i]==co[i+n])
			{
				printf("BAD\n");
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			printf("GOOD\n");
		}
	}	
	return 0;
}