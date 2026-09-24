#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=2e5+10;
const ll dx[] = {1, -1, -1, 1};
const ll dy[] = {-1, -1, 1, 1};
ll n,m,k,x,y,d,tx,ty,td,ans,cs=1;
char ss[3];
map<ll,ll>mp[maxn];
set<pair<ll,ll> >s[2][maxn];
void add(ll a,ll b)
{
	mp[a][b]=1;
	s[0][a+b].insert(make_pair(a,b));
	s[1][b-a+n].insert(make_pair(a,b));
}
void work(ll opt)
{
	set<pair<ll,ll> >:: iterator it=s[d&1][d&1?y-x+n:x+y].lower_bound(make_pair(x,y));
	if(d==1||d==2)--it;
	if(opt)ans+=abs(x-(*it).first);
	x=(*it).first-dx[d];
	y=(*it).second-dy[d];
	ll cnt=mp[x+dx[d]].count(y)+mp[x].count(y+dy[d]);
	if(cnt==0||cnt==2)cs=2,d^=2;
	else if(mp[x+dx[d]].count(y))y+=dy[d],d^=1;
	else x+=dx[d],d^=3;
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		ll a,b;
		scanf("%lld%lld",&a,&b);
		add(a,b);
	}
	for(int i=0;i<=n+1;i++)
	{
		add(i,0);
		add(i,m+1);
	}
	for(int i=1;i<=m;i++)
	{
		add(0,i);
		add(n+1,i);
	}
	scanf("%lld%lld",&x,&y);
	scanf("%s",ss);
	if(ss[0]=='S')d+=2;
	if(ss[0]=='S'&&ss[1]=='E')d++;
	if(ss[0]=='N'&&ss[1]=='W')d++;
	work(0);
	tx=x,ty=y,td=d;
	work(1);
	while(x!=tx||y!=ty||d!=td)
	{
		work(1);
	}
	printf("%lld\n",ans/cs);
	return 0;
}
