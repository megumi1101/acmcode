#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
int n,m,a[maxn],b[maxn],p[maxn];
double f[maxn][5010];
bool check(double mid)
{
	for(int i=n;i>=0;i--)
	{
		for(int j=m+1;j<=5000;j++)
		{
			f[i][j]=mid;
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j]=min(mid,(f[i+1][j+a[i+1]]+a[i+1])*p[i+1]/100.0+(f[i+1][j+b[i+1]]+b[i+1])*(100.0-p[i+1])/100.0);
		}
	}
	return f[0][0]<mid;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&p[i]);
	}
	double mid;
	double l=0,r=1e9;
	for(int i=1;i<=100;i++)
	{
		mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.9lf",l);
	return 0;
}
