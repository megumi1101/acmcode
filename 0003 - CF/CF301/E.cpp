    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    const int mod=1e9+7,maxn=109;
    int c[maxn][maxn],n,m,K,dp[2][maxn][maxn][maxn],ans;
    void add(int &x,int y){x=(x+y>=mod)?x+y-mod:x+y;}
    signed main()
    {
    	scanf("%lld%lld%lld",&n,&m,&K);n++;
    	c[0][0]=1;
    	for(int i=1;i<=K;i++)
    		for(int j=0;j<=i;j++){
    			c[i][j]=(j?c[i-1][j-1]:0)+c[i-1][j];
    			if(c[i][j]>K)c[i][j]=K+1;
    		}
    	bool op=1;
    	dp[op][0][1][1]=1;
    	for(int i=1;i<=m;i++)
    	{
    		op^=1;
    		memset(dp[op],0,sizeof(dp[op]));
    		for(int j=0;j<=n;j++)
    			for(int k=1;k<=n;k++)
    				for(int l=1;l<=K;l++)
    					if(dp[op^1][j][k][l])
    						for(int t=k;t<=n-j;t++)
    							if(l*c[t-1][k-1]<=K)
    								add(dp[op][j+t][t-k][l*c[t-1][k-1]],dp[op^1][j][k][l]);
    		int tmp=0;
    		for(int j=2;j<=n;j++)
    			for(int l=1;l<=K;l++)add(tmp,dp[op][j][0][l]);
    		add(ans,tmp*(m-i+1)%mod);
    	}
    	printf("%lld",ans);
    	return 0;
    }

