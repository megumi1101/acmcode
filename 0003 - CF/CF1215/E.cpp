#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    #define int long long
    int a[400005];
    int vis[22];
    int w[22][22];
    int f[1100000];
    void sol() {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            a[i]--;
            vis[a[i]]++;
            for(int j=0;j<20;j++) {
                if(j==a[i])continue;
                w[j][a[i]] += vis[j];
            }
        }
        for(int i=1;i<(1<<20);i++) {
            f[i] = 1e18;
            for(int j=0;j<20;j++) {
                if((1<<j)&i) {
                    int sum=0;
                    for(int k=0;k<20;k++) {
                        if(((1<<k)&i) && k!=j) {
                            sum += w[j][k];
                        }
                    }
                    f[i] = min(f[i^(1<<j)]+sum,f[i]);
                }
            }
        }
        cout<<f[(1<<20)-1];
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
