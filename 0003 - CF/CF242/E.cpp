#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    const int N=1e5+10;
    int n,m;
    vector<int> a(N),b(N);
    struct smt {
        #define mid ((l+r)>>1)
        #define ls (u<<1)
        #define rs (u<<1|1)
        int sum[N<<2],tag[N<<2];
        vector<int>a;
        void pushup(int u) {
            sum[u]=sum[ls]+sum[rs];
        } 
        void build(int u,int l,int r) {
            if(l==r) {sum[u]=a[l]; return;}
            build(ls,l,mid);
            build(rs,mid+1,r);
            pushup(u);
        }
        void pushdown(int u,int l,int r) {
            if(tag[u]) {
                tag[ls]^=1;
                tag[rs]^=1;
                sum[ls]=(mid-l+1)-sum[ls];
                sum[rs]=(r-mid)-sum[rs];
                tag[u]=0;
            }
        }
        void update(int u,int l,int r,int xl,int xr) {
            if(xl<=l&&r<=xr) {
                sum[u]=(r-l+1)-sum[u];
                tag[u]^=1;
                return;
            }
            pushdown(u,l,r);
            if(xl<=mid)update(ls,l,mid,xl,xr);
            if(xr>mid)update(rs,mid+1,r,xl,xr);
            pushup(u);
        }
        int cx(int u,int l,int r,int xl,int xr) {
            int res=0;
            if(xl<=l&&r<=xr) {
                return sum[u];
            }
            pushdown(u,l,r);
            if(xl<=mid)res+=cx(ls,l,mid,xl,xr);
            if(xr>mid)res+=cx(rs,mid+1,r,xl,xr);
            return res;
        }
    } T[20];  
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        for(int j=0;j<20;j++) {
            int x=(1<<j);
            for(int i=1;i<=n;i++) {
                if(a[i]&x)b[i]=1;
                else b[i]=0;
            }
            T[j].a=b;
            T[j].build(1,1,n);
        }
        cin>>m;
        while(m--) {
            int op,l,r,z;
            cin>>op>>l>>r;
            if(op==1) {
                int ans=0;
                for(int j=0;j<20;j++) {
                    int x=(1<<j);
                    ans+=x*(T[j].cx(1,1,n,l,r));
                }
                cout<<ans<<"\n";
            }
            else {
                cin>>z;
                for(int j=0;j<20;j++) {
                    int x=(1<<j);
                    if(z&x) {
                        T[j].update(1,1,n,l,r);
                    }
                }
            }
        }
    }
    #undef int
}  
int main() {
    return xbbbz::main(), 0;
}
/*
5
4 10 3 13 7
8
1 2 4
2 1 3 3
1 2 4
1 3 3
2 2 5 5
1 1 5
2 1 2 10
1 2 3

*/
