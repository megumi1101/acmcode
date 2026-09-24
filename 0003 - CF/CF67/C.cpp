#include<bits/stdc++.h>
using namespace std;
const int maxn=4e3+10;
int n,m,c1,c2,c3,c4,p1,p2;
int dp[maxn][maxn],pos1[maxn][26],pos2[maxn][26];
char s1[maxn],s2[maxn];
void init()
{
	for(int i=1;i<=n+1;i++)
	{
		for(int j=0;j<26;j++)
			pos1[i][j]=pos1[i-1][j];
		if(i>1)pos1[i][s1[i-1]-'a']=i-1;
	}
	for(int i=1;i<=m+1;i++)
	{
		for(int j=0;j<26;j++)
			pos2[i][j]=pos2[i-1][j];
		if(i>1)pos2[i][s2[i-1]-'a']=i-1;
	}
}
int main()
{
	scanf("%d%d%d%d%s%s",&c1,&c2,&c3,&c4,s1+1,s2+1);
	n=strlen(s1+1),m=strlen(s2+1);
	init();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for (int i=0;i<=n;++i)
	{
		for (int j=0;j<=m;++j)
		{
			if(j>0) dp[i][j]=min(dp[i][j],dp[i][j-1]+c1);
			if(i>0) dp[i][j]=min(dp[i][j],dp[i-1][j]+c2);
			if(i&&j)
			{
				if (s1[i]==s2[j]) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
				else dp[i][j]=min(dp[i][j],dp[i-1][j-1]+c3);
				int p1=pos1[i][s2[j]-'a'],p2=pos2[j][s1[i]-'a'];
				if (p1&&p2) dp[i][j]=min(dp[i][j],dp[p1-1][p2-1]+(i-p1-1)*c2+(j-p2-1)*c1+c4);
			}
		}
	}
	printf("%d",dp[n][m]);
	return 0;
}
