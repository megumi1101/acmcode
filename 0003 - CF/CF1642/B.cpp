#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n,a[300005],dao=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				dao++;
			}
		}
		dao++;
		for(int i=1;i<=dao;i++)
		{
			printf("%d ",dao);
		}
		for(int i=dao+1;i<=n;i++)
		{
			printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}
