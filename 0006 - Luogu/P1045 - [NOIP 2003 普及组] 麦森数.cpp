#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    vector<int>a(510,0),b(510,0);
    int p;
    void calc(){
        for(int i=1;i<=56;i++)a[i]<<=1;
        for(int i=1;i<=56;i++)
            if(a[i]>=1e9){a[i]-=1e9;a[i+1]+=1;}
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cin>>p;
        cout<<(int)(log10(2.0)*p+1)<<"\n";
        a[1]=1;
        for(int i=1;i<=p;++i)calc();a[1]-=1;
        a[56]%=100000;
        for(int i=1;i<=500;i++){
            int x=(i-1)/9+1;
            b[i]=a[x]%10;
            a[x]/=10;
        }
        for(int i=500;i>=1;i--){
            if((i%50==0)&&i<500)cout<<"\n";
            cout<<b[i];
        }
        return;
    }
}