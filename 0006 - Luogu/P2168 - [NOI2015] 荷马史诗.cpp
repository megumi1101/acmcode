#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int num,len;
	friend bool operator<(node a,node b)
	{
		if(a.num==b.num)
		{
			return a.len>b.len; 
		}
		return a.num>b.num;
	}
};
int n,k,w,ans;
priority_queue<node> q;
signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&w);
		q.push((node){w,0});
	}
	while((q.size()-1)%(k-1)!=0)
	{
		q.push((node){0,0});
	}
	while(q.size()>=k)
	{
		int hei=-1,nu=0;
		for(int i=1;i<=k;i++)
		{
			node tmp=q.top();
			q.pop();
			hei=max(hei,tmp.len);
			nu+=tmp.num;
		}
		q.push((node){nu,hei+1});
		ans+=nu;
	}
	printf("%lld\n%lld",ans,q.top().len);
	return 0;
}