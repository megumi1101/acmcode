#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int inf = 1e18;
    void sol() {
        int n;
        cin>>n;
        int a[n+5];
        bool xx=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            if(a[i]>=0)xx=1;
        }
        if(!xx) {
            int ans=-inf;
            for(int i=1;i<=n;i++) {
                ans=max(ans,a[i]);
            }
            cout<<ans<<"\n";
        }
        else {
            int s1=0, s2=0;
            for(int i=1;i<=n;i++) {
                if(i&1)s1+=max(a[i],(int)0);
                else s2+=max(a[i],(int)0);
            }
            cout<<max(s1,s2)<<"\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0);
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
