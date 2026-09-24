#include<bits/stdc++.h>
using namespace std;
int n,len,a[1000002];
int q[1000002];
int main()
{
	scanf("%d%d",&n,&len);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int l=1,r=0;
	for(int i=1;i<=n;i++)
	{
		
		while(l<=r&&q[l]+len<=i)
		{
			l++;
		}
		while(l<=r&&a[i]<a[q[r]])
		{
			r--;
		}
		q[++r]=i;
		if(i>=len)
		{
			printf("%d ",a[q[l]]);
		}
	}
	printf("\n");
	memset(q,0,sizeof(q));
	l=1,r=0;
	for(int i=1;i<=n;i++)
	{
		
		while(l<=r&&q[l]+len<=i)
		{
			l++;
		}
		while(l<=r&&a[i]>a[q[r]])
		{
			r--;
		}
		q[++r]=i;
		if(i>=len)
		{
			printf("%d ",a[q[l]]);
		}
	}
	return 0;
}