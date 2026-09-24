#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,q;
int d[300][300],dis[300][300],ran[300];
struct node
{
	int val;
	int bh;
}num[300];
int cmp(node a,node b)
{
	return a.val<b.val;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i].val);
		num[i].bh=i;
	}
	sort(num+1,num+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		ran[num[i].bh]=i;
	}
	memset(d,0x3f,sizeof(d));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		d[ran[a]][ran[b]]=d[ran[b]][ran[a]]=min(c,d[ran[a]][ran[b]]);		
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				dis[i][j]=min(dis[i][j],d[i][j]+max(num[k].val,max(num[i].val,num[j].val)));
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int ii,jj;
		scanf("%d%d",&ii,&jj);
		printf("%d\n",dis[ran[ii]][ran[jj]]);
	}
	return 0;	
}