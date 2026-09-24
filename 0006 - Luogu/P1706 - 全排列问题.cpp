#include<bits/stdc++.h>
using namespace std;
int n,a[10],b[10];
void pr(int mm)
{
	for(int i=1;i<=mm;i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n");
}
void dfs(int k)
{
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			a[k]=i;
			if(k==n)
			{
				pr(n);
			}
			else dfs(k+1);
			b[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
 } 