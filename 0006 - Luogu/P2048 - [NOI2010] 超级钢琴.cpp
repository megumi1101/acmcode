#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+100;
ll sum[maxn],aaa,ans;
ll n,k,L,R;
int p[maxn][20];
int cx(int l,int r)
{
	int k=log2(r-l+1);
	int x=p[l][k];
	int y=p[r-(1<<k)+1][k];
	return sum[x]>sum[y]?x:y;
}
struct node
{
	int o,l,r,pos;
	friend bool operator<(node a,node b)
	{
		return sum[a.pos]-sum[a.o-1]<sum[b.pos]-sum[b.o-1];
	}
};
priority_queue<node> q;
int main()
{
	scanf("%lld%lld%lld%lld",&n,&k,&L,&R);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&aaa);
		sum[i]=sum[i-1]+aaa;
	}
	for(int i=1;i<=n;i++)
	{
		p[i][0]=i;
	}
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			int x=p[i][j-1];
			int y=p[i+(1<<(j-1))][j-1];
			p[i][j]=sum[x]>sum[y]?x:y;
		}
	}
	//return 0;
	for(int o=1;o+L-1<=n;o++)
	{
		q.push((node){o,o+L-1,min(n,o+R-1),cx(o+L-1,min(n,o+R-1))});
	}
	//return 0;
	while(k--)
	{
		node tmp=q.top();
		q.pop();
		ans+=sum[tmp.pos]-sum[tmp.o-1];
		if(tmp.pos!=tmp.r)
		{
			q.push((node){tmp.o,tmp.pos+1,tmp.r,cx(tmp.pos+1,tmp.r)});
		}
		if(tmp.pos!=tmp.l)
		{
			q.push((node){tmp.o,tmp.l,tmp.pos-1,cx(tmp.l,tmp.pos-1)});
		}
	}
	printf("%lld",ans);
	return 0;
}