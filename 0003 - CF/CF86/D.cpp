#include<bits/stdc++.h>
using namespace std;

namespace xbbbz {
    #define int long long
    const int N=2e5+10;
    int n,m;
    int a[N], id[N] ,cnt[N*5], ans[N], tans;
    struct node {
        int l,r,num;
        friend bool operator < (const node &a , const node &b) {
            if(id[a.l] == id[b.l]) return a.r < b.r;
            else return id[a.l] < id[b.l];
        }
    }b[N];
    void add(int x) {
        cnt[a[x]]++;
        tans+=( cnt[a[x]]*cnt[a[x]] - (cnt[a[x]]-1)*(cnt[a[x]]-1) ) *a[x];
    }
    void del(int x) {
        tans-=( cnt[a[x]]*cnt[a[x]] - (cnt[a[x]]-1)*(cnt[a[x]]-1) ) *a[x];
        cnt[a[x]]--;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        cin>>n>>m;
        int bl = sqrt(n);
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            id[i] = (i-1)/bl+1;
        }
        for(int i=1;i<=m;i++) {
            cin>>b[i].l>>b[i].r;
            b[i].num=i;
        }
        sort(b+1,b+1+m);
        int l=1, r=0;
        for(int i=1;i<=m;i++) {
            while(r<b[i].r)add(++r);
            while(r>b[i].r)del(r--);
            while(l<b[i].l)del(l++);
            while(l>b[i].l)add(--l);
            ans[b[i].num]=tans;
        }
        for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
    }
    #undef int
}

int main() {
    return xbbbz::main(), 0;
}
