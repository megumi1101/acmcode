#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1000005
int fa[maxn],size[maxn],val[maxn],cnt[maxn],root=0;
int ch[maxn][2],tag[maxn],l,r;
int n,tot,m;
inline int read()
{
       register int x=0,t=1;
       register char ch=getchar();
       while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
       if(ch=='-'){t=-1;ch=getchar();}
       while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
       return x*t;
}
void pushdown(int x)
{
	if(tag[x])
	{
		tag[ch[x][0]]^=1;
		tag[ch[x][1]]^=1;
		tag[x]=0;
		swap(ch[x][0],ch[x][1]);
	}
}
void update(int x)
{
	size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
}
void rotate(int x)
{
	int y=fa[x];
	int z=fa[y];
	int k=(ch[y][1]==x);
	ch[z][ch[z][1]==y]=x;
	fa[x]=z;
	ch[y][k]=ch[x][k^1];
	fa[ch[x][k^1]]=y;
	ch[x][k^1]=y;
	fa[y]=x;
	update(y);update(x);
}
void splay(int x,int goal)
{
	while(fa[x]!=goal)
	{
		int y=fa[x];
		int z=fa[y];
		if(z!=goal)
		{
			((ch[z][0]==y)^(ch[y][0]==x))?rotate(x):rotate(y);
		}
		rotate(x);
	}
	if(goal==0)
	{
		root=x;
	}
}
void insert(int x)
{
	int fath=0;
	int u=root;
	while(u&&x!=val[u])
	{
		fath=u;
		u=ch[u][x>val[u]];
	}
	u=++tot;
	if(fath)
	{
		ch[fath][x>val[fath]]=u;
	}
	val[u]=x;
	fa[u]=fath;
	size[u]=1;
	splay(u,0);
}
int kth(int x)
{
	int u=root;
	if(size[u]<x)
	{
		return -1;
	}
	while(1)
	{
		pushdown(u);
		int y=ch[u][0];
		if(x>size[y]+1)
		{	
			x-=size[y]+1;
			u=ch[u][1];
		}
		else if(x<=size[y])
		{
			u=y;
		}
		else
		{
			return u;
		}
	}
}
void fan(int l,int r)
{
	l=kth(l);
	r=kth(r+2);
	splay(l,0);
	splay(r,l);
	tag[ch[ch[root][1]][0]]^=1;
}
void write(int u)
{
	pushdown(u);
	if(ch[u][0])
	{
		write(ch[u][0]);
	}
	if(val[u]>1&&val[u]<n+2)
	{
		printf("%d ",val[u]-1);
	}
	if(ch[u][1])
	{
		write(ch[u][1]);
	}
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n+2;i++)
	{
		insert(i);
	}
	while(m--)
	{
		l=read();
		r=read();
		fan(l,r);
	}
	write(root);
	printf("\n");
	return 0;
}