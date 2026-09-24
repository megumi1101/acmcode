#include<bits/stdc++.h>
using namespace std;
int n,a[1010][1010],f[1<<20][21];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	memset(f,0x3f,sizeof(f));
	f[1][1]=0;
	for(int i=1;i<(1<<n);i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!((i>>(j-1))&1))continue;
			for(int k=1;k<=n;k++)
			{
				if(j==k)continue;
				if(!((i>>(k-1))&1))continue;
				f[i][j]=min(f[i][j],f[i^(1<<(j-1))][k]+a[k][j]);
			}
		}
	}
	int minn=99999999;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,f[(1<<n)-1][i]+a[i][1]);
	}
	printf("%d",minn);
	return 0;
}