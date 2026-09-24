#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int n,k;
        cin>>n>>k;
        int a[n+5];
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++) {
            bool fg=0;
            for(int j=1;j<=n;j++) {
                if(j==i)continue;
                if(abs(a[i]-a[j])%k==0) {
                    fg=1;break;
                }
            }
            if(!fg) {
                cout<<"YES\n"<<i<<"\n";
                return;
            }
        }
        cout<<"NO\n";
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
