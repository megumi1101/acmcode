#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int n,m,k,ans[maxn],fa[maxn];
int tot,bh[maxn];
struct node
{
	int x,y,num;
}a[maxn];
bool cmp(node a,node b)
{
	return a.num<b.num;
}
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);	
}
void hb(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)fa[fx]=fy,tot--;
}
int main()
{
	scanf("%d%d",&n,&m);
	tot=n;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=n;i++)a[i].num=0;
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		int d;
		scanf("%d",&d);
		bh[d]=k-i+1;
	}
	for(int i=1;i<=m;i++)a[i].num=max(bh[a[i].x],bh[a[i].y]);
	sort(a+1,a+1+m,cmp);
	for(int i=0,j=1;i<=k;i++)
	{
		for(;a[j].num==i;j++)
		{
			hb(a[j].x,a[j].y);
		}
		ans[i]=tot-(k-i);
	}
	for(int i=k;i>=0;i--)printf("%d\n",ans[i]);
	return 0;	
}