#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long mod=1000000007;
struct mat
{
	ll a[2][2];
	friend mat operator*(mat x,mat y)
	{
		mat tmp;
		for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		{
			tmp.a[i][j]=0;
		}
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=1;j++)
			{
				for(int k=0;k<=1;k++)
				{
					tmp.a[i][j]=(tmp.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
				}
			}
		}
		return tmp;
	}
};
mat qp(mat x,ll k)
{
	mat ret;
	ret.a[0][0]=ret.a[1][1]=1;
	ret.a[1][0]=ret.a[0][1]=0;
	while(k)
	{
		if(k&1)
		{
			ret=ret*x;
		}
		k>>=1;
		x=x*x;
	}
	return ret;
}
int main()
{
	ll n;
	scanf("%lld",&n);
	mat kk;
	kk.a[0][0]=kk.a[1][0]=kk.a[0][1]=1;
	kk.a[1][1]=0;
	if(n<=2)
	{
		printf("1");
		return 0;
	}
	mat tt=qp(kk,n-2);
	ll ans=tt.a[0][0]+tt.a[0][1];
	ans%=mod;
	printf("%lld",ans);
	return 0;
}