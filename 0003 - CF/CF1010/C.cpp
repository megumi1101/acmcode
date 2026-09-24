#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    int gcd(int a, int b) {
        return b?gcd(b,a%b):a;
    }
    void sol() {
        int n, k;
        cin>>n>>k;
        int a[n+5];
        int d = 0;
        for(int i=1;i<=n;i++)cin>>a[i], d=gcd(d,a[i]);
        int vis[k+5];
        memset(vis,0,sizeof(vis));
        int tmp=0;
        int ans=0;
        while(!vis[tmp]) {
            ans++;
            vis[tmp]=1;
            tmp=(tmp+d)%k;
        }
        cout<<ans<<"\n";
        for(int i=0;i<k;i++)if(vis[i])cout<<i<<" ";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin>>T;
        while(T--) {
            sol();
        }
    }
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
