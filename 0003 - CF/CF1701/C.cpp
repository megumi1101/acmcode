#include <bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N=2e5+10;
    int n,m,s;
    vector<int>a(N);
    int pd(int x) {
        int res=0;
        for(int i=1;i<=n;i++)if(a[i]>=x)res+=a[i]-x;
        for(int i=1;i<=n;i++) {
            if(a[i]<x)res-=(x-a[i])/2;
            if(res<=0)return 1;
        }
        return 0;
    }
    int sol() {
        cin>>n>>m;
        for(int i=1;i<=n;i++)a[i]=0;
        for(int i=1;i<=m;i++) {
            int x;cin>>x;
            a[x]++;
        }
        int l=1,r=2e18,ans=0;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(pd(mid))ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--) cout<<sol()<<"\n";
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
