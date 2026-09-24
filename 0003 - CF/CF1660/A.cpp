#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		
		int n,m;
		scanf("%d%d",&n,&m);
		if(n)
		{
			printf("%d\n",m+m+n+1);
		}
		else
		{
			printf("1\n");
		}
	}
}
