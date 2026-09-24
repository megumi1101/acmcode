#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,p[55];
void ins(int x)
{
	for(int i=52;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			if(!p[i])
			{
				p[i]=x;return;
			}
			else x^=p[i];
		}
	}
}
int qmax()
{
	int res=0;
	for(int i=52;i>=0;i--)
	{
		res=max(res,res^p[i]);
	}
	return res;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%lld",&x);
		ins(x);
	}
	printf("%lld",qmax());
	return 0;
}