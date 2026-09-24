#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int p[65],ans;
void insert(int x)
{
	for(int i=60;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			if(!p[i])
			{
				p[i]=x;
				ans++;
				break;
			}
			else x^=p[i];
		}
	}
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		char s[65];
		int x=0;
		scanf("%s",s);
		for(int i=0;i<strlen(s);i++)
		{
			if(s[i]=='O') x+=(1LL<<i);
		}
		insert(x);
	}
	printf("%lld",(1LL<<ans)%2008);
	return 0;
}