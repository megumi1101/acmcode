#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int n;
        cin>>n;
        int a[n+5];
        int b[n+5];
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        int x=a[1]+b[1];
        int z=a[n]+b[n];
        for(int i=2;i<=n-1;i++) {
            for(int j=2;j<=n-1;j++) {
                if(a[i]+b[j]>x&&a[i]+b[j]<z) {
                    cout<<"YES\n";
                    return;
                }
            }
        }
        cout<<"NO\n";
        
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
