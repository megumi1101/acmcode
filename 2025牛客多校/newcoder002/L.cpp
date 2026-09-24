#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
#define int long long
int T,t,n,bz[N],a[N],cnt[N];
ll ans,mo=998244353;
ll ksm(ll x,ll y)
{
	if(y==0) return 1;
	if(y==1) return x;
	if(y%2==0) return ksm(x*x%mo,y/2);
	else return ksm(x*x%mo,y/2)*x%mo;
}
void dfs(int x)
{
	if(bz[x]) return;
	bz[x]=1;
	cnt[t]++;
	dfs(a[x]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while (T--)
	{
		cin>>n;
		t=0;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++)
			if(!bz[i])
				t++,dfs(i);
		int odd=0;
		for (int i=1;i<=t;i++) odd+=cnt[i]%2;
		if(odd==0)
		{
			ll sum=1,s1;
			ans=0;
			for (int i=1;i<=t;i++) sum=sum*(1+(cnt[i]>2))%mo;
			s1=sum*ksm(2,mo-2)%mo;
			for (int i=1;i<=t;i++)
			{
				if(cnt[i]==2) ans=(ans+sum)%mo;
				else
				{
					ans=(ans+s1*(cnt[i] / 2)%mo*(cnt[i] / 2)%mo)%mo;
				}
			}
		}
		else
		{
			if(odd!=2) ans=0;
			else 
			{
				ans=1;
				for (int i=1;i<=t;i++)
					if(cnt[i]%2==1) ans=ans*cnt[i]%mo;
					else ans=ans*(1+(cnt[i]>2))%mo;
			}
		}
		for (int i=1;i<=t;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) bz[i]=0;
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
18
2 3 4 5 6 1 8 9 10 11 12 7 14 15 16 17 18 13
*/