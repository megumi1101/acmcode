#include<bits/stdc++.h>
using namespace std;
#define int long long
#define db double
const db inf=1e12+10;
const int maxn=3e3+10;
int n,m,q[maxn];
db s[maxn],g[maxn],f[maxn];
db X(int i){return s[i];}
db Y(int i){return g[i]+s[i]*s[i];}
db xl(int i,int j){return (Y(i)-Y(j))/(X(i)-X(j));}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lf",&s[i]),s[i]+=s[i-1];
	for(int i=0;i<=n;i++)g[i]=inf,f[i]=inf;
	g[0]=0;
	for(int j=1;j<=m;j++)
	{
		int l=1,r=0;
		q[++r]=0;
		for(int i=1;i<=n;i++)
		{
			while(l<r&&xl(q[l],q[l+1])<=2*s[i])l++;
			f[i]=g[q[l]]+(s[i]-s[q[l]])*(s[i]-s[q[l]]);
			while(l<r&&xl(q[r-1],q[r])>xl(q[r],i))r--;
			q[++r]=i;
		}
		memcpy(g,f,sizeof(g));
	}
	
	printf("%lld",m*(int)f[n]-(int)s[n]*(int)s[n]);
	return 0;
}