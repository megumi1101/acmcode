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
    void sol(){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>=c)cout<<"-1 ";
        else cout<<"1 ";
        if(a*b<=c)cout<<"-1";
        else cout<<b;
        cout<<"\n";
    }
    void main(){
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
}
