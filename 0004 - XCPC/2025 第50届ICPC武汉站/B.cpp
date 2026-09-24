// QOJ user: xbbbz
// Contest: 2025 ç¬?0å±ŠICPCæ­¦æ±‰ç«?// Problem: #14720. 77G Network (14720)
// Submission: https://qoj.ac/submission/1649147
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define N 4000010
#define M 400010
#define pb push_back
vector<int>e[N],ed[N];
int label[N],rev[N],dfn[N],vis[N],low[N],fa[M][20],f[N];
int T,n,x,y,q,tot,cnt;
struct node{int x,y;};
stack<int>st;
void bfs()
{
    queue<node>q;
    q.push({1,0});
    int cnt=0;
    while (q.size())
    {
        int x=q.front().x,y=q.front().y;
        q.pop();
        label[x]=++cnt;
        rev[cnt]=rev[cnt+n]=x;
        fa[cnt][0]=y;
        if(y>0) ed[cnt+n].pb(y),ed[y+n].pb(cnt);
        for (int v:e[x]) q.push({v,cnt});
    }
}
void build(int l,int r,int k)
{
    for (int i=l;i<=r;i++) ed[i].pb(2*n+k),ed[6*n+k].pb(i+n);
    if(l==r) return;
    int mid=(l+r)/2;
    build(l,mid,k*2),build(mid+1,r,k*2+1);
}
void find(int l,int r,int k,int x,int y,int z)
{
    if(l>=x&&r<=y)
    {
        ed[z].pb(6*n+k);
        ed[2*n+k].pb(z+n);
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) find(l,mid,k*2,x,y,z);
    if(mid<y) find(mid+1,r,k*2+1,x,y,z);
}
void tarjan(int x)
{
    dfn[x]=low[x]=++tot;
    vis[x]=1;
    st.push(x);
    for (int v:ed[x])
    {
        if(!dfn[v])
        {
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(vis[v]) low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        ++cnt;
        while (1)
        {
            int u=st.top();
            st.pop();
            vis[u]=0,f[u]=cnt;
            if(u==x) break;
        }
    }
}
void clear()
{
    for (int j=0;j<=18;j++)
        for (int i=1;i<=n;i++)
            fa[i][j]=0;
    for (int i=0;i<=n;i++) e[i].clear();
    for (int i=0;i<=10*n;i++) dfn[i]=low[i]=f[i]=0,ed[i].clear();
}
int leap(int x,int dep)
{
    for (int i=0;i<=18;i++)
        if(dep&(1<<i))
            x=fa[x][i];
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>n;
        for (int i=2;i<=n;i++)
        {
            cin>>x;
            e[x].pb(i);
        }
        bfs();
        build(1,n,1);
        for (int j=1;j<=18;j++)
            for (int i=1;i<=n;i++)
                fa[i][j]=fa[fa[i][j-1]][j-1];
        cin>>q;
        for (int i=1;i<=q;i++)
        {
            cin>>x>>y;
            x=label[x];
            int l=1,r=n+1,mid,ll=n+1,rr=0;
            while (l<r)
            {
                mid=l+r>>1;
                if(leap(mid,y)<x) l=mid+1;
                else
                {
                    r=mid;
                    if(leap(mid,y)==x) ll=min(ll,mid);
                }
            }
            l=1,r=n+1;
            while (l<r)
            {
                mid=l+r>>1;
                if(leap(mid,y)>x) r=mid;
                else
                {
                    if(leap(mid,y)==x) rr=max(rr,mid);
                    l=mid+1;
                }
            }
            if(rr) find(1,n,1,ll,rr,x);
            // cout<<"ll="<<ll<<","<<"rr="<<rr<<endl;
        }
        tot=cnt=0;
        for (int i=1;i<=10*n;i++)
            if(!dfn[i])
                tarjan(i);
        int bz=0;
        for (int i=1;i<=n;i++)
            if(f[i]==f[i+n])
                bz=1;
        if(bz==1) {cout<<"No\n";clear();continue;}
        cout<<"Yes\n";
        vector<int>ans;
        for (int i=1;i<=n;i++)
            if(f[i]<f[i+n])
                ans.pb(rev[i]);
        cout<<ans.size()<<"\n";
        for (int i:ans) cout<<i<<" ";
        cout<<"\n";
        clear();
    }
    return 0;
}
/*
3
6
1 1 2 2 4
2
1 3
2 1
6
1 1 2 2 4
6
1 1
1 2
1 3
2 1
2 2
2 1
8
1 1 3 1 1 2 4
10
1 2
3 2
1 3
5 1
6 1
3 2
4 1
3 2
5 1
3 1
*/
</code>