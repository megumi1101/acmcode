#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 3e5+10;
    int n, a[N], cnt=1, ch[N*15][2], siz[N*15][2], ni[N*15], vis[N*15];
    vector<int>xx[35];
    void add(int x) {
        int u = 1;
        for(int j=30;j>=0;j--) {
            if(!vis[u]) {
                xx[j+1].push_back(u);
                vis[u]=1;
            }
            int y = (x>>j)&1;
            if(!ch[u][y]) ch[u][y]=++cnt;
            siz[u][y]++;
            if(y==0)ni[u]+=siz[u][1];
            u=ch[u][y];
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            add(a[i]);
        }
        int x=0,ans=0;
        for(int j=31;j>=1;j--) {
            int res0=0;
            int res1=0;
            for(int u : xx[j]) {
                res1+=siz[u][0]*siz[u][1]-ni[u];
                res0+=ni[u];
            }
            if(res1 < res0)x^=(1<<(j-1)), ans+=res1;
            else ans+=res0;
        }
        cout<<ans<<" "<<x;
    }
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
