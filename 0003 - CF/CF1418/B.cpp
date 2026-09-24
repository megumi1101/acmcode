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
        int n;cin>>n;
        vector<int> a(n+5),loc(n+5),xx;
        xx.clear();
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>loc[i];
        for(int i=1;i<=n;i++){
            if(loc[i])continue;
            xx.push_back(a[i]);
        }
        sort(xx.begin(),xx.end(),[&](int a,int b){return a>b;});
        int pos=0;
        for(int i=1;i<=n&&pos<xx.size();i++){
            if(loc[i])continue;
            else {
                a[i]=xx[pos];pos++;
            }
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<"\n";
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int T;cin>>T;
        while(T--)solve();
    }
}
