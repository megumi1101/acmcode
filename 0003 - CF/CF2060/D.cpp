#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    const int mod = 998244353;
    void sol() {
        int n,k;
        cin>>n;
        int a[n+5];
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++) {
            if(a[i]>a[i+1]) {
                cout<<"NO\n";
                return ;
            }
            a[i+1]-=a[i];
        }
        cout<<"YES\n";
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
