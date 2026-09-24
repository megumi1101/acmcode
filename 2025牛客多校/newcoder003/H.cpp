#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int n,m,vis[N],dep[N],l,r,tar,fa[N][21];
vector<int> e[N];
void dfs(int x)
{
	for (int i=0;i<e[x].size();i++)
		dep[e[x][i]]=dep[x]+1,dfs(e[x][i]);
}
int get(int x,int y)
{
	for (int i=19;i>=0;i--)
		if(y>=(1<<i))
			x=fa[x][i],y-=1<<i;
	return x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=2;i<=n;i++)
	{
		cin>>fa[i][0];
		e[fa[i][0]].push_back(i);
	}
	for (int j=1;j<=19;j++)
		for (int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	dep[1]=1;dfs(1);
	vis[0]=vis[1]=1;
	int ans=-1;
	for (int i=1;i<=m;i++)
	{
		cin>>tar>>l>>r;
		if(ans>0) continue;
		int x=tar;
		for (int j=19;j>=0;j--)
			if(!vis[fa[x][j]])
				x=fa[x][j];
		if(x>1) x=fa[x][0];
		if(dep[tar]-dep[x]<=r-l+1) ans=l+dep[tar]-dep[x]-1;
		int y=get(tar,(dep[tar]-dep[x])-(r-l+1));
//		printf("i=%d x=%d y=%d dep=%d\n",i,x,y,(dep[tar]-dep[x])-(r-l+1));
		for (int i=0;i<r-l+1;i++) vis[y]=1,y=fa[y][0];
	}
	cout<<ans<<endl;
	return 0;
}
/*
7 4
1 1 2 2 3 3
4 1 1
7 2 2
5 3 3
6 4 4
*/