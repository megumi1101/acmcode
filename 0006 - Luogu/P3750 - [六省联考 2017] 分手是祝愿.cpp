#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10,mod=100003;
int n,k,tmp,cnt;
int jc[maxn],jj[maxn],inv[maxn],op[maxn],f[maxn];
void init()
{
	jc[0]=jc[1]=jj[0]=jj[1]=inv[1]=1;
	for(int i=2;i<=n;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	}
}
signed main()
{
	scanf("%lld%lld",&n,&k);
	init();
	for(int i=1;i<=n;i++)scanf("%lld",&op[i]);
	for(int i=n;i>=1;i--)
	{
		if(op[i])
		{
			cnt++;
			for(int j=1;j*j<=i;j++)
			{
				if(i%j==0)
				{
					op[j]^=1;
					if(j*j!=i)op[i/j]^=1;
				}
			}
		}
	}
	for(int i=n;i>=1;i--)
	{
		tmp=(n-i)*f[i+1]%mod;
		tmp+=n;tmp%=mod;
		tmp=tmp*inv[i]%mod;
		f[i]=tmp;
	}
	tmp=0;
	if(cnt<=k)
	{
		tmp=cnt;
	}
	else
	{
		for(int i=cnt;i>k;i--)
		{
			tmp+=f[i];tmp%=mod;
		}
		tmp+=k;tmp%=mod;
	}
	tmp=tmp*jc[n]%mod;
	printf("%lld",tmp);
}