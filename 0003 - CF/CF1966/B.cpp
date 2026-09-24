#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    void sol() {
        int n,m;
        cin>>n>>m;
        string a[n+1];
        for(int i=1;i<=n;i++)cin>>a[i],a[i]=' '+a[i];
        bool flag=0;
        if(a[1][1]==a[n][m]||a[n][1]==a[1][m])flag=1;
        if(a[1][1]==a[n][1]) {
            for(int i=1;i<=n;i++) {
                if(a[i][m]==a[1][1])flag=1;
            }
        }
        if(a[1][m]==a[n][m]) {
            for(int i=1;i<=n;i++) {
                if(a[i][1]==a[1][m])flag=1;
            }
        }
        if(a[1][1]==a[1][m]) {
            for(int j=1;j<=m;j++) {
                if(a[n][j]==a[1][1])flag=1;
            }
        }
        if(a[n][1]==a[n][m]) {
            for(int j=1;j<=m;j++) {
                if(a[1][j]==a[n][1])flag=1;
            }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
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
