    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    const int maxn=1e6+10,mod=1e9+7;
    int n,k,sum,num,fm,jc[maxn],ans,qz[maxn],hz[maxn];
    int fp(int a,int b)
    {
        int res=1;
        while(b)
        {
            if(b&1)res=res*a%mod;
            a=a*a%mod;b>>=1;
        }
        return res;
    }
    signed main()
    {
    	scanf("%lld%lld",&n,&k);jc[0]=1;
    	for(int i=1;i<=k+2;i++)jc[i]=jc[i-1]*i%mod;
    	qz[0]=hz[k+3]=1;
    	for(int i=1;i<=k+2;i++)qz[i]=qz[i-1]*(n-i)%mod;
    	for(int i=k+2;i>=1;i--)hz[i]=hz[i+1]*(n-i)%mod;
    	for(int i=1;i<=k+2;i++)
    	{
    		(sum+=fp(i,k))%=mod;
    		num=qz[i-1]*hz[i+1]%mod;
    		fm=jc[i-1]*jc[k+2-i]%mod;
    		(num*=(sum*fp(fm,mod-2)%mod))%=mod;
    		if((k+2-i)&1)ans+=mod-num;
    		else ans+=num;ans%=mod;
    	}
    	printf("%lld",ans);
    	return 0;
    }
