#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int inf = 1e18;
    const int N = 2e5+10;
    int n;
    vector<int>ed[N];
    int col[N], fa[N];
    void dfs(int u, int f,int c) {
        fa[u] = f;
        col[u] = c;
        for(int v : ed[u]) {
            if(v == f)continue;
            dfs(v, u, c^1);
        }
    }
    void sol() {
        cin>>n;
        int a[n+5];
        for(int i=1;i<=n;i++) 
            ed[i].clear(), col[i] = -1, fa[i] = -1;
        for(int i=1;i<n;i++) {
            int x,y;
            cin>>x>>y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        int rt=0;
        for(int i=1;i<=n;i++) {
            if(ed[i].size()==1)rt=i;
        }
        dfs(rt,0,0);
        bool fg=0;
        for(int i=1;i<=n;i++) {
            if(col[i]&&fa[i]!=rt) {
                fg=1;
                int cnt=0;
                for(int j=1;j<=n;j++) {
                    if(col[j]==0&&j!=rt) a[j]=(++cnt*2);
                }
                a[rt]=++cnt*2;
                a[i]=++cnt*2;
                for(int j=1;j<=n;j++) {
                    if(col[j]&&j!=i) a[j]=(++cnt*2);
                }
                break;
            }
        }
        if(!fg) {
            int res=0;
            for(int i=1;i<=n;i++)if(col[i])res++;
            int x=rt;
            if(res==1) {
                for(int i=1;i<=n;i++)if(col[i])x=i;
            }
            int cnt=0;
            a[x]=2*n;
            for(int i=1;i<=n;i++) {
                if(i!=x) {
                    a[i]=++cnt*2;
                    if(a[i]==n*2-2)a[i]++;
                }
            }
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<" "; cout<<"\n";
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
