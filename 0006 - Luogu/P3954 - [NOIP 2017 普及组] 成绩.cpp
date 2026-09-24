#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    void main(){
        #define int long long
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int a,b,c;
        cin>>a>>b>>c;
        cout<<a*2/10+b*3/10+c*5/10;
    }
}