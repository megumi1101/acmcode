// LUOGU_RID: 92625632
#include<bits/stdc++.h>
using namespace std;
#define int long long
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
const int N=1e5+10;
int n,m,k,f[N][205],cnt=1,ans=1e18+7;
struct node
{
	int s,t,d,w;
	friend bool operator<(node a,node b)
	{
		if(a.w==b.w)return a.d<b.d;
		return a.w<b.w;
	}
}a[N];
priority_queue<node>q;
bool cmp1(node a,node b)
{
	if(a.s==b.s)return a.t<b.t;
		return a.s<b.s;
}
void chkmin(int &a,int b){if(a>b)a=b;}
signed main()
{
	n=rid();m=rid();k=rid();
	for(int i=1;i<=k;i++)a[i]=(node){rid(),rid(),rid(),rid()};
	sort(a+1,a+1+k,cmp1);
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<=n;i++)
	{
		while(a[cnt].s<=i&&cnt<=k)q.push(a[cnt]),cnt++;
		while(!q.empty()&&q.top().t<i)q.pop();
		if(q.empty())
			for(int j=0;j<=m;j++){chkmin(f[i+1][j],f[i][j]);}
		if(!q.empty())
		{
			node u=q.top();
			for(int j=0;j<=m;j++){chkmin(f[u.d+1][j],f[i][j]+u.w);}
		}
		for(int j=0;j<=m;j++){chkmin(f[i+1][j+1],f[i][j]);}
	}
	for(int i=0;i<=m;i++)ans=min(ans,f[n+1][i]);
	printf("%lld",ans);
	return 0;
}////
