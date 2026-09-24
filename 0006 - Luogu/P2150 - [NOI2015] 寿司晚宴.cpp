#include<bits/stdc++.h>
using namespace std;
#define int long long
int p[10]={0,2,3,5,7,11,13,17,19,0};
int n,mod,dp[500][500],f1[500][500],f2[500][500];
struct node
{
	int val,big,jh;
	void init()
	{
		int tmp=val;big=-1;
		for(int i=1;i<=8;i++)
		{
			if(tmp%p[i])continue;
			jh|=(1<<i-1);
			while(tmp%p[i]==0)tmp/=p[i];
		}
		if(tmp!=1)big=tmp;
	}
}a[510];
bool cmp(node a, node b)
{
	return a.big>b.big;
}
signed main()
{
	scanf("%lld%lld",&n,&mod);
	for(int i=2;i<=n;i++)
	{
		a[i-1].val=i;
		a[i-1].init();
	}
	sort(a+1,a+n,cmp);
	dp[0][0]=1;
	for(int i=1;i<n;i++)
	{
		if(i==1||a[i].big!=a[i-1].big||a[i].big==-1)
		{
			memcpy(f1,dp,sizeof(f1));
			memcpy(f2,dp,sizeof(f2));
		}
		for(int j=255;j>=0;j--)
		{
			for(int k=255;k>=0;k--)
			{
				if(j&k)continue;
				if((a[i].jh&j)==0)f2[j][k|a[i].jh]+=f2[j][k],f2[j][k|a[i].jh]%=mod;
                if((a[i].jh&k)==0)f1[j|a[i].jh][k]+=f1[j][k],f1[j|a[i].jh][k]%=mod;
			}
		}
		if(i==n-1||a[i].big!=a[i+1].big||a[i].big==-1)
		{
            for(int j=0;j<=255;j++)
			{
                for(int k=0;k<=255;k++)
				{
                    if(j&k) continue;
                    dp[j][k]=f1[j][k]+f2[j][k]+mod-dp[j][k];
                    dp[j][k]%=mod;
                }
            }
        }		
	}
	int ans=0;
	for(int j=0;j<=255;j++)
	{
       for(int k=0;k<=255;k++)
	   {
            if((j&k)==0&&dp[j][k])ans+=dp[j][k],ans%=mod;
       }
	}
	printf("%lld",ans);
	return 0;
}