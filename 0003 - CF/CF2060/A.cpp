#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    const int mod = 998244353;
    void sol() {
        int a[10];
        for(int i=1;i<=2;i++)cin>>a[i];
        for(int i=4;i<=5;i++)cin>>a[i];
        int res=0;
        for(int i=-205;i<=205;i++) {
            a[3]=i;
            int tmp=0;
            for(int j=1;j<=3;j++) {
                if(a[j]+a[j+1]==a[j+2])tmp++;
            }
            res=max(res,tmp);
        }
        cout<<res<<"\n";
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
