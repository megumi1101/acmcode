#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pa pair<int,int>
#define N 1000010
int T,n;
struct node{
    int v,id,dir;
};
void sol()
{
    cin>>n;
    vector<int>ans;
    vector<int>a(n+5);
    vector<int>b(n+5);
    vector<int>cnt(n+5,0);
    vector<vector<node>>e(n+5);
    for (int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    for (int i=1;i<=n;i++) cin>>b[i],cnt[b[i]]++;
    for (int i=1;i<=n;i++)
    {
        if(cnt[i]%2==1)
        {
            cout<<"-1\n";
            return;
        }
    }
 
    for (int i=1;i<=n;i++)
    {
        e[a[i]].pb({b[i],i,1});
        e[b[i]].pb({a[i],i,2});
    }
    vector<int>num(n+5,0);
    vector<int>bz(n+5,0);
    vector<int>vis(n+5,0);
    auto dfs=[&](auto &&dfs,int x) -> void {
        vis[x]=1;
        for (int &i=num[x];i<e[x].size();)
        {
            auto &[v,id,dir]=e[x][i];
           i++;
            if(bz[id]==1) continue;
            bz[id]=1;
            if(dir==2) ans.pb(id);
            dfs(dfs,v);
        }
    };
    for (int i=1;i<=n;i++)
        if(!vis[i])
            dfs(dfs,i);
    cout<<ans.size()<<"\n";
    for (int v:ans) cout<<v<<" ";
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) sol();
    return 0;
}
