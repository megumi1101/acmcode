#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 1e5+10;
    const int mod = 998244353;
    int n;
    int c[N<<1], a[N], b[N];
    int f[N][11], sum[N];
    int lb(int x) {
        return x&-x;
    }
    void add(int x,int k) {
        for(;x<=2*n+5;x+=lb(x))c[x]+=k;
    }
    int cx(int x) {
        int res=0;
        for(;x;x-=lb(x))res+=c[x];
        return res;
    }
    void sol() {
        cin>>n;
        int ans=n*(n+1)/2;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=10;j++)
                f[i][j]=0;
        for(int mid=1;mid<=10;mid++) {
            for(int i=1;i<=2*n+5;i++) c[i]=0;
            int lst=0;
            for(int i=1;i<=n;i++) {
                if(a[i]>mid)b[i]=1;
                else b[i]=-1;
                sum[i] = sum[i-1]+b[i];
                if(a[i]==mid) {
                    for(int j=lst;j<i;j++) {
                        add(sum[j]+n+1,1);
                    }
                    lst=i;
                }
                ans -= cx(sum[i]+n+1) - cx(sum[i]+n);
            }
        }
        cout<<ans<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin>>T;
        // init();
        while(T--) {
            sol();
        }
    }
    #undef int 
}
 
int main() {
    return xbbbz::main(), 0;
}
