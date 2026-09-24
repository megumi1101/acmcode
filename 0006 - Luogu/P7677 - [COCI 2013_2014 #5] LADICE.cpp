#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int fa[N],n,l;bool vis[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	n=rid();l=rid();
	for(int i=1;i<=l;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int x=rid(),y=rid();
		int fx=find(x),fy=find(y);
		if(!vis[fx]||!vis[fy])
		{
			printf("LADICA\n");
			if(!vis[fx])vis[fx]=1,fa[fx]=fy;
			else vis[fy]=1,fa[fy]=fx;continue;
		}
		printf("SMECE\n");
	}
	return 0;
}
