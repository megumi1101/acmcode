#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int inf = 1e18;
    const int N = 5e5+10;
    int a[N], f[N], sum[N], lst[N];
    void sol() {
        int n, c;
        cin>>n>>c;
        int ans = 0;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            sum[i]=sum[i-1] + (a[i]==c);
            if(a[i]==c)continue;
            f[i] = 1;
            int x = lst[a[i]];
            if(x) {
                f[i] = max(f[i], f[x]-(sum[i]-sum[x])+1); 
            }
            ans=max(ans,f[i]); 
            lst[a[i]] = i;
        }
        cout<<ans+sum[n]; 
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
