#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m;
long long ans;
struct node
{
	int x,y;
}a[maxn],b[maxn];
bool cmp(node a,node b)
{
	return a.y>b.y;
}
multiset<int> p;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i].x,&b[i].y);
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+m,cmp);
	int pos=1;
	for(int i=1;i<=n;i++)
	{
		while(pos<=m&&b[pos].y>=a[i].y)
		{
			p.insert(b[pos++].x);
		}
		multiset<int>::iterator it=p.lower_bound(a[i].x);		
		if(it==p.end())
		{
			printf("-1");
			return 0;
		}
		else
		{
			ans+=*it;
			p.erase(it);
		}
	}
	printf("%lld",ans);
	return 0;
}