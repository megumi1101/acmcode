#include<bits/stdc++.h>
using namespace std;
 
 
namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    int lg[N];
    void init() {
        lg[1] = 0;
        for(int i=2;i<=(int)2e5;i++) lg[i] = lg[i>>1] + 1;
    }
    int gcd(int a, int b) {
        return b?gcd(b,a%b):a;
    }
    void sol() {
        int n, q;
        cin>>n>>q;
        int f[n+5][21];
        int a[n+5];
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int j=1;j<=20;j++) {
            for(int i=1;i+(1<<j)-1<=n;i++) {
                f[i][j] = gcd( gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]), abs(a[i] - a[i+(1<<(j-1))]));
            }
        }
        while(q--) {
            int l, r;
            cin>>l>>r;
            int k = lg[r-l+1];
            int ans = gcd(f[l][k], f[r-(1<<k)+1][k]);
            ans =gcd(ans, abs(a[r] - a[l]));
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin>>T;
        init();
        while(T--) {
            sol();
        }
    }
    #undef int 
}
 
int main() {
    return xbbbz::main(), 0;
}
