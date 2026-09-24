    #include<bits/stdc++.h>
    using namespace std;
    int dp[45][127][127];
    int n,m;
    int get(int num)
    {
        int res=0;
        for(int i=1;i<=m;i++)
    	{
            res+=((num&1)==0);
            num>>=1;
        }
        return res;
    }
    bool check(int j,int k,int l)
    {
        int a,b,c,d,e;
        for(int i=1;i<=m;i++)
    	{
        	a=(j&(1<<(i-1)));
        	b=(k&(1<<(i-1)));
        	c=(l&(1<<(i-1)));
        	if(i!=1)d=(k&(1<<(i-2)));	
        	else d=0;
        	if(i!=m)e=(k&(1<<i));
        	else e=0;
        	if(!(a||b||c||d||e)) return 0;
        }
        return 1;
    }
    int main(){
        scanf("%d%d",&n,&m);
        if(m>n)swap(m,n);
        int top=(1<<m)-1;
        for(int i=0;i<=top;i++)
            for(int j=0;j<=top;j++)
                dp[0][i][j]=-1e8;
        for(int i=0;i<=top;i++) dp[0][0][i]=0;
        for(int dep=1;dep<=n;dep++)
            for(int k=0;k<=top;k++)
                for(int i=0;i<=top;i++)
                    for(int j=0;j<=top;j++)
                        if(check(k,i,j))
                        dp[dep][i][j]=max(dp[dep][i][j],dp[dep-1][k][i]+get(i));
        int ans=0;
        for(int i=0;i<=top;i++)ans=max(ans,dp[n][i][0]);
        printf("%d\n",ans);
        return 0;
    } 
