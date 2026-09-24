#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    xbbbz::main();return 0;
}
namespace xbbbz{
    #define IOSFAST ios::sync_with_stdio(false),cin.tie(0);
    #define int long long
    const int N=2e5+10;
    vector<int>ed[N];
    struct node{int x,y,z;};
    vector<node>xx;
    int ans=0;
    int n,c,s1,s2;
    int fa[N],dep[N];
    int d1[N],d2[N],d3[N];
    bool vis[N];
    void dfs1(int u,int f){
        dep[u]=dep[f]+1;
        fa[u]=f;
        if(dep[u]>dep[c])c=u;
        for(int v:ed[u]){
            if(v==f)continue;
            dfs1(v,u);
        }
    }
    void dfs2(int u,int f){
        d1[u]=d1[f]+1;
        for(int v:ed[u]){
            if(v==f)continue;
            dfs2(v,u);
        }
    }
    void dfs3(int u,int f){
        d2[u]=d2[f]+1;
        for(int v:ed[u]){
            if(v==f)continue;
            dfs3(v,u);
        }
        if(!vis[u]){
            if(d1[u]>=d2[u])xx.push_back((node){s1,u,u});
            else xx.push_back((node){s2,u,u});
            ans+=max(d1[u],d2[u])-1;
        }
    }
    void sol(){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)ed[i].clear();
        memset(vis,0,sizeof(vis));
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            ed[u].push_back(v),ed[v].push_back(u);
        }
        memset(dep,0,sizeof(dep));dfs1(1,0);s1=c;
        memset(dep,0,sizeof(dep));dfs1(s1,0);s2=c;
        int len=-1;
        for(int i=s2;i;i=fa[i]){
            len++;vis[i]=1;
        }
        dfs2(s1,0);dfs3(s2,0);
        for(int i=s2;i!=s1;i=fa[i]){
            xx.push_back((node){i,s1,i});
        }
        ans+=len*(len+1)/2;
        cout<<ans<<"\n";
        for(auto i:xx){
            cout<<i.x<<" "<<i.y<<" "<<i.z<<"\n";
        }
    }
    void main(){
        IOSFAST;
        int T=1;
        while(T--){
            sol();
        }
    }
}
