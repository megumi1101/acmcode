#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n,ans=0,x;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{	
			scanf("%d",&x);
			ans^=x;
		}
		if(!ans)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}