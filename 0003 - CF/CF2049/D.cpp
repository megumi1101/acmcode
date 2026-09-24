#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int inf = 1e18;
    void sol() {
        int n,m,x;
        cin>>n>>m>>x;
        int a[n+5][m+5];
        int f[2][m+5];
        int g[2][m+5][m+5];
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        int op=0;
        for(int i=1;i<=n;i++) {
            op^=1;
            for(int j=1;j<=m;j++) {
                f[op][j]=inf;
                for(int k=0;k<m;k++) {
                    g[op][j][k]=inf;
                    if(i>1)g[op][j][k]=min(g[op][j][k], f[op^1][j]+k*x+a[i][(j+k-1)%m+1]);
                    if(j>1)g[op][j][k]=min(g[op][j][k], g[op][j-1][k]+a[i][(j+k-1)%m+1]);
                    if(i==1&&j==1)g[op][j][k] = a[i][(j+k-1)%m+1] + k*x;
                    f[op][j] = min(f[op][j], g[op][j][k]);
                }
            }
        }
        cout<<f[op][m]<<"\n";
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
