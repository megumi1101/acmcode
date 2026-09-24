#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4+10;
struct node
{
	int bh,val;
	friend bool operator<(node a,node b)
	{
		return a.val>b.val;
	}
}a[maxn];
int p[70],ans;
void ins(int x,int y)
{
	for(int i=62;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			if(!p[i])
			{
				p[i]=x;
				ans+=y;
				break;
			}
			else x^=p[i];
		}
	}
}
int n;
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].bh,&a[i].val);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		ins(a[i].bh,a[i].val);
	}
	printf("%lld",ans);
	return 0;
}