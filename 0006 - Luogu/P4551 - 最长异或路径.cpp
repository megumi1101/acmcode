#include<bits/stdc++.h>
using namespace std;

namespace xbbbz {
    const int N = 1e6+10;
    int n, a[N], cnt=1, ch[N][2];
    struct node {
        int v,w;
    };
    vector<node>ed[N];
    void dfs(int u, int f) {
        for(node i : ed[u]) {
            int v = i.v;
            int w = i.w;
            if(v==f)continue;
            a[v] = a[u] ^ w;
            dfs(v,u);
        }
    }
    void add(int x) {
        int u = 1;
        for(int j=30;j>=0;j--) {
            int y = (x>>j)&1;
            if(!ch[u][y]) ch[u][y]=++cnt;
            u=ch[u][y];
        }
    }
    int cx(int x) {
        int u = 1;
        int res=0;
        for(int j=30;j>=0;j--) {
            int y = (x>>j)&1;
            if(ch[u][y^1]) {
                res^=(1<<j);
                u=ch[u][y^1];    
            }
            else u=ch[u][y];
        }
        return res;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        cin>>n;
        for(int i=1;i<n;i++) {
            int x,y,z;
            cin>>x>>y>>z;
            ed[x].push_back({y,z});
            ed[y].push_back({x,z});
        }
        dfs(1,1);
        for(int i=1;i<=n;i++) {
            add(a[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            ans=max(ans,cx(a[i]));
        }
        cout<<ans;
    }
}

int main() {
    return xbbbz::main(), 0;
}