#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N=1e5+10,mod=998244353;
    void sol() {
        int n,k;
        cin>>n>>k;
        vector<vector<int> > dp(n+10, vector<int>(k+10,0));
        for(int i=1;i<=k+1;i++)dp[0][i]=1;
        int ans=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=k;j++) {
                for(int p=1;p<=min(i/j,k+1-j);p++) {
                    dp[i][j] += dp[i-p*j][p];
                    dp[i][j] %= mod;
                }
            }
            if(i==n) for(int j=1;j<=k;j++) ans = (ans+dp[n][j])%mod;
        }
        cout<<ans<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int T;
        cin >> T;
        while(T--) {
            sol();
        }
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
