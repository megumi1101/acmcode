#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    const int mod = 998244353;
    void sol() {
        int n, m;
        cin>>n>>m;
        int x,y;
        int ans=0;
        ans=m*4*n;
        cin>>x>>y;
        for(int i=2;i<=n;i++) {
            cin>>x>>y;
            ans-=m-x;
            ans-=m-x;
            ans-=m-y;
            ans-=m-y;
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
