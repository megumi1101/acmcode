#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int n,k,x;
        cin>>n>>k>>x;
        vector<int>a(n+10);
        int ans=0;
        int sum[200005];
        int ss[200005];
        for(int i=0;i<=n+1;i++)sum[i]=ss[i]=0;
        for(int i=1;i<=n;i++)cin>>a[i],ans+=a[i];
        sort(a.begin()+1,a.begin()+n+1,[&](int a,int b){return a>b;});
        for(int i=n;i>=1;i--){
            if(n-i+1<=x)ss[i]=ss[i+1]+a[i];
            else ss[i]=ss[i+1]+a[i]-a[i+x];
        }
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
        int res=-1e9;
        for(int i=0;i<=k;i++){
            res=max(res,-sum[i]-2*ss[i+1]);
        }
        ans+=res;
        cout<<ans<<"\n";
    }
    void main() {
        int T;
        cin >> T;
        while(T--) {
            sol();
        }
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
