#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+10;
int ans,s[maxn][maxn],n,x,p,m,a[maxn],b[maxn];
int fp(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%p;
		a=a*a%p;b>>=1;
	}
	return res;
}
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&x,&p,&m);
	s[0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			(s[i][j]=s[i-1][j-1]+j*s[i-1][j]%p)%=p;
	for(int i=0;i<=m;i++)scanf("%lld",&a[i]);
	for(int i=0;i<=m;i++)
		for(int j=i;j<=m;j++)
			(b[i]+=s[j][i]*a[j]%p)%=p;
	(ans+=b[0]*fp(x+1,n)%p)%=p;
	int tmp=1;
	for(int i=1;i<=m;i++)
	{
		(tmp*=(n-i+1))%=p;
		(ans+=b[i]*tmp%p*fp(x,i)%p*fp(x+1,n-i)%p)%=p;
	}
	printf("%lld",ans);
	return 0;
}