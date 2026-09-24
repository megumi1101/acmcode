#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1010;
int n,m,k,mod,lin[maxn],mul[maxn],ans=1,p2p[maxn];
bool fg;
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	if((n+m)&1){puts("0");return 0;}
	if(n<m)swap(n,m),fg=1;
	for(int i=1;i<=n;i++)mul[i]=1;
	for(int i=1,x,y,z;i<=k;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		if(fg)swap(x,y);
		lin[x]++;mul[x]*=z;
	}
	scanf("%lld",&mod);
	p2p[0]=1;
	for(int i=1;i<=n;i++)p2p[i]=p2p[i-1]*2%mod;
	for(int i=1;i<n;i++)
		if(!lin[i]){swap(lin[i],lin[n]);swap(mul[i],mul[n]);break;}
	for(int i=1;i<n&&ans;i++)
	{
		if(lin[i]==m&&mul[i]==1)ans=0;
		if(lin[i]<m)ans=ans*p2p[m-lin[i]-1]%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
/////
