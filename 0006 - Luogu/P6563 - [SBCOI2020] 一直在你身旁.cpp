#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=8e3;
int a[maxn],q[maxn];
int f[maxn][maxn];
signed main()
{
	int t;
	scanf("%lld",&t);
	while(t--)
	{
		int n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)f[i][i]=0;
		for(int j=2;j<=n;j++)
		{
			int l=1,r=0;
			int pos=j;
			for(int i=j-1;i>=1;i--)
			{
				if(i==j-1)
				{
					f[i][j]=a[i];
					continue;
				}
				while(pos>i&&f[pos][j]<f[i][pos-1])pos--;
				f[i][j]=f[i][pos]+a[pos];
				while(l<=r&&q[l]>=pos)l++;
				if(l<=r)f[i][j]=min(f[q[l]+1][j]+a[q[l]],f[i][j]);
				while(l<=r&&f[q[r]+1][j]+a[q[r]]>=f[i+1][j]+a[i])r--;
				q[++r]=i;
			}
		}
		printf("%lld\n",f[1][n]);
	}
	return 0;
}