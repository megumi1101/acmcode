#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    const int N=2005;
    int n, x, a[N], fa[N], vis1[N],vis2[N],ans[N][2];
    vector<int>ed[N],xx[N];
    int find(int x) {
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    void hb(int x,int y) {
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy) {
            fa[fy]=fx;
        }
    }
    bool pd(int x, int y) {
        return find(x)==find(y);
    }
    void sol() {
        cin>>n;
        for(int i=1;i<=n;i++)ed[i].clear();
        for(int i=1;i<=n;i++)cin>>a[i],fa[i]=i;
        for(int i=n-1;i>=1;i--) {
            for(int j=0;j<=n;j++)vis1[j]=0,vis2[j]=0;
            for(int j=1;j<=n;j++) {
                if(vis2[find(j)])continue;
                vis2[find(j)]=1;
                if(!vis1[a[j]%i])vis1[a[j]%i]=j;
                else {
                    hb(j,vis1[a[j]%i]);
                    ans[i][0]=vis1[a[j]%i];
                    ans[i][1]=j;
                    break;
                }
            }
        }
        // int cnt=0;
        // for(int u=1;u<=n;u++) {
        //     for(int v : ed[u]) {
        //         if(!pd(u,v)) {
        //             hb(u,v);
        //             cnt++;
        //             xx[u].push_back(v);
        //         }
        //     }
        // }
 
            cout<<"Yes\n";
            for(int i=1;i<n;i++) {
                cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
            }
        
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
