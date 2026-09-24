#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    const int N=3e5+10;
    const int inf = 3e18;
    int n,m;
    int a[N],dp[N][23];
    vector<int>ed[N];
    void dfs(int u,int f) {
        for(int i=1;i<=21;i++)dp[u][i]=i*a[u];
        for(int v : ed[u]) {
            if(v==f)continue;
            dfs(v,u);
            for(int i=1;i<=21;i++) {
                int res=inf;
                for(int j=1;j<=21;j++) {
                    if(i==j)continue;
                    res=min(res,dp[v][j]);
                }
                dp[u][i]+=res;
            }
        }
    }
    void sol() {
        int ans=inf;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)ed[i].clear();
        for(int i=1;i<n;i++) {
            int x,y;
            cin>>x>>y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        dfs(1,0);
        for(int i=1;i<=21;i++) {
            ans=min(ans,dp[1][i]);
        }
        
        cout<<ans<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
