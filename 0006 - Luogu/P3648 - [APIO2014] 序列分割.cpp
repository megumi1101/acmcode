#include<bits/stdc++.h>
using namespace std;
#define int long long
#define db long double
const int maxn=1e5+10;
int n,k,p[maxn][205],q[maxn];
db f[maxn],g[maxn],s[maxn];
db xl(int i,int j)
{
	if(s[i]==s[j])return -1e15;
	return (g[i]-s[i]*s[i]-g[j]+s[j]*s[j])/(s[j]-s[i]);
}
signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%Lf",&s[i]),s[i]+=s[i-1];
	for(int j=1;j<=k;j++)
	{
		int l=1,r=0;
		q[++r]=0;
		for(int i=1;i<=n;i++)
		{
			while(l<r&&xl(q[l],q[l+1])<s[i])l++;
			f[i]=g[q[l]]+s[q[l]]*(s[i]-s[q[l]]);
			p[i][j]=q[l];
			while(l<r&&xl(q[r-1],q[r])>xl(q[r],i))r--;
			q[++r]=i;			
		}
		memcpy(g,f,sizeof(g));
	}
	printf("%lld\n",(int)f[n]);
	for(int x=n,i=k;i>=1;i--)
	{
		x=p[x][i];
		printf("%lld ",x);		
	}
	return 0;
}