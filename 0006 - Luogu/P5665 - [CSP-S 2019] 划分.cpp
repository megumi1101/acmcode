#include<bits/stdc++.h>
const int maxm=1e5+10;
const int maxn=4e7+10;
const int mod=(1<<30);
int n,m,x,y,z,tp;
int a[maxn],b[maxn],l[maxm],r[maxm],p[maxm],pre[maxn],q[maxn];
long long sum[maxn];
#define s(i) sum[i]-sum[pre[i]]
using namespace std;
int main()
{
	scanf("%d%d",&n,&tp);
	if(tp)
	{
		scanf("%d%d%d%d%d%d",&x,&y,&z,&b[1],&b[2],&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&p[i],&l[i],&r[i]);
		}
		for(int i=3;i<=n;i++)
		{
			b[i]=(0LL+1LL*b[i-1]*x+1LL*b[i-2]*y+z)%mod;
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=p[i-1]+1;j<=p[i];j++)
			{
				a[j]=(b[j]%(r[i]-l[i]+1))+l[i];
				sum[j]=sum[j-1]+a[j];
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
	}
	int l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&sum[q[l+1]]+s(q[l+1])<=sum[i])++l;
		pre[i]=q[l];
		while(l<r&&sum[q[r]]+s(q[r])>=sum[i]+s(i))--r;
		q[++r]=i;
	}
	int u=n;
	__int128 ans=0,tmp=1;
	while(u)
	{
		tmp=s(u);
		tmp*=s(u);
		ans+=tmp;
		u=pre[u];
	}
	int as[50],cnt=0;
	while(ans)
	{
		as[++cnt]=ans%10;
		ans/=10;
	}
	while(cnt)
	{
		printf("%d",as[cnt--]);
	}
	return 0;
}