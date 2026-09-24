#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    const int N=1e6+10;
    int n,m;
    vector<int>a(N),sum(N,0),sumb(N,0);
    int ss(int x) {
        if(x==0)return 0;
        int res = x/n*sum[n];
        int y = (x-1)/n+1;
        x%=n;
        int z = min(n-y+1,x);
        res += sum[y+z-1]-sum[y-1];
        if(x>(n-y+1)) {
            x-=(n-y+1);
            res+=sum[x];
        }
        return res;
    }
    void sol() {
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
        // for(int i=n;i>=1;i--)sumb[i]=a[i]+sumb[i+1];
        for(int i=1;i<=m;i++) {
            int x,y;
            cin>>x>>y;
            cout<<ss(y)-ss(x-1)<<"\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
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
