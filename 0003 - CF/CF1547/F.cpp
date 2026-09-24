#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
	const int N=2e5+10;
	int lg[N];
	void init() {
		lg[1]=0;
		for(int i=2;i<=(int)2e5;i++)lg[i]=lg[i>>1]+1;
	}
	int gcd(int a,int b) {
		return b?gcd(b,a%b):a;
	}
	bool pd(int x,vector<vector<int>>f,int n) {
		int k=lg[x];
		int res=gcd(f[1][k],f[x-(1<<k)+1][k]);
		for(int i=2;i<=n;i++) {
			if(i+x-1>n) {
				int k1=lg[n-i+1];
				int k2=lg[x-(n-i+1)];
				int tmp1=gcd(f[i][k1],f[n-(1<<k1)+1][k1]);
				int tmp2=gcd(f[1][k2],f[x-(n-i+1)-(1<<k2)+1][k2]);
				int tmp=gcd(tmp1,tmp2);
				if(tmp!=res)return 0;
			}
			else {
				int tmp=gcd(f[i][k],f[x+i-(1<<k)][k]);
				if(tmp!=res)return 0;
			}
		}
		return 1;
	}
	void sol() {
		int n;
		cin>>n;
		vector <vector<int>> f(n+3,vector<int>(lg[n]+3,0));
		// int f[n+3][lg[n]+2];
		for(int i=1;i<=n;i++)cin>>f[i][0];
		for(int j=1;(1<<j)<=n;j++) {
			for(int i=1;i+(1<<j)-1<=n;i++) {
				f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
		int l=1,r=n;
		int ans=-1;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(pd(mid,f,n))ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<ans-1<<"\n";
	}
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
		int T;
		init();
		cin>>T;
		while(T--) {
			sol();
		}
    }
}
int main(){
    return xbbbz::main(),0;
}
