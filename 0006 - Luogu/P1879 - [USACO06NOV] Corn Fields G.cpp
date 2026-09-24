#include<bits/stdc++.h>
using namespace std;

namespace xbbbz {
    #define int long long
    const int N = 1e5+10;
    const int inf = 1e18;
    const int mod = 1e8;
    bool pd(int x, int m) {
        for(int i=1;i<m;i++) {
            if(x&(1<<i) && x&(1<<(i-1))) {
                return 0;
            }
        }
        return 1;
    }
    void sol() {
        int n, m;
        cin>>n>>m;
        int a[n+1];
        int b[(1<<m)];
        int cnt=0;
        for(int i=1;i<=n;i++) {
            a[i]=0;
            for(int j=1;j<=m;j++) {
                int x;
                cin>>x;
                a[i] = a[i]*2+x;
            }
        }
        for(int i=0;i<(1<<m);i++) {
            if(pd(i, m))b[++cnt]=i;
        }
        int f[n+5][cnt+5];
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=cnt;j++) {
                if((b[j]|a[i])>a[i])continue;
                if(i==1) {f[i][j] = 1; continue;}
                for(int k=1;k<=cnt;k++) {
                    if((b[k]&b[j])==0) {
                        (f[i][j] += f[i-1][k]) %=mod;
                    }
                }
            }
        }
        int ans=0;
        for(int j=1;j<=cnt;j++) (ans+=f[n][j]) %=mod;
        cout<<ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin>>T;
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