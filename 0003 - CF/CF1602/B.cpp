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
        vector<int>vis(n+10);
        vector<vector<int>> a(2*n+10,vector<int>(n+10,0));
        for(int i=1;i<=n;i++)cin>>a[0][i];
        for(int i=1;i<=2*n;i++){
            for(int j=1;j<=n;j++)vis[j]=0;
            for(int j=1;j<=n;j++){
                vis[a[i-1][j]]++;
            }
            for(int j=1;j<=n;j++){
                a[i][j]=vis[a[i-1][j]];
            }
        }
        int q;cin>>q;
        while(q--){
            int x,k;
            cin>>x>>k;
            if(k<=2*n)cout<<a[k][x];
            else cout<<a[2*n][x];
            cout<<"\n";
        }
    }
    void main(){
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
}
