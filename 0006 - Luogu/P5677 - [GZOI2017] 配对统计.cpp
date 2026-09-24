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
    struct node {
        int l,r,id;
        friend bool operator < (node a, node b) {
            return a.r < b.r;
        }
    }s[N<<1], t[N];
    void sol() {
        cin>>n>>m;
        int a[n+5];
        int pos[n+5];
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            pos[i]=i;
        }
        sort(pos+1,pos+1+n,[&](int i, int j){return a[i] < a[j];});
        sort(a+1,a+1+n,[&](int i, int j){return i < j;});
        a[0]=-inf, a[n+1]=inf;
        int cnt=0;
        for(int i=1;i<=n;i++) {
            if(a[i]-a[i-1]<=a[i+1]-a[i]) {
                s[++cnt] = {min(pos[i], pos[i-1]),max(pos[i], pos[i-1]),cnt};
            }
            
            if(a[i]-a[i-1]>=a[i+1]-a[i]) {
                s[++cnt] = {min(pos[i], pos[i+1]),max(pos[i], pos[i+1]),cnt};
                // add(min(pos[i], pos[i+1]),1,c1);
                // add(max(pos[i], pos[i+1]),1,c2);
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++) {
            int l,r;
            cin>>l>>r;
            t[i]={l,r,i};
        }
        sort(s+1,s+1+cnt);
        sort(t+1,t+1+m);

        int p=1;
        for(int i=1;i<=m;i++) {
            while(s[p].r<=t[i].r&&p<=cnt) {
               add(s[p].l, 1, c1);
               p++;
            }
            ans += t[i].id * (p-1-cx(t[i].l-1,c1));
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