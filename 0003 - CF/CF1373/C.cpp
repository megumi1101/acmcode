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
        string s;
        cin>>s;
        int res=0,ans=0;
        bool vis[1000006];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<s.size();i++){
            if(s[i]=='-'){
                res++;
                if(res>0&&vis[res]==0){
                    vis[res]=1;
                    ans+=i+1;
                }
            }
            else{
                res--;
            }
        }
        ans+=s.size();
        cout<<ans<<"\n";
    }
    void main(){
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
}
