#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int n;
        cin>>n;
        int vis[n+5];
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) {
            if(vis[i])continue;
            for(int j=i;j<=n;j*=2) {
                cout<<j<<" ";
                vis[j]=1;
            }
        }
        cout<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
