#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    #define int long long
    void solve(){
        int x,y,k;
        cin>>x>>y>>k;
        int ans=k+(k+y*k-2)/(x-1)+1;
        cout<<ans<<"\n";
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int T;cin>>T;
        while(T--)solve();
    }
}
