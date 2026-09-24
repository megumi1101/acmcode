#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 1e5+10;
    const int inf = 1e18;
    void sol() {
        int n, x;
        cin>>n>>x;
        int a[n+5], b[n+5];
        int res=0;
        for(int i=1;i<=n;i++)
            cin>>a[i]>>b[i], res+=b[i];
        int f[res+1];
        f[0] = 0;
        for(int i=1;i<=res;i++)f[i]=inf;
        for(int i=1;i<=n;i++) {
            int now = (i-1)*x;
            for(int j=res;j>=0;j--) {
                if(j-b[i]>=0 && f[j-b[i]] + a[i] <= now) {
                        f[j] = min(f[j], f[j-b[i]] + a[i]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=res;i++) {
            if(f[i]!=inf)ans=i;
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
