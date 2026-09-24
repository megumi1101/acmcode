#include<bits/stdc++.h>
using namespace std;


namespace xbbbz {
    #define int long long
    typedef long double db ;
    void sol() {
        int n;
        cin>>n;
        db t1 = 0.0;
        db t2 = 0.0;
        db ans = 0.0;
        for(int i=1;i<=n;i++) {
            db x;
            cin>>x;
            t2 = x * (t2 + 1 + t1);
            t1 = x;
            ans+=t2;
        }
        cout<<fixed<<setprecision(10);
        cout<<ans;
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
