#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int n,p[maxn],mod;
signed main()
{
	scanf("%lld%lld",&n,&mod);
	p[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int k=j*(3*j-1)/2,op=(j&1)?1:-1;
			if(k>i)break;
			p[i]+=op*p[i-k];p[i]+=mod;p[i]%=mod;
			k=j*(3*j+1)/2;
			if(k>i)break;
			p[i]+=op*p[i-k];p[i]+=mod;p[i]%=mod;
		}
	}
	printf("%lld",p[n]);
	return 0;
}