#include<bits/stdc++.h>
using namespace std;
 
 
namespace xbbbz {
    #define int long long
    const int N = 3e5+10;
    const int inf =1e18;
    int n, m;
    int c1[N], c2[N];
    int lb(int x) {
        return x&(-x);
    }
    void add(int x, int k, int *c) {
        for(;x<=n;x+=lb(x))c[x]+=k;
    }
    int cx(int x, int *c) {
        int res=0;
        for(;x;x-=lb(x))res+=c[x];
        return res;
    }
    void sol() {
        cin>>n;
        int a[n+5], b[n+5];
        int c[n+5], p[n+5];
        for(int i=1;i<=n;i++)cin>>a[i];   
        for(int i=1;i<=n;i++)cin>>b[i], p[i]=i;
        sort(p+1,p+1+n,[&](int i, int j){return a[i]<a[j];});      
        sort(a+1,a+1+n,[&](int i, int j){return i<j;});
        
        for(int i=1;i<=n;i++)c[i]=b[p[i]];
        for(int i=1;i<=n;i++)b[i]=c[i];
        map<int,int>mp;
        sort(c+1,c+1+n);
        for(int i=1;i<=n;i++)mp[c[i]] = i;
        for(int i=1;i<=n;i++)b[i]=mp[b[i]];
 
        int ans=0;
        for(int i=1;i<=n;i++) {
            ans += cx(b[i],c1) * a[i] ;
            ans -= cx(b[i],c2);
            add(b[i], 1, c1);
            add(b[i], a[i], c2);
        }
        cout<<ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin>>T;
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
