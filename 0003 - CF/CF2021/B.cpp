#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    void sol() {
        int n,m;
        cin>>n>>m;
        vector<int>a(n*2),vis(n*2);
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        a[n+1]=1e18;
        sort(a.begin()+1,a.begin()+1+n);
        int pos=1;
        for(int i=1;i*m<=n;i++) {
            while(a[pos]<i*m) {
                vis[a[pos]%m]++;
                pos++;
            }
            for(int j=0;j<m;j++) {
                if(vis[j]<i) {
                    cout<<(i-1)*m+j<<"\n";
                    return;
                }
            }
        }
        for(int i=pos;i<=n;i++)if(a[i]<=n)vis[a[i]%m]++;
        for(int i=0;m*(n/m)+i<=n;i++) {
            if(vis[i]<(n/m)+1) {
                cout<<m*(n/m)+i<<"\n";
                return;
            }
        }
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
