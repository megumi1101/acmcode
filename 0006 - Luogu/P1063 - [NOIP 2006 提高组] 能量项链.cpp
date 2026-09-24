#include<cstdio>
#include<iostream>
using namespace std;
int n,a[1010],fmax[1010][1010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];	
	}
	for(int p=1;p<n;p++)
	{
		for(int i=1,j=i+p;(i<2*n)&&(j<n+n);i++,j=i+p)
		{
			for(int k=i;k<j;k++)
			{
				fmax[i][j]=max(fmax[i][j],fmax[i][k]+fmax[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
		}
	}
	int maxx;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,fmax[i][i+n-1]);
	}
	printf("%d",maxx);
	return 0;
}