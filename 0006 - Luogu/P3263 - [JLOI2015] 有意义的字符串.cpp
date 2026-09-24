#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll b,d,n,ans;
const ll mod=7528443412579576937;
ll add(ll a, ll b)
{
	return ((ull)a+(ull)b)%mod;
}
ll mul(ll a,ll b)
{
	ll res=0;
	while(b)
	{
		if(b&1)res=add(res,a);
		b>>=1;a=add(a,a);
	}
	return res;
}
struct node
{
	ll a[2][2];
	node(){memset(a,0,sizeof(a));}
	friend node operator*(node a,node b)
	{
		node c;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				for(int k=0;k<2;k++)
				{
					c.a[i][j]=add(c.a[i][j],mul(a.a[i][k],b.a[k][j]));
				}
			}
		}
		return c;
	}	
}b1,b2;
node fap(node x,ll b)
{
	node res;
	res.a[0][0]=1;
	res.a[1][1]=1;
	while(b)
	{
		if(b&1)res=res*x;
		b>>=1;x=x*x;
	}
	return res;
}
int main()
{
	scanf("%lld%lld%lld",&b,&d,&n);
	if(n==0){printf("1");return 0;}
	b1.a[0][0]=b;
	b1.a[0][1]=2;
	b2.a[0][0]=b;b2.a[0][1]=1;
	b2.a[1][0]=(d-b*b)/4;
	b2=fap(b2,n-1);
	b1=b1*b2;
	ans=b1.a[0][0];
	if((n%2==0)&&(b*b!=d))ans--;
	printf("%lld",ans);
	return 0;
}