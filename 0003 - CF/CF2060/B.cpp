#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    const int mod = 998244353;
    void sol() {
        int n,m;
        cin>>n>>m;
        int a[n+5][m+5];
        int b[n+5];
        int c[n+5];
        for(int i=1;i<=n;i++)c[i]=i;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++) {
            for(int j=1;j<m;j++) {
                if((a[i][j]%n) != (a[i][j+1]%n)) {
                    cout<<"-1\n";
                    return;
                }
            }
            b[i]=a[i][1]%n;
        }
        sort(c+1,c+1+n,[&](int i,int j){return b[i]<b[j];});
        for(int i=1;i<=n;i++)cout<<c[i]<<" ";
        cout<<"\n"; 
        
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
