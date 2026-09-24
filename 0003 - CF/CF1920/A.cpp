#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    void sol() {
        int n;
        cin>>n;
        vector<int>a;
        int mn=0;int mx=1e9;
        for(int i=1;i<=n;i++) {
            int x, y;
            cin >> x >> y;
            if(x==1) {
                mn=max(mn,y);
            } else if (x==2){
                mx=min(mx,y);
            } else {
                a.push_back(y);
            }
        }
        int ans=mx-mn+1;
        for(int i : a){
            if(i>=mn&&i<=mx)ans--;
        }
        if(ans>0)cout<<ans<<"\n";
        else cout<<"0"<<"\n";
    }
    void main() {
        int T;
        cin >> T;
        while(T--) {
            sol();
        }
    }
}
int main() {
    return xbbbz::main(), 0;
}
