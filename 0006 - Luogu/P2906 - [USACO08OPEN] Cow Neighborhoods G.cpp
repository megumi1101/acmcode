#include<bits/stdc++.h>
using namespace std;
#define pl pair<long long,long long>
#define int long long
#define mk make_pair
#define fi first
#define se second
set<pl>s;
const int maxn=1e5+10;
int n,c,fa[maxn],cnt[maxn];
pl a[maxn];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void hb(int x,int y)
{
	fa[find(x)]=find(y);
}
signed main()
{
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		a[i]=mk(x+y,x-y);
		fa[i]=i;
	}
	sort(a+1,a+n+1);
	s.insert(mk(-1LL<<60,0));
	s.insert(mk(1LL<<60,0));
	s.insert(mk(a[1].se,1));
	for(int j=1,i=2;i<=n;i++)
	{
		while(a[i].fi-a[j].fi>c)
		{
			s.erase(mk(a[j].se,j)),j++;
		}
		set<pl>::iterator it=s.lower_bound(mk(a[i].se,0));
		if(it->fi-a[i].se<=c)hb(i,it->se);
		it--;
		if(a[i].se-it->fi<=c)hb(i,it->se);
		s.insert(mk(a[i].se,i));
	}
	int ans=0,mx=0;
	for(int i=1;i<=n;i++)
	{
		ans+=(find(i)==i);
		mx=max(mx,++cnt[find(i)]);
	}
	printf("%lld %lld\n",ans,mx);
	return 0;
}