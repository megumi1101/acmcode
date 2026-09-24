#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int T=1,n,m,k,ans;
int d[maxn],a[maxn];
vector<pair<int,int>>sp;
void solve() {
	scanf("%lld%lld%lld",&n,&m,&k);
	sp.clear();d[n+1]=inf;ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&d[i],&a[i]);
	}
    while(!sp.empty())sp.pop_back();
	for(int i=1;i<=n;i++){
		sp.push_back({d[i],a[i]});
		int t=d[i],res=0;
		while(sp.size()) {
			int tt=sp.back().first;
			int w=sp.back().second;
			int d1=tt+k-1;
			int d2=t+(res+w)/m-1;
			int dd=min(min(d1,d2),d[i+1]-1);
			if(d1<t) {
				break;
			}
			if(d[i+1]-1==dd) {
				sp.back()={tt,w+res-(d[i+1]-t)*m};
				ans+=d[i+1]-t;
				break;
			}
			if(d1==dd) {
				res=0;
			}
			else{
				res+=w-(dd-t+1)*m;
			}
			ans+=dd-t+1;
			t=dd+1;
			sp.pop_back();
		}
	}
	printf("%lld\n",ans);
}
signed main() {
	scanf("%lld",&T);
	while(T--){
		solve();
	}
	return 0;
}
