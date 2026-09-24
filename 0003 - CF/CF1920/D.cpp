#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N=1e5+10;
    int lst[N],dp[N];
    void sol() {
        int n,q;
        cin>>n>>q;
        for(int i=0;i<=n;i++)lst[i]=0, dp[i]=0;
        for(int i=1;i<=n;i++) {
            int x, y;
            cin>>x>>y;
            if(x == 1) {
                dp[i] = dp[i-1]+1;
                lst[i] = y;
            } else {
                dp[i] = y+1 > (int)2e18/dp[i-1] ? (int)2e18 : (y+1)*dp[i-1];
                lst[i] = lst[i-1];      
            }
        }
        int pos;
        while(q--) {
            int k;cin>>k;
            while(1) {
                pos = lower_bound(dp+1, dp+1+n, k)-dp;
                if(k == dp[pos]) {
                    cout<<lst[pos]<<" \n"[q==0];break;
                } else if(k%dp[pos-1] == 0) {
                    cout<<lst[pos-1]<<" \n"[q==0];break;
                }
                k %= dp[pos-1];
            }
        }
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
