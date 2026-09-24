#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,k,p2[64];
signed main()
{
	p2[0]=1;for(int i=1;i<=63;i++)p2[i]=2*p2[i-1];
	scanf("%llu%llu",&n,&k);
	bool op=0;
	while(n)
	{
		if(k>p2[n-1]-1)
		{
			if(op)printf("0");
			else printf("1");
			op=1;k-=p2[n-1];
		}
		else
		{
			if(op)printf("1");
			else printf("0");
			op=0;
		}
		n--;
	}
}