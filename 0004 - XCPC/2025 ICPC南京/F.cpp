#include<bits/stdc++.h>
using namespace std;
#define N 4100
int T,n,m,x,y,w;
char ch;
void dfs(int w,auto &fa)
{

    auto get=[&](auto && self,int x,int w) -> int
    {
        if(fa[w][x]==x) return x;
        fa[w][x]=self(self,fa[w][x],w);
        return fa[w][x];
    };

    if(get(get,x,w)==get(get,y,w)) return;
    fa[w][get(get,x,w)]=get(get,y,w);
    if(w==0) return;

    for (int i=0;i<12;i++)
    {
        if(w&(1<<i))
            dfs(w-(1<<i),fa);
    }
}
void sol()
{
    cin>>n>>m;
    vector fa(4100,vector<int>(n+5,0));
    for (int i=0;i<(1<<12);i++)
        for (int j=1;j<=n;j++)
            fa[i][j]=j;

    auto get=[&](auto && self,int x,int w) -> int
    {
        if(fa[w][x]==x) return x;
        fa[w][x]=self(self,fa[w][x],w);
        return fa[w][x];
    };

    long long ans=0;
    for (int k=1;k<=m;k++)
    {
        cin>>ch;
        if(ch=='+')
        {
            cin>>x>>y>>w;
            dfs(w,fa);
        }
        else
        {
            cin>>x>>y;
            int now=0;
            for (int i=11;i>=0;i--)
            {
                now+=(1<<i);
                if(get(get,x,now)!=get(get,y,now)) now-=(1<<i);
            }
            if(now==0&&get(get,x,0)!=get(get,y,0)) now=-1;
            ans+=now;
        }
    }
    cout<<ans<<"\n";
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
2
4 11
+ 1 3 6
+ 3 4 2
? 1 4
+ 1 4 3
? 4 1
+ 4 3 4
? 1 4
+ 3 2 3
? 1 2
+ 1 1 4
? 1 3
4 4
+ 1 2 64
+ 3 4 32
? 1 2
? 3 1
*/