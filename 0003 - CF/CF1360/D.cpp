#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    void sol() {
        int n,k;
        cin>>n>>k;
        int ans=1;
        for(int i=1;i*i<=n;i++) {
            if(n%i==0) {
                if(i<=k)ans=max(ans,i);
                if(n/i<=k)ans=max(ans,n/i);
            }
        }
        cout<<n/ans<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        int T=1;
        cin>>T;
        while(T--)sol();
    }
}
int main() {
    return xbbbz::main(), 0;
}
