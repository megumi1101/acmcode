#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int n,x,y;
        cin>>n>>x>>y;
        int a[n+1],b[n+1];
        for(int i=1;i<=n;i++)a[i]=(i&1)^1;
        int xx=y-x+1;
        if(n&1) {
            if(!a[xx]) {
                a[xx]=2;
                for(int i=xx+1;i<=n;i++)a[i]^=1;
            }
            else {
                a[n]=2;
            }
        }
        else {
            if(!a[xx])a[xx]=2;
        }
        for(int i=1;i<=n;i++) {
            b[(i+x-2)%n+1]=a[i];
        }
        for(int i=1;i<=n;i++)cout<<b[i]<<" ";
        cout<<"\n";
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
