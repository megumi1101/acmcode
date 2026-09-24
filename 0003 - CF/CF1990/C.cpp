#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    void sol() {
        int n;
        cin>>n;
        int a[n+5],sum[n+5];
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        map<int,int>mp,mp2;
        int mx=0;
        int ans=0;
        for(int i=1;i<=n;i++)cin>>a[i],ans+=a[i];
        mp[a[1]]++;a[1]=0;
        for(int i=2;i<=n;i++) {
            mp[a[i]]++;
            if(mp[a[i]]==2)mx=max(mx,a[i]);
            a[i]=mx;
            ans+=a[i];
        }
        mx=0;
        mp2[a[2]]++;a[2]=0;
        for(int i=3;i<=n;i++) {
            mp2[a[i]]++;
            if(mp2[a[i]]==2)mx=max(mx,a[i]);
            a[i]=mx;
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=3;i<=n;i++) {
            ans+=sum[i];
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
