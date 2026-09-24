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
    const int MN=(1<<11)+10;
    int n;
    vector<vector<int>>a(MN,vector<int>(MN,1));
    void dfs(int x,int y,int dep){
        if(dep==-1)return;
        int res=1<<dep;
        for(int i=x;i<x+res;++i){
            for(int j=y;j<y+res;++j){
                a[i][j]=0;
            }
        }
        dfs(x+res,y,dep-1);
        dfs(x,y+res,dep-1);
        dfs(x+res,y+res,dep-1);
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cin>>n;
        dfs(1,1,n-1);
        int res=1<<n;
        for(int i=1;i<=res;++i){
            for(int j=1;j<=res;++j){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}