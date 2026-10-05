#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 600010
int T,n,m;
ll c[N],dep[N];
void sol()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>c[i];

    vector f(n+5,vector<ll>(20,0));
    vector fa(n+5,vector<ll>(20,0));
    vector<ll>dp(n+5,0x3f3f3f3f3f3f3f3f);
    vector<ll>mi1(n+5,0);
    vector<ll>mi2(n+5,0);
    vector<vector<int>>e(n+5);
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        e[x].push_back(y),e[y].push_back(x);
    }

    auto dfs=[&](auto && self,int x,int father) -> void
    {
        int siz=0;
        for (auto v:e[x])
        {
            if(v==father) continue;
            fa[v][0]=x;
            dep[v]=dep[x]+1;
            siz++;
            self(self,v,x);
            if(!mi1[x]||dp[mi1[x]]>dp[v]) mi2[x]=mi1[x],mi1[x]=v;
            else if(!mi2[x]||dp[mi2[x]]>dp[v]) mi2[x]=v;
        }
        for (auto v:e[x])
        {
            if(v==father) continue;
            if(v==mi1[x]) f[v][0]=dp[mi2[x]];
            else f[v][0]=dp[mi1[x]];
        }
        if(siz==0) dp[x]=c[x];
        else dp[x]=min(c[x],dp[mi1[x]]+dp[mi2[x]]);
    };

    auto lca=[&](int x,int y) -> int
    {
        if(dep[x]<dep[y]) swap(x,y);
        int z=dep[x]-dep[y];
        for (int i=0;i<20;i++)
            if((1<<i)&z)
                x=fa[x][i];
        if(x==y) return x;
        for (int i=19;i>=0;i--)
            if(fa[x][i]!=fa[y][i])
                x=fa[x][i],y=fa[y][i];
        return fa[x][0];
    };

    dep[1]=1;
    dfs(dfs,1,0);

    for (int j=1;j<=19;j++)
        for (int i=1;i<=n;i++)
        {
            f[i][j]=f[i][j-1]+f[fa[i][j-1]][j-1];
            fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(lca(x,y)!=y)
        {
            cout<<"-1\n";
            continue;
        }
        ll ans=0;
        int z=dep[x]-dep[y];
        for (int j=19;j>=0;j--)
            if(z&(1<<j))
                ans+=f[x][j],x=fa[x][j];
        cout<<ans<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) sol();
    return 0;
}
/*
1
5 5
1 2 3 4 5
1 2
1 3
2 4
2 5
3 1
2 1
4 1
5 1
5 2
*/