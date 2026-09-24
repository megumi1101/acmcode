#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int f[100],x,y,k,ans;
signed main()
{
	scanf("%lld",&k);
	f[1]=f[2]=1;
	for(int i=3;i<=92;i++){f[i]=f[i-1]+f[i-2];}
	for(int i=1;f[i+2]<=k;i++)
	{
		int q=pow(-1,i-1);
		x=f[i+3]*k*q;
		y=f[i+2]*k*(-q);
		if(x<0)
		{
			y-=(abs(x)/f[i+1]+1)*f[i];
			if(y>0)ans+=ceil(1.0*y/f[i]),ans%=mod;
		}
		else if(y<0)
		{
			x-=(abs(y)/f[i]+1)*f[i+1];
			if(x>0)ans+=ceil(1.0*x/f[i+1]),ans%=mod;
		}
	}
	printf("%lld",ans);
	return 0;
}