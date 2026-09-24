#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    const int N=1e5+10;
    int dep[N],fa[N];
    int n,a,b,da,db;
    vector<int>ed[N];
    int s1,s2;
    void dfs(int u,int f,int &s){
        fa[u]=f;
        dep[u]=dep[f]+1;
        if(dep[u]>dep[s])s=u;
        for(int v : ed[u]){
            if(v==f)continue;
            dfs(v,u,s);
        }
        //cout<<"Df";
    }
    int lca(int x,int y){
        if(dep[x]<dep[y])swap(x,y);
        while(dep[x]>dep[y]){
            x=fa[x];
        }
        while(fa[x]!=fa[y]){
            x=fa[x];y=fa[y];
        }
        if(x==y)return x;
        else return fa[x];
    }
    void sol(){
        cin>>n>>a>>b>>da>>db;
        for(int i=1;i<=n;i++)ed[i].clear();
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        memset(dep,0,sizeof(dep));memset(fa,0,sizeof(fa));
        dfs(1,0,s1);
        memset(dep,0,sizeof(dep));memset(fa,0,sizeof(fa));
        dfs(s1,0,s2);
        int len=dep[s2]-dep[s1];
        int dab=dep[a]+dep[b]-2*dep[lca(a,b)];
        if(dab<=da||2*da>=db||2*da>=len)cout<<"Alice";
        else cout<<"Bob";
        cout<<"\n";
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
