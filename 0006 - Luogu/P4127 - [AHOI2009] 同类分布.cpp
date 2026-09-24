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
void op()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
int n,f[24][200][200][2],a[25],cnt,bin[24],ans;
int dfs(int i,int j,int k,int lin,int x)
{
	if(f[i][j][k][lin]!=-1)return f[i][j][k][lin];
	int &tmp=f[i][j][k][lin];tmp=0;
	if(i==0){if(j==x&&k==0)tmp++;return tmp;}
	for(int u=0;u<=9;u++)
	{
		if(lin&&u>a[i])break;
		tmp+=dfs(i-1,j+u,(k+bin[i-1]*u)%x,lin&&(u==a[i]),x);
	}
	return tmp;
}
signed main()
{
	//op();
	n=rid();n--;
	bin[0]=1;for(int i=1;i<=22;i++)bin[i]=bin[i-1]*10;
	while(n){a[++cnt]=n%10;n/=10;}
	for(int i=1;i<=9*cnt;i++)
		memset(f,-1,sizeof(f)),ans-=dfs(cnt,0,0,1,i);
	cnt=0;
	n=rid();
	while(n){a[++cnt]=n%10;n/=10;}
	for(int i=1;i<=9*cnt;i++)
		memset(f,-1,sizeof(f)),ans+=dfs(cnt,0,0,1,i);
	printf("%lld",ans);
	return 0;
}