#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[105],ans,p[35];
void ins(int x)
{
	int res=x;
	for(int i=30;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			if(!p[i])
			{
				p[i]=x;
				break;
			}
			else x^=p[i];
		}		
	}
	if(!x) ans+=res;
}
int cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		ins(a[i]);
	}
	printf("%lld",ans);
	return 0;
}