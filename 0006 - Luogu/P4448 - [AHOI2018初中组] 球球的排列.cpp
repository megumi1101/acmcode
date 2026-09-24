#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=305,mod=1e9+7;
int fa[maxn],a[maxn],b[maxn],cnt,f[2][maxn][maxn],n;
bool op=0;
bool sq(int x)
{
	return (int)sqrt(x)*(int)sqrt(x)==x;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);b[i]=i;
		for(int j=1;j<i;j++)if(sq(a[i]*a[j])){b[i]=j;break;}
	}
	sort(b+1,b+1+n);
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		op^=1;memset(f[op],0,sizeof(f[op]));
		if(b[i]!=b[i-1])
		{
			cnt=0;
			for(int j=0;j<i;j++)
				for(int k=0;k<=j+1;k++)
				{
					if(k<=j)(f[op][j][0]+=f[op^1][k][j-k]*(i-j)%mod)%=mod;
					(f[op][j][0]+=f[op^1][k][j-k+1]*(j+1)%mod)%=mod;
				}
		}
		else
		{
			for(int j=0;j<i;j++)
				for(int k=0;k<=cnt;k++)
				{
					if(k)(f[op][j][k]+=f[op^1][j][k-1]*(cnt*2-k+1)%mod)%=mod;
					(f[op][j][k]+=f[op^1][j+1][k]*(j+1)%mod)%=mod;
					(f[op][j][k]+=f[op^1][j][k]*(i-cnt*2+k-j)%mod)%=mod;
				}
		}cnt++;
	}
	printf("%lld",f[op][0][0]);
	return 0;
}