#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int n,k;
        cin>>n>>k;
        int a[n+5];
        for(int i=1;i<=n;i++)cin>>a[i];
        a[n+2]=0;
        if(n==k) {
            for(int i=2;i<=n+2;i+=2) {
                if(a[i]!=i/2) {
                    cout<<i/2<<"\n";
                    return;
                }
            }
        }
        else {
            for(int i=2;i<=n-k+2;i++) {
                if(a[i]!=1) {
                    cout<<"1"<<"\n";
                    return;
                }
            }
            cout<<"2"<<"\n";
        }
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
