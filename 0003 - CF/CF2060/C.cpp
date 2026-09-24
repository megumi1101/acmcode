#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    const int mod = 998244353;
    void sol() {
        int n,k;
        cin>>n>>k;
        int a[n+5];
        int vis[2*n+5];
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)cin>>a[i], vis[a[i]]++;
        int ans=0;
        for(int i=1;i<=k/2;i++) {
            if(2*i==k) {
                ans+=vis[i]/2;
            }
            else ans+=min(vis[i],vis[k-i]);
        }
        cout<<ans<<"\n";
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
