 #include<bits/stdc++.h>
 using namespace std;
 int to[101010],head[666],nxt[101010],w[101010];
int dfn[666],low[666],sta[666],num;
int col,si[666],co[666],tot,top,v[666];
int n,m1,m2,ans;
int dis[666][666];
void add(int x,int y,int v)
{
 	to[++tot]=y;
 	w[tot]=v;
 	nxt[tot]=head[x];
 	head[x]=tot;
}
void tar(int u)
{
 	dfn[u]=low[u]=++num;
 	sta[++top]=u;
 	for(int i=head[u];~i;i=nxt[i])
 	{
 		int v=to[i];
 		if(!dfn[v])
 		{
 			tar(v);
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
		++si[col];
		while(sta[top]!=u)
		{
			co[sta[top]]=col;
			++si[col];
			top--;
		}
		top--;
	}
}
 int main()
 {
 	scanf("%d%d%d",&n,&m1,&m2);
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=n;j++)
 		{
 			dis[i][j]=99999999;
		 }
	 }
 	memset(head,-1,sizeof(head));
 	for(int i=1;i<=n;i++)
 	{
 		dis[i][i]=0;
	}
 	while(m1--)
 	{
 		int x,y;
		scanf("%d%d",&x,&y);
 		add(x,y,-1);
 		add(y,x,1);
 		dis[x][y]=-1;
 		dis[y][x]=1;
	}
	while(m2--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,0);
		if(dis[x][y]==99999999)		
		{
			dis[x][y]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			tar(i);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(co[i]!=co[k]||dis[i][k]==99999999)continue;
			for(int j=1;j<=n;j++)
			{
				if(co[j]!=co[i]||dis[k][j]==99999999)continue;
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i][i])
		{
			printf("NIE\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(co[i]!=co[j])continue;
			v[co[i]]=max(v[co[i]],dis[i][j]);
		}
	}
	for(int i=1;i<=col;i++)
	{
		ans+=v[i];
	}
	printf("%d\n",ans+col);
	return 0;
 }