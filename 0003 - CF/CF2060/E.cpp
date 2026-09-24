#include<bits/stdc++.h>
using namespace std;
 
 
namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    struct DSU {
        std::vector<int> f, siz;
        
        DSU() {}
        DSU(int n) {
            init(n);
        }
        
        void init(int n) {
            f.resize(n);
            std::iota(f.begin(), f.end(), 0);
            siz.assign(n, 1);
        }
        
        int find(int x) {
            while (x != f[x]) {
                x = f[x] = f[f[x]];
            }
            return x;
        }
        
        bool same(int x, int y) {
            return find(x) == find(y);
        }
        
        bool merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return false;
            }
            siz[x] += siz[y];
            f[y] = x;
            return true;
        }
        
        int size(int x) {
            return siz[find(x)];
        }
    };
    void sol() {
        int n, m1, m2;
        cin>>n>>m1>>m2;
        DSU f(n+5), g(n+5);
        int a[m1+5], b[m1+5];
        int cf=n,cg=n;
        for(int i=1;i<=m1;i++) {
            cin>>a[i]>>b[i];
        } 
        for(int i=1;i<=m2;i++) {
            int x,y;
            cin>>x>>y;
            cg-=g.merge(x,y);
        }
        int ans=0;
        for(int i=1;i<=m1;i++) {
            if(g.same(a[i], b[i])) {
                cf-=f.merge(a[i], b[i]);
            }
            else {
                ans++;
            }
        }
        ans+=cf-cg;
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
