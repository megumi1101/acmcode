#include<bits/stdc++.h>
using namespace std;
int n,mj;
double eps=1e-8;
double a[105][105];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		mj=i;
		for(int j=i+1;j<=n;j++)
		{
			if(fabs(a[j][i])>fabs(a[mj][i]))
			{
				mj=j;
			}
		}
		if(fabs(a[mj][i])<eps)
		{
			printf("No Solution");
			return 0;
		}
		for(int j=i;j<=n+1;j++)
		{
			swap(a[mj][j],a[i][j]);
		}
		for(int j=1;j<=n;j++)
		{
			if(j==i)continue;
			double tmp=a[j][i]/a[i][i];
			for(int k=i;k<=n+1;k++)
			{
				a[j][k]-=tmp*a[i][k];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%.2lf\n",a[i][n+1]/a[i][i]);
	}
}