#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
int fap(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int a[10][10]={
	{0},
	{0,2,4},
	{0,0,12,36},
	{0,0,0,112,336},
	{0,0,0,0,912,2688},
	{0,0,0,0,0,7136,21312},
	{0,0,0,0,0,0,56768,170112},
	{0,0,0,0,0,0,0,453504,1360128},
	{0,0,0,0,0,0,0,0,3626752,10879488}
};
signed main()
{
	scanf("%lld%lld",&n,&m);
	if(n>m)swap(n,m);
	if(n==1)printf("%lld",fap(2,m));
	else{
		if(n==m)printf("%lld",a[n][m]);
		else printf("%lld\n",a[n][n+1]*fap(3,m-n-1)%mod);
	}
}