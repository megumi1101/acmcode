#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,xx,w[maxn],mx[maxn],ans=1,cnt;
vector<int> a[maxn];

int lb(int x)
{
	return x&(-x);
}
void update(int p,int x)
{
	for(int i=p;i<=cnt;i+=lb(i))
	{
		mx[i]=max(mx[i],x);
	}
}
int cx(int p)
{
	int res=0;
	for(int i=p;i;i-=lb(i))
	{
		res=max(res,mx[i]);
	}
	return res;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=5*n;i++)
	{
		scanf("%d",&xx);
		a[xx].push_back(i);
	}
	for(int i=1;i<=5*n;i++)
	{
		scanf("%d",&xx);
		for(int j=4;j>=0;j--)
		{
			w[++cnt]=a[xx][j];
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		int tt=cx(w[i]-1)+1;
		
		ans=max(ans,tt);
		update(w[i],tt);
	}
	printf("%d",ans);
	return 0;
}