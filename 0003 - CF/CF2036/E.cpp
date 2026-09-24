#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int T;
	T=1;
	while(T--){
		int n,k,q;
		cin>>n>>k>>q;
		vector<vector<int> > a(k,vector<int>(n));
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				cin>>a[j][i];
				if(i>=1) a[j][i]|=a[j][i-1];
			}
		}
		while(q--){
			int st=0,en=2e9+100,ci;cin>>ci;
			while(ci--){
				int r,c;
				char op;
				cin>>r>>op>>c;
				r--;
				if(op=='>'){
					int x=upper_bound(a[r].begin(),a[r].end(),c)-a[r].begin();
					st=max(st,x);
				}
				else{
					int x=lower_bound(a[r].begin(),a[r].end(),c)-a[r].begin();
					en=min(x-1,en);
				}
			}
			//cout<<st<<' '<<en<<endl;
			if(st<=en&&st<n) cout<<st+1<<endl;
			else cout<<-1<<endl;
		}
	}
	return 0;
}
