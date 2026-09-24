#include<cstdio>
#define maxn 1000005
int fa[maxn],size[maxn],val[maxn],cnt[maxn],root=0;
int ch[maxn][2];
int n,opt,xbb,tot;
inline int read()
{
       register int x=0,t=1;
       register char ch=getchar();
       while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
       if(ch=='-'){t=-1;ch=getchar();}
       while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
       return x*t;
}
void update(int x)
{
	size[x]=size[ch[x][0]]+size[ch[x][1]]+cnt[x];
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
void find(int x)
{
	int u=root;
	if(!u)
	{
		return;
	}
	while(val[u]!=x&&ch[u][x>val[u]])
	{
		u=ch[u][x>val[u]];
	}
	splay(u,0);
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
	if(u)
	{
		cnt[u]++;
	}
	else
	{
		u=++tot;
		if(fath)
		{
			ch[fath][x>val[fath]]=u;
		}
		val[u]=x;
		fa[u]=fath;
		cnt[u]=1;
		size[u]=1;
	}
	splay(u,0);
}
int next(int x,int f)
{
	find(x);
	int u=root;
	if(val[u]>x&&f)
	{
		return u;
	}
	if(val[u]<x&&!f)
	{
		return u;
	}
	u=ch[u][f];
	while(ch[u][f^1])
	{
		u=ch[u][f^1];
	}
	return u;
}
void delet(int x)
{
	int qian=next(x,0);
	int hou=next(x,1);
	splay(qian,0);
	splay(hou,qian);
	int del=ch[hou][0];
	if(cnt[del]>1)
	{
		cnt[del]--;
		splay(del,0);
	}
	else
	{
		ch[hou][0]=0;
	}
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
		int y=ch[u][0];
		if(x>size[y]+cnt[u])
		{	
			x-=size[y]+cnt[u];
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
int main()
{
	insert(-2147483647);
    insert(+2147483647);
	n=read();
	while(n--)
	{	
		opt=read();
		xbb=read();
		switch(opt)
        {
            case 1:insert(xbb);break;
            case 2:delet(xbb);break;
            case 3:find(xbb);printf("%d\n",size[ch[root][0]]);break;
            case 4:printf("%d\n",val[kth(xbb+1)]);break;
            case 5:printf("%d\n",val[next(xbb,0)]);break;
            case 6:printf("%d\n",val[next(xbb,1)]);break;
        }
    }
}