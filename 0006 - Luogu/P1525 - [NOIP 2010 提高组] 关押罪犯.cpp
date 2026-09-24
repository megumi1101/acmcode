#include<bits/stdc++.h>
using namespace std;
int n,m,mm=0;
int fa[20202],b[20202];
int find(int x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int he(int x,int y)
{
	int v=find(x);
	int u=find(y);
	fa[u]=v;
}
bool check(int x,int y)
{
	if(find(x)==find(y))
	{
		return true;
	}
	else return false;
}
struct node
{
	int x,y,z;
}a[101001];

bool cmp(node a,node b)
{
	return a.z>b.z;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(check(a[i].x,a[i].y))
		{
			printf("%d",a[i].z);
			return 0;
		}
		else
		{
			if(!b[a[i].x])
			{
				b[a[i].x]=a[i].y;
			}
			else 
			{
				he(b[a[i].x],a[i].y);
			}
			if(!b[a[i].y])
			{
				b[a[i].y]=a[i].x;
			}
			else 
			{
				he(b[a[i].y],a[i].x);
			}
		}		
	}
	printf("0");	
	return 0;
}