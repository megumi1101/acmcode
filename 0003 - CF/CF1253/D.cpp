#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    const int N=2e5+10;
    int fa[N],n,m;
    int find(int x) {
        if(fa[x]==x)return x;
        else return fa[x]=find(fa[x]);
    }
    void hb(int x,int y) {
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy) {
            fa[fy]=fx;
        }
    }
    struct node {
        int l,r,mn,mx;
        friend bool operator<(node a,node b) {
            if(a.l==b.l)return a.r<b.r;
            else return a.l<b.l;
        }
    }a[N],b[N];
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        cin>>n>>m;
        a[0].l=a[0].r=0;
        for(int i=1;i<=m;i++) {
            cin>>a[i].l>>a[i].r;
            if(a[i].l>a[i].r)swap(a[i].l,a[i].r);
        }
        sort(a+1,a+1+m);
        int cnt=0,nowr=0;
        for(int i=1;i<=m;i++) {
            if(a[i].l<=nowr) {
                b[cnt].r=i;
                nowr=max(nowr,a[i].r);
                b[cnt].mx=nowr;
            }
            else {
                b[++cnt].l=i;
                b[cnt].r=i;
                b[cnt].mn=a[i].l;
                b[cnt].mx=a[i].r;
                nowr=a[i].r;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=1;i<=cnt;i++) {
            ans+=b[i].mx-b[i].mn;
            for(int j=b[i].l;j<=b[i].r;j++) {
                if(find(a[j].l)==find(a[j].r))continue;
                hb(a[j].l,a[j].r);
                ans--;
            }
            // for(int j=b[i].mn;j<=b[i].mx;j++) {
            //     ans+=(fa[j]==j);
            // }
        }
        cout<<ans;
    }
}  
int main() {
    return xbbbz::main(), 0;
}
