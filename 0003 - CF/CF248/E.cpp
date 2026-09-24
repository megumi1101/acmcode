#include<bits/stdc++.h>
using namespace std;
#define db long double
const int maxn=1e5+50;
db f[maxn][110],c[501000][10],ans;
int num[maxn],now[maxn],n,q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		now[i]=num[i];f[i][num[i]]=1;
		ans+=f[i][0];
	}
	for(int i=0;i<=maxn*5;i++)c[i][0]=1;
	for(int i=1;i<=maxn*5;i++)
		for(int j=1;j<=min(i,5);j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	scanf("%d",&q);
	while(q--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		ans-=f[u][0];
		for(int j=0;j<=num[u];j++)
		{
			db res=0;
			for(int k=j;k<=min(j+w,now[u]);k++)
			{
				res+=f[u][k]*c[k][k-j]*c[now[u]-k][w-k+j];
			}
			res/=c[now[u]][w];
			f[u][j]=res;
		}
		ans+=f[u][0];
		now[u]-=w;now[v]+=w;
		printf("%.9Lf\n",ans);
	}
	return 0;
}
