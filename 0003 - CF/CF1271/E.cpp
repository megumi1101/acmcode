// LUOGU_RID: 92677557
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k,bin[64],ans;
bool ck1(int x)
{
	int cnt=0;
	for(int i=0;i<=62;i++)
	{
		if(bin[i]*x>n)break;
		int res=n-bin[i]*x+1;
		cnt+=min(bin[i],res);
	}
	if(cnt>=k)return 1;
	else return 0;
}
bool ck2(int x)
{
	int cnt=0;
	for(int i=0;i<=62;i++)
	{
		if(bin[i]*x>n)break;
		int res=n-bin[i]*x+1;
		cnt+=min(bin[i+1],res);
	}
	if(cnt>=k)return 1;
	else return 0;
}
signed main()
{
	scanf("%lld%lld",&n,&k);
	if(n==k){puts("1");return 0;}
	bin[0]=1;for(int i=1;i<=63;i++)bin[i]=bin[i-1]*2;
	int l=0,r=(n-1)/2;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(ck1(2*mid+1))l=mid;
		else r=mid-1;
	}
	ans=2*l+1;
	l=1,r=n/2;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(ck2(2*mid))l=mid;
		else r=mid-1;
	}
	ans=max(ans,2*l);
	printf("%lld ",ans);
	return 0;
}
////
