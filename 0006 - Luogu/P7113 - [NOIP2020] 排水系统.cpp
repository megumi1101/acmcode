#include<bits/stdc++.h>
using namespace std;
#define int __int128
const int N=1e5+10;
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
void inline print(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');	
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
struct node{int x,y;}a[N];
int n,m,d[N],rd[N];
vector<int>ed[N];
queue<int>q;
void yf(node &u)
{
	int f=gcd(u.x,u.y);
	u.x/=f,u.y/=f;
}
void up(node u,node &v)
{
	if(v.x==0&&v.y==0){v.x=u.x;v.y=u.y;return;}
	v.x=u.x*v.y+v.x*u.y;v.y=u.y*v.y;yf(v);
}
signed main()
{
	n=rid();m=rid();
	for(int i=1;i<=n;i++)
	{	
		d[i]=rid();
		for(int j=1;j<=d[i];j++)
		{
			int v=rid();
			ed[i].push_back(v);rd[v]++;
		}
	}
	for(int i=1;i<=n;i++){if(!rd[i])q.push(i),a[i].x=a[i].y=1;};
	while(!q.empty())
	{
		int u=q.front();q.pop();
		int siz=ed[u].size();
		if(siz)a[u].y*=siz;
		yf(a[u]);
		for(int i=0;i<siz;i++)
		{
			int v=ed[u][i];
			up(a[u],a[v]);
			rd[v]--;if(!rd[v])q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
		if(!d[i])print(a[i].x),printf(" "),print(a[i].y),printf("\n");
	return 0;
}
