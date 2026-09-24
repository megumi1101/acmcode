#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    void sol() {
        int n,m,k,w;
        cin>>n>>m>>k>>w;
        int a[w+5],b[n*m+5];
        for(int i=1;i<=w;i++)cin>>a[i];
        sort(a+1,a+w+1,[&](int a,int b){return a>b;});
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                int pos = (i-1)*m+j;
                int x=min(i+k-1,n)-max(i,k)+1;
                int y=min(j+k-1,m)-max(j,k)+1;
                b[pos]=x*y;
            }
        }
        int ans=0;
        sort(b+1,b+n*m+1,[&](int a,int b){return a>b;});
        for(int i=1;i<=w;i++) {
            ans+=a[i]*b[i];
        }
        cout<<ans<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
