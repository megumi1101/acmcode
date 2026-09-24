// AtCoder user: lnxbb
// Contest: abc388
// Problem: abc388_e
// Submission: https://atcoder.jp/contests/abc388/submissions/61698358
// Language: C++ 20 (gcc 12.2)

#include<bits/stdc++.h>
using namespace std;

namespace xbbbz {
    #define int long long
	bool pd(int *a,int n,int x) {
		for(int i=1;i<=x;i++) {
			if(2*a[i]>a[n-x+i]) return 0;
		}
		return 1;
	}
    void sol() {
        int n;
        cin>>n;
        int a[n+5];
		bool vis[n+5];
		for(int i=1;i<=n;i++)cin>>a[i];
		int l=1,r=n/2,ans=0;
		while(l<=r) {
			int mid=(l+r)/2;
			if(pd(a,n,mid)) ans=mid,l=mid+1;
			else r=mid-1;
		}
		cout<<ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin>>T;
        // init();
        while(T--) {
            sol();
        }
    } 
    #undef int
}

int main() {
    return xbbbz::main(), 0;
}