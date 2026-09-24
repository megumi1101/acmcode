// LUOGU_RID: 91820638
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,mod=998244353;
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int n,f[N],p,inv[105];
signed main()
{
	n=rid();
	inv[1]=1;
	for(int i=2;i<=100;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	for(int i=1;i<=n;i++)p=rid(),f[i]=(f[i-1]+1)*100%mod*inv[p]%mod;
	printf("%lld",f[n]);
	return 0;
}
