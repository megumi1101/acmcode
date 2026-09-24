#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    int gcd(int a,int b){
        return b?gcd(b,a%b):a;
    }
    void sol(){
        int n;cin>>n;
        vector<int>l(n+10),c(n+10);
        for(int i=1;i<=n;i++)cin>>l[i];
        for(int i=1;i<=n;i++)cin>>c[i];
        unordered_map<int,int>ump;
        vector<pair<int,int>>xx;
        ump[0]=0;
        for(int i=1;i<=n;i++){
            xx.clear();
            for(const auto &it : ump){
            // for(auto it : ump){
                int res=gcd(it.first,l[i]);
                if(ump.find(res)!=ump.end()){
                    // ump[res]=min(ump[res],ump[it.first]+c[i]);
                    xx.push_back({res,min(ump[res],ump[it.first]+c[i])});
                }
                else{
                    // ump[res]=ump[it.first]+c[i];
                    xx.push_back({res,ump[it.first]+c[i]});
                }
            }
            for(auto it :xx){
                if(ump[it.first])ump[it.first]=min(ump[it.first],it.second);
                else ump[it.first]=it.second;
            }
        }
        if(ump[1]==0)cout<<"-1";
        else cout<<ump[1];
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int T=1;
        //cin>>T;
        while(T--){
            sol();
        }
    }
}
