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
const int mod=1e9+7,N=1e5+10;
int fap(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;b>>=1;
	}
	return res;
}
int n,m,siz,t[20][N],lg[N],cnt,fa[20*N];
bool vis[N];
void init(){int i=1;for(int j=2;j<=n;j++){if(j==(1<<(i+1)))i++;lg[j]=i;}}
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void hb(int x,int y){fa[find(x)]=find(y);}
void zh(int x,int &y){x%=n;y=x?x:n;}
signed main()
{
	n=rid();m=rid();init();
	for(int i=0;i<=lg[n];i++)for(int j=1;j<=n;j++)t[i][j]=++cnt;
	for(int i=1;i<=cnt;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int l=rid(),r=rid(),len=rid(),d=rid();
		d=len-l;len=r-l+1;
		for(int k=0;len;len>>=1,k++)
		{
			if(len&1)
			{
				int o=l+((len>>1)<<(k+1)),p=o+d;
				hb(t[k][o],t[k][p]);
			}
		}	
	}
	for(int i=lg[n];i>=1;i--)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			int fat=find(t[i][j]);
			if(fat==t[i][j]){continue;}
			int y;zh(fat,y);
			hb(t[i-1][j],t[i-1][y]);
			hb(t[i-1][j+(1<<(i-1))],t[i-1][y+(1<<(i-1))]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int fat=find(t[0][i]);
		int y;zh(fat,y);
		if(!vis[y]){vis[y]=1;siz++;}
	}
	printf("%lld",(9*fap(10,siz-1))%mod);
	return 0;
}
