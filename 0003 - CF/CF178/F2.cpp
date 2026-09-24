#include<bits/stdc++.h>
using namespace std;
#define N 2005*500
void chkmax(int &a,int b){a=a>b?a:b;}
int n,k;
vector<int>ed[4005];
int num,siz[4005],dep[4005];
char s[505];
int son[N][26],cnt=1,en[N],sz[N];
int f[4005][2005];
void ins()
{
	int u=1,v;
	for(int i=0;i<strlen(s);i++)
	{
		if(!son[u][v=s[i]-'a'])son[u][v]=++cnt,sz[u]++;
		u=son[u][v];
	}
	en[u]++;
}
void dfs1(int u,int fat,int deep)
{
	if(u==1||sz[u]>1||en[u])
	{
		dep[++cnt]=deep;siz[cnt]=en[u];
		ed[fat].push_back(cnt);
		fat=cnt;
	}
	for(int i=0;i<26;i++)
	{
		int v=son[u][i];
		if(!v) continue;
		dfs1(v,fat,deep+1);
	}
}
int tmp[4005];
void dfs2(int u,int fat)
{
	for(int kk=0;kk<ed[u].size();kk++)
	{
		int v=ed[u][kk];
		dfs2(v,u);
		for(int i=0;i<=siz[u];i++) tmp[i]=f[u][i];
		for(int i=0;i<=min(siz[u],k);i++)
		{
			for(int j=0;j<=min(siz[v],k-i);j++)
			{
				chkmax(f[u][i+j],tmp[i]+f[v][j]);
			}
		}
		siz[u]+=siz[v];
	}
	for(int i=1;i<=siz[u];i++) f[u][i]+=i*(i-1)/2*(dep[u]-dep[fat]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%s",s),ins();
	cnt=0;
	dfs1(1,0,0);
	dfs2(1,0);
	printf("%d",f[1][k]);
	return 0;		
}
