#include <bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 1e6+10;
    #define mid ((l+r)>>1)
    #define ls (u<<1)
    #define rs ((u<<1)|1)
    int sum[N<<2], tag[N<<2];
    int n,w;
    deque<int> q;
    int cf[N];
    int ans[N];
    // void pushup (int u) {
    //     sum[u] = sum[ls] + sum[rs];
    // }
    // void pushdown(int u, int l, int r) {
    //     tag[ls] += tag[u];
    //     tag[rs] += tag[u];
    //     sum[ls] += tag[u] * (mid-l+1);
    //     sum[rs] += tag[u] * (r-mid+1);
    //     tag[u] = 0;
    // }
    // void add(int u, int l, int r, int xl, int xr, int k) {
    //     if(xl<=l&&r<=xr) {
    //         tag[u] += k;
    //         sum[u] += k * (r-l+1);
    //         return;
    //     }
    //     pushdown(u,l,r);
    //     if(xl<=mid) add(ls, l, mid, xl, xr, k);
    //     if(xr>mid) add(rs, mid+1, r, xl, xr, k);
    //     pushup(u);
    // }
    // int cx(int u, int l, int r, int xl, int xr) {
    //     int res=0;
    //     if(xl<=l&&r<=xr) {return sum[u];}
    //     pushdown(u,l,r);
    //     if(xl<=mid) res += cx(ls, l, mid, xl, xr);
    //     if(xr>mid) res += cx(rs, mid+1, r, xl, xr);
    //     return res;
    // }
    void add(int l,int r,int k) {
        cf[l]+=k;
        cf[r+1]-=k;
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        cin>>n>>w;
        for(int i=1;i<=n;i++) {
            int l;
            cin>>l;
            vector<int> a(l+5,0);
            for(int i=1;i<=l;i++)cin>>a[i];
            q.clear();
            if(w-l < l) {
                for(int i=1;i<=w;i++){
                    while(!q.empty()&&q.front()<=i-(w-l+1))q.pop_front();
                    if(i<=l)while(!q.empty()&&a[q.back()]<=a[i])q.pop_back();
                    if(i<=l)q.push_back(i);
                    int tmp = a[q.front()];
                    if(i<=w-l||i>l)tmp=max(tmp,(int)0);     
                    add( i, i, tmp);
                }
            }
            else {  
                int res=0;
                for(int i=1;i<=l;i++) res=max(res,a[i]), add( i, i, res);
                res=0;
                for(int i=1;i<=l;i++) res=max(res,a[l-i+1]), add( w-i+1, w-i+1, res);
                if(l+1<=w-l) {
                    add(l+1, w-l, res);            
                }
            }
        }
        for(int i=1;i<=w;i++) {
            ans[i] = ans[i-1]+cf[i];
        }
        for(int i=1;i<=w;i++) {
            cout<<ans[i]<<" ";
        }
    }
 
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
