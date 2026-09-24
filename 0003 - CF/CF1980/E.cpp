#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    void sol() {
        int n,m;
        cin>>n>>m;
        int a[n+10][m+10];
        int b[n+10][m+10];
        int c[n+10][m+10];
        int vis1[n*m+10];
        int vis2[n*m+10];
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
 
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>b[i][j];
                c[i][j]=b[i][j];
            }
                
 
        bool flag=1;
        for(int j=1;j<=m;j++) {
            vis1[a[1][j]]=j;
        }
        for(int i=1;i<=n;i++) {
            if(vis1[b[i][1]]) {
                for(int j=1;j<=m;j++) {
                    int x = vis1[b[i][j]];
                    if(!x){cout<<"NO\n";return;}
                    for(int k=1;k<=n;k++) {
                        c[k][x]=b[k][j];
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                b[i][j]=c[i][j];
        
        for(int i=1;i<=n;i++) {
            vis2[a[i][1]]=i;
        }
        for(int j=1;j<=m;j++) {
            if(vis2[b[1][j]]) {
                for(int i=1;i<=n;i++) {
                    int x = vis2[b[i][j]];
                    if(!x){cout<<"NO\n";return;}
                    for(int k=1;k<=m;k++) {
                        c[x][k]=b[i][k];
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                b[i][j]=c[i][j];
 
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) {
                if(a[i][j]!=b[i][j]) {
                    cout<<"NO\n";
                    return;
                }
            }
        cout<<"YES\n";
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
