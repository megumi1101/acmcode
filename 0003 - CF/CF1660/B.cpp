#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		if(n==1)
		{
			if(a[1]!=1)printf("NO\n");
			else printf("YES\n");
			continue;
		}
		else
		{
			if(a[n]-a[n-1]>1)printf("NO\n");
			else printf("YES\n");
			continue;
		}
	}	
}
