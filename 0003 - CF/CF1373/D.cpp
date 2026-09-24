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
        int n;
        cin>>n;
        vector<int>a(n+10,0),b(n+10,0),c(n+10,0),f(n+10,0),las(n+10,0);
        for(int i=1;i<=n;i++){
            if(i&1)cin>>a[i/2+1];
            else cin>>b[i/2];
        }
        int ans=0;
        for(int i=1;i<=n/2;i++)c[i]=b[i]-a[i];
        for(int i=1;i<=n/2;i++){
            if(f[i-1]>0)f[i]=f[i-1]+c[i],las[i]=las[i-1];
            else f[i]=c[i],las[i]=i;
            ans=max(ans,f[i]);
        }
        //if(n==4)cout<<"DF"<<ans<<"DF";
        // if(n&1){
            for(int i=1;i<=n/2;i++)c[i]=b[i]-a[i+1];
            if(!(n&1))c[n/2]=0;
            for(int i=0;i<=n;i++)f[i]=las[i]=0;
            for(int i=1;i<=n/2;i++){
                if(f[i-1]>0)f[i]=f[i-1]+c[i],las[i]=las[i-1];
                else f[i]=c[i],las[i]=i;
                ans=max(ans,f[i]);
            }
        // }
        for(int i=1;i<=n;i++)if(i&1)ans+=a[i/2+1];
        cout<<ans<<"\n";
    }
    void main(){
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
}
