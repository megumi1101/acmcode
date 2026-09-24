#include<bits/stdc++.h>
using namespace std;
const int mx=4e4+10;
int n,W,dp[mx];
int ans,q[mx],q2[mx];
int main()
{
	scanf("%d%d",&n,&W);
	for(int i=1;i<=n;i++)
	{
		int v,w,c;
		scanf("%d%d%d",&v,&w,&c);
		if(w==0)
		{
			ans+=v*c;
			continue;
		}
		c=min(c,W/w);
		for(int d=0;d<w;d++)
		{
			int l=1,r=0;
			for(int s=0;w*s+d<=W;s++)
			{
				while(l<=r&&q2[r]<=dp[w*s+d]-v*s)r--;
				q[++r]=s;
				q2[r]=dp[w*s+d]-v*s;
				while(l<=r&&q[l]<s-c)l++;
				dp[w*s+d]=max(dp[w*s+d],q2[l]+v*s);
			}
		}
	}
	printf("%d",ans+dp[W]);
	return 0;
}