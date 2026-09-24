#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    void sol(){
        int x,y;
        cin>>x>>y;
        if(x<0)x=-x;
        if(y<0)y=-y;
        if(x>y)swap(x,y);
        y-=x;
        int ans=2*x;
        if(y)ans+=2*y-1;
        cout<<ans<<"\n";
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--){
            sol();
        }
    }
}
