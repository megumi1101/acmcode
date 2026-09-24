#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
	const int N=1e7+10;
	int sg[N],cnt,pr[N],vis[N];
    bool pd(int n,int x,int k) {
        return ((x*(2*k+x-1))-n*(2*k+n-1)/2)>0;
    }
	void init() {
		for(int i=2;i<=(int)1e7;i++) {
			if(!vis[i])pr[++cnt]=i;
			for(int j=1;j<=cnt&&pr[j]*i<=(int)1e7;j++) {
				vis[i*pr[j]]=1;
				if(i%pr[j]==0)break;
			}
		}
		sg[1]=1;
		for(int i=2;i<=cnt;i++)sg[pr[i]]=i;
		for(int i=3;i<=(int)1e7;i+=2) {
			if(!vis[i])continue;
			for(int j=2;j<=cnt;j++) {
				if(i%pr[j]==0) {
					sg[i]=j;
					break;
				}
			}
		}
	}
    void sol() {
        int n;
		cin>>n;
		int a[n+10];
		int ans=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			ans^=sg[a[i]];
		}
		if(ans)cout<<"Alice"<<"\n";
		else cout<<"Bob"<<"\n";
 
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
		init();
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
