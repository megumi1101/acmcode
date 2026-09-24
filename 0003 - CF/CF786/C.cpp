#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
	#define int long long
	const int N=1e5+10;
	int n,a[N],c[N];
	bool vis[N];
	int getans(int k) {
		// memset(vis,0,sizeof(vis));
		int res=0,last=1,ans=0;
		for(int i=1;i<=n;i++) {
			if(!vis[a[i]]) {
				res++;
				vis[a[i]]=1;
				if(res>k) {
					ans++;
					res=0;
					for(int j=last;j<=i;j++)vis[a[j]]=0;
					last=i;
				}
			}
			if(res==0) {
				vis[a[i]]=1;
				res++;
			}
		}
		for(int j=last;j<=n;j++)vis[a[j]]=0;
		return ans+1;
	}
	void main() {
		ios::sync_with_stdio(false),cin.tie(nullptr);
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int t=sqrt(n);
		for(int k=1;k<=t;k++) {
			c[k]=getans(k);
		}
		int last=t;
		int tmp=c[last];
		while(last<n) {
			int l=last,r=n,ans=-1;
			while(l<=r) {
				int mid=(l+r)/2;
				if(getans(mid)==tmp)ans=mid,l=mid+1;
				else r=mid-1;
			}
			for(int i=last+1;i<=ans;i++)c[i]=tmp;
			last=ans+1;c[last]=getans(last);tmp=c[last];
		}
		for(int i=1;i<=n;i++)cout<<c[i]<<" ";
	}
	#undef int
}
int main() {
	return xbbbz::main(), 0;
}
/*
10 1 11
1
2
3
4
5
6
7
8
9
10
2 8 6 10
*/
