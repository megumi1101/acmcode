#include<bits/stdc++.h>
using namespace std;
int n,m,w,q[2002],dp[2002][2002],ap,bp,as,bs,l,r,ans;
int main()
{
	scanf("%d%d%d",&n,&m,&w);
	memset(dp,128,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&ap,&bp,&as,&bs);
		for(int j=0;j<=as;j++)
		{
			dp[i][j]=-1*ap*j;
		}
		for(int j=0;j<=m;j++)
		{
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}	
		if(i<=w)continue;
		l=1;r=0;
		for(int j=0;j<=m;j++)
		{
			while(l<=r&&q[l]<j-as)
			{
				l++;
			}
			while(l<=r&&dp[i-w-1][j]+j*ap>dp[i-w-1][q[r]]+q[r]*ap)
			{
				r--;
			}
			q[++r]=j;
			if(l<=r)
			{
				dp[i][j]=max(dp[i][j],dp[i-w-1][q[l]]+q[l]*ap-j*ap);
			}
		}
		l=1;r=0;
		for(int j=m;j>=0;j--)
		{
			while(l<=r&&q[l]>j+bs)
			{
				l++;
			}
			while(l<=r&&dp[i-w-1][j]+j*bp>dp[i-w-1][q[r]]+q[r]*bp)
			{
				r--;
			}
			q[++r]=j;
			if(l<=r)
			{
				dp[i][j]=max(dp[i][j],dp[i-w-1][q[l]]+q[l]*bp-j*bp);
			}
		}
	}
	for(int i=0;i<=m;i++)
	{
		ans=max(ans,dp[n][i]);
	}
	printf("%d",ans);
	return 0;
}