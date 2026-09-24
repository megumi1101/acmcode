#include<bits/stdc++.h>
using namespace std;
int n,a[10010],dp[10010],imax,mm,q;
int main()
{
	//freopen("lis.in","r",stdin);
	//freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		dp[i]=1;
	}
	scanf("%d",&mm);
	for(int i=n-1;i>=1;i--)
	{		
		int maxn=1;
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]<a[j])
			{
				if(dp[j]+1>maxn)
				{
					maxn=dp[j]+1;
				}
			}
		}
		dp[i]=maxn;
		if(maxn>imax)imax=maxn;
	}
	for(int i=1;i<=mm;i++)
	{	
		scanf("%d",&q);
		if(q>imax)
		{
			printf("Impossible\n");
		}
		else
		{
			int last=-1;
			for(int j=1;j<=n;j++)
			{
				if(dp[j]>=q&&a[j]>last)
				{
					printf("%d ",a[j]);
					q--;
					last=a[j];
					if(q==0)break;
				}				
			}
			printf("\n");
		}
	}
	return 0;
}