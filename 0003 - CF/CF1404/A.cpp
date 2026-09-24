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
        int n,k;
        cin>>n>>k;
        string s;
        vector<int>a(n+10),vis(n+10);
        cin>>s;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1')a[i]=1;
            else if(s[i-1]=='0')a[i]=-1;
            else a[i]=0;
        }
        bool flag=0;
        for(int i=1;i<=n;i++){
            int now=i%k;
            if(vis[now]==0){
                vis[now]=a[i];
            }
            else if(vis[now]==1){
                if(a[i]==-1){flag=1;break;}
            }
            else{
                if(a[i]==1){flag=1;break;}
            }
        }
        int res=0,res2=0;
        for(int i=1;i<=n;i++){
            int now=i%k;
            a[i]=vis[now];
        }
        for(int i=1;i<=k;i++){
            if(a[i]==1)res++;
            else if(a[i]==-1)res2++;
        }
        if(res>res2)swap(res,res2);
        if(res2>k/2)flag=1;
        if(flag)cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n";
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
