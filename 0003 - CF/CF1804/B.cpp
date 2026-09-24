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
        int n,k,d,w;
        
        cin>>n>>k>>d>>w;
        vector<int> a(n+10);
        for(int i=1;i<=n;i++)cin>>a[i];
        int m=d+w;
        int pos=1;
        int ans=0;
        for(;pos<=n;){
            int tml=a[pos],cnt=1;
            while(pos<=n&&cnt<=k&&a[pos]-tml<=m){
                cnt++;
                pos++;
            }
            ans++;
        }
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
