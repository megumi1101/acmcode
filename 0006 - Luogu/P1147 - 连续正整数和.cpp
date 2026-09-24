#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,i=1,j=2,sum=3;
	scanf("%d",&m);
	while(i<=m/2)
	{
		if(sum==m)
		{
			printf("%d %d\n",i,j);
			sum-=i++;
		}
		else if(sum<m)
		{
			sum+=++j;
		}
		else
		{
			sum-=i++;
		}
	}
	return 0;
}