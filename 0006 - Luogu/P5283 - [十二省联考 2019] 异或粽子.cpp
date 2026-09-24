#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int n,k;
int a[maxn],ans,top=1;
int cnt[maxn<<5],ch[maxn<<5][2];
void ins(int x)
{
	int u=1;
	cnt[u]++;
	for(int i=33;i>=0;i--)
	{
		int t=(x>>i)&1ll;
		if(!ch[u][t])ch[u][t]=++top;
		u=ch[u][t];cnt[u]++;
	}
}
int cx(int x,int k)
{
	int u=1,ans=0;
	for(int i=33;i>=0;i--)
	{
		int t=(x>>i)&1ll;
		if(cnt[ch[u][t]]>=k)u=ch[u][t];
		else k-=cnt[ch[u][t]],u=ch[u][t^1],ans|=(1ll<<i);
	}
	return ans;
}
struct node
{
	int id,rk,val;
	friend bool operator<(node a,node b)
	{
		return a.val<b.val;
	}
};
priority_queue<node>q;
signed main()
{
	scanf("%lld%lld",&n,&k);
	ins(0);
	k*=2;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]^=a[i-1];
		ins(a[i]);
	}
	for(int i=0;i<=n;i++)q.push({i,n+1,cx(a[i],n+1)});
	while(k--)
	{
		node x=q.top();q.pop();
		ans+=x.val;
		if(x.rk)q.push({x.id,x.rk-1,cx(a[x.id],x.rk-1)});
	}
	printf("%lld",ans/2);
	return 0;
}