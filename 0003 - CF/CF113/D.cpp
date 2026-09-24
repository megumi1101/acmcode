#include<bits/stdc++.h>
using namespace std;
#define db double
db p[30][30],a[900][900];
int n,m,ds[30],x,y,mj;
vector<int>ed[30];
int pp(int x,int y)
{
	return (x-1)*n+y;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
		ds[x]++;ds[y]++;
	}
	for(int i=1;i<=n;i++)scanf("%lf",&p[i][i]);
	for(int u=1;u<=n;u++)
	{
		for(int i=0;i<ed[u].size();i++)
		{
			int v=ed[u][i];
			p[u][v]=(1-p[u][u])/ds[u];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int c=1;c<=n;c++)
			{
				for(int d=1;d<=n;d++)
				{
					if(c!=d)
					a[pp(i,j)][pp(c,d)]=p[c][i]*p[d][j];
				}
			}
			a[pp(i,j)][pp(i,j)]-=(db)1;
		}
	}
	a[pp(x,y)][n*n+1]=-1;
	for(int i=1;i<=n*n;i++)
	{
		mj=i;
		for(int j=i+1;j<=n*n;j++)
		{
			if(fabs(a[j][i])>fabs(a[mj][i]))
			{
				mj=j;
			}
		}
		for(int j=i;j<=n*n+1;j++)
		{
			swap(a[mj][j],a[i][j]);
		}
		for(int j=1;j<=n*n;j++)
		{
			if(j==i)continue;
			double tmp=a[j][i]/a[i][i];
			for(int k=i;k<=n*n+1;k++)
			{
				a[j][k]-=tmp*a[i][k];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%.8lf ",a[pp(i,i)][n*n+1]/a[pp(i,i)][pp(i,i)]);
	}
}
