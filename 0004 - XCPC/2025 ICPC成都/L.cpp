#include<bits/stdc++.h>
using namespace std;
#define N 400010
int n,T,a[N],b[N];
void sol()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    vector<vector<int>>e(n+5);
    vector<int>cnta(n+5,0);
    vector<int>cntb(n+5,0);
    vector<int>son(n+5,0);
    vector<int>siz(n+5,0);
    vector<int>ans(n+5,0);
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        e[x].push_back(y),e[y].push_back(x);
    }
    auto dfs=[&](auto && self,int x,int fa) -> void
    {
        siz[x]=1;
        for (auto v:e[x])
        {
            if(v==fa) continue;
            self(self,v,x);
            siz[x]+=siz[v];
            if(siz[son[x]]<siz[v]) son[x]=v;
        }
    };

    int numa=0,numb=0,tota=0,totb=0;
    dfs(dfs,1,0);

    auto add=[&](int x) -> void
    {
        if(a[x]==0) numa++;
        else
        {
            if(cntb[a[x]]<=cnta[a[x]]) tota++;
            else totb--;
            cnta[a[x]]++;
        }
        
        if(b[x]==0) numb++;
        else
        {
            if(cnta[b[x]]<=cntb[b[x]]) totb++;
            else tota--;
            cntb[b[x]]++;
        }
    };

    auto del=[&](int x) -> void
    {
        if(a[x]==0) numa--;
        else
        {
            if(cnta[a[x]]>cntb[a[x]]) tota--;
            else totb++;
            cnta[a[x]]--;
        }

        if(b[x]==0) numb--;
        else
        {
            if(cntb[b[x]]>cnta[b[x]]) totb--;
            else tota++;
            cntb[b[x]]--;
        }
    };

    auto solve=[&](auto && self,int x,int fa,int type) -> void
    {
        if(type==1) add(x);
        else del(x);
        for (int v:e[x])
        {
            if(v==fa) continue;
            self(self,v,x,type);
        }
    };

    auto dfs1=[&](auto && self,int x,int fa) -> void
    {
        for (int v:e[x])
        {
            if(v==fa||v==son[x]) continue;
            self(self,v,x);
        }
        if(son[x]) self(self,son[x],x);
        for (int v:e[x])
        {
            if(v==fa||v==son[x]) continue;
            solve(solve,v,x,1);
        }
        add(x);
        
        if(tota<=numb&&totb<=numa) ans[x]=1;

        if(son[fa]!=x) solve(solve,x,fa,-1);
    };

    dfs1(dfs1,1,0);
    // for (int i=1;i<=n;i++) cout<<i<<" "<<siz[i]<<" "<<son[i]<<"\n";

    for (int i=1;i<=n;i++) cout<<ans[i];
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) sol();
    return 0;
}
/*
3
6
1 5 0 3 4 0
0 3 4 5 2 0
1 2
2 3
2 4
1 5
5 6
5
2 2 3 0 4
4 1 4 2 0
1 2
2 3
3 4
4 5
3
1 2 3
3 2 1
1 2
2 3
*/