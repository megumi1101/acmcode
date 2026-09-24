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
        string a,b,c;
        cin>>a;
        b[0]='z'+1;
        int res=-1;
        for(int i=0;i<a.size();i++){
            if(a[i]<b[0]){
                b[0]=a[i];
                res=i;
            }
        }
        cout<<b[0]<<" ";
        for(int i=0;i<a.size();i++){
            if(i==res)continue;
            else cout<<a[i];
        }
        cout<<"\n";
    }
    void main(){
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
}
