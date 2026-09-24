#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010
int T,n,q,a[N];
int tot,bz[N],p[N];
map<int,int> t;
ll x;
void solve(int x)
{
	int m=1;
	for (int i=1;i<=tot;i++)
	{
		int cnt=0;
		while (x%p[i]==0)
		{
			x/=p[i];
			cnt++;
		}
		if(cnt%2==1) m*=p[i];
	}
//	cout<<m*x<<endl;
	t[m*x]++;
}
int main()
{
	cin>>T;
	for (int i=2;i<=1000;i++)
	{
		if(!bz[i]) p[++tot]=i;
		for (int j=1;j<=tot&&i*p[j]<=1000;j++)
		{
			bz[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
//	for (int i=1;i<=tot;i++) cout<<p[i]<<" ";cout<<endl;
	while (T--)
	{
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			solve(a[i]);
		}
		int ans0=0,ans1=0,cnt=0;
		for(map<int,int>::iterator i=t.begin();i!=t.end();++i)
		{
			ans0=max(ans0,i->second);
			if(i->first==1||i->second%2==0) cnt+=i->second;
		}
		ans1=max(ans0,cnt);
		cin>>q;
//		cout<<ans0<<" "<<ans1<<endl;
		for (int i=1;i<=q;i++)
		{
			cin>>x;
			if(x==0) cout<<ans0<<endl;
			else cout<<ans1<<endl;
		}
		t.clear();
	}
	return 0;
}
