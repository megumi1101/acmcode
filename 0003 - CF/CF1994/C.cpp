#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    void sol() {
        int n,m;
        cin>>n>>m;
        int a[n+5],sum[n+5],d[n+5],ans=0;
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)cin>>a[i], sum[i] = sum[i-1]+a[i], d[i]=1;
        for(int i=1;i<=n;i++) {
            int l=i,r=n;
            int tmp=-1;
            while(l<=r) {
                int mid=(l+r)/2;
                if(sum[mid]-sum[i-1]<=m)tmp=mid,l=mid+1;
                else r=mid-1;
            }
            if(tmp!=-1) {
                ans+=(tmp-i+1)*d[i];
                d[tmp+2]+=d[i];
            }
            else {
                d[i+1]+=d[i];
            }
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
