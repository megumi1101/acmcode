#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int x,m;
        cin>>x>>m;
        int l=0,r=m/x+1;
        int res=-1,ans=0;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(((mid*2*x)^x)<=m)res=mid,l=mid+1;
            else r=mid-1;
        }
        ans=res+1;
        res=-1;
        l=0,r=m/x+1;
        while(l<=r) {
            int mid=(l+r)>>1;
            if((((mid*2+3)*x)^x)<=m)res=mid,l=mid+1;
            else r=mid-1;
        }
        ans+=res+1;
        for(int i=1;i<=min(2*x+1,m);i++) {
            if((x^i)%i==0 && (x^i)%x!=0)ans++;
        }
        cout<<ans<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
