#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
	void sol() {
		int n,m;
		cin>>n>>m;
		int res=0;
		while(n%3==0) {
			n/=3;
			res++;
		}
		if(m%n) {
			cout<<"NO\n";
			return;
		}
		else {
			m/=n;
		}
		n=1;
		while(m%2==0)m/=2,res--;
		while(m%3==0)m/=3,res--;
		if(m!=1||res<0) {
			cout<<"NO\n";
			return;
		}
		cout<<"YES\n";
	}
	void main() {
		ios::sync_with_stdio(false),cin.tie(nullptr);
		int T;
		cin>>T;
		for(int i=1;i<=T;i++) {
			sol();
		}
	}
}
int main() {
	return xbbbz::main(), 0;
}
