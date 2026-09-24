#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    const int N=2e5+10;
    int n,c;
    int a[N],dp[N][2];
    vector<int>ed[N];
    bool cmp(int a,int b) {
        return dp[a][1]-dp[a][0]>dp[b][1]-dp[b][0];
    }
    void dfs(int u, int f) {
        dp[u][0] = 0;
        dp[u][1] = a[u];
        vector<int>xx;
        for(int v : ed[u]) {
            if(v==f)continue;
            dfs(v, u);
            dp[u][0] += max(dp[v][0],dp[v][1]);
            dp[u][1] += dp[v][0];
            xx.push_back(v);
        }
        sort(xx.begin(),xx.end(),cmp);
        int res = dp[u][1];
        for(int v : xx) {
            res = res + dp[v][1]- dp[v][0] -2*c;
            dp[u][1] = max(res,dp[u][1]);
        }
    }
    void sol() {
        cin>>n>>c;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)ed[i].clear();
        for(int i=1;i<n;i++) {
            int x,y;
            cin>>x>>y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        dfs(1,0);
        cout<<max(dp[1][0],dp[1][1])<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--) {
            sol();
        }
    }
    #undef int    
}
int main() {
    return xbbbz::main(), 0;
}
