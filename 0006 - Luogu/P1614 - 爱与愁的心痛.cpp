#include<bits/stdc++.h>
using namespace std;
int sum[3005],ans=9999999;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		sum[i]=sum[i-1]+x;
	}
	for(int i=1;i+m-1<=n;i++)
	{
		ans=min(ans,sum[i+m-1]-sum[i-1]);
	}
	printf("%d",ans);
	return 0;
}