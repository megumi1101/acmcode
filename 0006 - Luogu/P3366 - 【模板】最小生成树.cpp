#include<bits/stdc++.h>
using namespace std;
int f[202020],n,m,ans,cnt;
struct edd
{
	int u,v,w;
}ed[202020];
int cmp(edd a,edd b)
{
	return a.w<b.w;
}
int find(int n)
{
	if(f[n]==n)return n;
	f[n]=find(f[n]);
	return f[n];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);
	}
	sort(ed+1,ed+m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int uu=find(ed[i].u);
		int vv=find(ed[i].v);
		if(uu==vv)
		{
			continue;
		}
		ans+=ed[i].w;
		f[vv]=uu;
		cnt++;
		if(cnt==n-1)
		{
			printf("%d",ans);
			break;
		}
	}
	if(cnt!=n-1)
	{
		printf("orz");
	}
	return 0;
}