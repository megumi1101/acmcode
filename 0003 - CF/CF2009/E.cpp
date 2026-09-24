#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    bool pd(int n,int x,int k) {
        return ((x*(2*k+x-1))-n*(2*k+n-1)/2)>0;
    }
    void sol() {
        int n,k;
        cin>>n>>k;
        int l=0,r=n;
        int ans=-1;
        int tans;
        while(l<=r) {
            int mid = (l+r)/2;
            if(pd(n,mid,k))ans=mid,r=mid-1;
            else l=mid+1;
        }
        tans=((ans*(2*k+ans-1))-n*(2*k+n-1)/2);
        tans=min(tans,n*(2*k+n-1)/2-((ans-1)*(2*k+ans-2)));
        cout<<tans<<"\n";
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
