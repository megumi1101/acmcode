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
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int x,y,z;
        cin>>x>>y>>z;
        int ans=(x+y)/z;
        cout<<ans<<" ";
        if((x/z+y/z)==ans)cout<<"0";
        else{
            cout<<min(z-x%z,z-y%z);
        }
    }
}
