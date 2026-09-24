#include<bits/stdc++.h>
using namespace std;
int n,m,a[101010];
int f[101010][22];
int mm(int l,int r)
{
	int k=log2(r-l+1);
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		f[i][0]=a[i];
	}
	for(int j=1;j<=21;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	while(m--)
	{
		int ll,rr;
		scanf("%d%d",&ll,&rr);
		printf("%d\n",mm(ll,rr));
	}	
}