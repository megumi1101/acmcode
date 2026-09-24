#include<bits/stdc++.h>
using namespace std;
vector<int> son[7777];
int n,x,y,v[7777],ro,ans,f[7777][2];
void dp(int x)
{
	f[x][0]=0;
	for(int i=0;i<son[x].size();i++)
	{
		int y=son[x][i];
		dp(y);
		f[x][1]+=f[y][0];
		f[x][0]+=max(f[y][0],f[y][1]);
	}
}
int main()
{
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i][1]);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		son[y].push_back(x);
		v[x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			ro=i;
			break;
		}
	}
	dp(ro);
	ans=max(f[ro][0],f[ro][1]);
	printf("%d",ans);
	return 0;
}