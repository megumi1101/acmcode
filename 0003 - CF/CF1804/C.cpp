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
        int n,x,p,f;
        cin>>n>>x>>p;
        bool flag=0;
        for(int i=1;i<=min(2*n,p);i++){
            if(((i*(i+1))/2+x)%n==0)flag=1;
        }
        if(flag)cout<<"Yes";
        else cout<<"No";
        cout<<"\n";
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
