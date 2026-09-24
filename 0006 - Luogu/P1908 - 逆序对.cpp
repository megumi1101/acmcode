#include<bits/stdc++.h>
#define ll long long
#define maxn 500010
using namespace std;
int n;
ll sum[maxn],b[maxn],ans,cnt;
struct node
{
	int v,bh;
}a[maxn];
int lb(int x)
{
	return x&(-x);
}
bool cmp(node a,node b)
{
	return a.v<b.v;
}
void insert(int x)
{
	while(x<=cnt)
	{
		sum[x]++;
		x+=lb(x);
	}	
}
ll cx(int x)
{
	ll res=0;
	while(x)
	{
		res+=sum[x];
		x-=lb(x);
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].v);
		a[i].bh=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].v!=a[i-1].v)
		{
			cnt++;
		}
		b[a[i].bh]=cnt;
	}
	for(int i=1;i<=n;i++)
	{
		insert(b[i]);
		ans+=i-cx(b[i]);
	}
	printf("%lld",ans);
	return 0;
}