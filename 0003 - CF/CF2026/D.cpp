#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    const int N=3e5+10;
    int n,f[N],g[N],sum[N],a[N],b[N];
    int sol(int x) {
        if(x==0)return 0;
        int l=0,r=n-1,res,ans=0;
        while(l<=r) {
            int mid=(l+r)/2;
            if(x>b[mid])res=mid,l=mid+1;
            else r=mid-1;
        }
        ans+=f[res];
        x-=b[res];
        ans+=g[res+x]-g[res]-x*sum[res];
        return ans;
    }
    void main() {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)b[i]=b[i-1]+(n-i+1);
        for(int i=1;i<=n;i++) {
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1;i<=n;i++)f[1]+=sum[i];
        for(int i=1;i<n;i++)f[i+1]=f[i]-(n-i+1)*a[i];
        for(int i=1;i<=n;i++)f[i]+=f[i-1];
        for(int i=1;i<=n;i++)g[i]=g[i-1]+sum[i];
        int T;
        cin>>T;
        while(T--) {
            int l,r;
            cin>>l>>r;
            cout<<sol(r)-sol(l-1)<<"\n";
        }
    }
    #undef int
}  
int main() {
    return xbbbz::main(), 0;
}
/*
4
1 2 5 10
1
1 10
*/
