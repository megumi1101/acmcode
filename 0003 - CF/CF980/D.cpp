// LUOGU_RID: 91689158
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005; 
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
queue<int>q[N];
int f[N],n,a[N];
signed main()
{
	n=rid();
	for(int i=1;i<=n;i++)a[i]=rid();
	for(int j=n;j>1;j--)
		for(int i=j-1;i>=1;i--)
		{
			if(a[i]*a[j]>0)
			{
				int tmp=sqrt(a[i]*a[j]);
				if(tmp*tmp==a[i]*a[j])q[j].push(i);
			}
		}
	for(int i=1;i<=n;i++)
	{
		int res=0;
		for(int j=i;j<=n;j++)
		{
			if(a[j]==0){f[max(res,(int)1)]++;continue;}
			while(!q[j].empty()&&q[j].front()<i)q[j].pop();
			if(q[j].empty())res++;
			f[res]++;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",f[i]);
	return 0;
}
/*
3
1 0 1 
*/
