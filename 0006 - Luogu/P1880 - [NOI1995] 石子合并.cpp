#include<cstdio>
#include<iostream>
using namespace std;
int fma[1010][1010],fmi[1010][1010],maxx,minn,s[1010];
int sum(int n,int m)
{
	return s[m]-s[n-1];
}
int main()
{
	int n,a[1010];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(int i=1;i<=n+n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(int p=1;p<=n;p++)
	{
		for(int i=1,j=i+p;(i<n+n)&&(j<n+n);i++,j=i+p)
		{
			fmi[i][j]=99999999;
			for(int k=i;k<j;k++)
			{
				fma[i][j]=max(fma[i][j],fma[i][k]+fma[k+1][j]+sum(i,j));
				fmi[i][j]=min(fmi[i][j],fmi[i][k]+fmi[k+1][j]+sum(i,j));
			}
		}
	}
	minn=99999999;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,fma[i][i+n-1]);
		minn=min(minn,fmi[i][i+n-1]);
	}
	printf("%d\n%d",minn,maxx);
	return 0;
}