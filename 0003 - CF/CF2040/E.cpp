#include<bits/stdc++.h>
using namespace std;
 
 
namespace xbbbz {
    #define int long long
    const int mod = 998244353;
    const int N = 2005;
    int n, q;
    vector<int>ed[N];
    int f[N][N][2];
    void dfs(int u, int fat) {
        for(int v : ed[u]) {
            if(v==fat)continue;
            for(int i=0;i<=n;i++) {
                f[v][i][0] = f[u][i][1] + 1;
                f[v][i][1] = 2 * (ed[v].size()-1) + f[u][i][0] + 1;
                if(i>=1) f[v][i][1] =min(f[v][i][1], f[u][i-1][0] + 1);
            }
            dfs(v,u);
        }
    }
    void sol() {
        cin>>n>>q;
        for(int i=1;i<=n;i++)ed[i].clear();
        for(int i=1;i<n;i++) {
            int x, y;
            cin>>x>>y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        for(int i=0;i<=n;i++)f[1][i][0]=f[1][i][1]=0;
        dfs(1, 0);
        for(int i=1;i<=q;i++) {
            int x, y;
            cin>>x>>y;
            cout<<f[x][y][0] % mod <<"\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin>>T;
        // init();
        while(T--) {
            sol();
        }
    }
    #undef int 
}
 
int main() {
    return xbbbz::main(), 0;
}
