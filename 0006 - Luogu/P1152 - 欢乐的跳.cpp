#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool vis[1005];
int main()
{
	int n;
	scanf("%d%d",&n,&a[1]);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int k=abs(abs(a[i])-abs(a[i-1]));
		if(k>n)continue;
		vis[k]=1;
	}
	for(int i=1;i<n;i++)
	{
		if(!vis[i])
		{
			printf("Not jolly");
			return 0;
		}
	}
	printf("Jolly");
	return 0;
}