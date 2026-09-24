#include<bits/stdc++.h>
using namespace std;
const int maxn=800,mod=1e9+7,M=6e6;
int a[maxn][maxn],qz[maxn],cnt;
int sum[M],lt[M],rt[M];
int n,m,dp[maxn][maxn];
void pushup(int a)
{
	sum[a]=sum[lt[a]]+sum[rt[a]];
	sum[a]%=mod;
}
void update(int &a,int l,int r,int p,int k)
{
	if(!a)a=++cnt;
	if(l==r)
	{
		sum[a]+=k;
		sum[a]%=mod;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) update(lt[a],l,mid,p,k);
	else update(rt[a],mid+1,r,p,k);
	pushup(a);
}
int cx(int a,int l,int r,int cl,int cr)
{
	if(!a)return 0;
	if(cl<=l&&r<=cr)return sum[a];
	int mid=(l+r)>>1;
	int res=0;
	if(cl<=mid)res=(res+cx(lt[a],l,mid,cl,cr))%mod;
	if(cr>mid) res=(res+cx(rt[a],mid+1,r,cl,cr))%mod;
	return res;	
}
int main()
{
	scanf("%d%d%d",&n,&m,&cnt);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<m;i++)qz[i]=1;
	dp[1][1]=1;
	update(a[1][1],1,m,1,1);
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			dp[i][j]=(qz[j-1]-cx(a[i][j],1,m,1,j-1)+mod)%mod;
			//printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
		int res=0;
		for(int j=2;j<=m;j++)
		{
			res=(res+dp[i][j])%mod;
			qz[j]=(qz[j]+res)%mod;
			update(a[i][j],1,m,j,dp[i][j]);
		}
	}
	printf("%d",dp[n][m]);
	return 0;
}