#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define ll long long
#define mo 998244353
string s,p;
int n,m,cnt=1;
struct node{
    int fa,len;
    int ch[26];
}sam[N];
void build()
{
    int p,now,x;
    p=now=1;
    for (int i=1;i<=n;i++)
    {
        p=now,now=++cnt;
        x=s[i]-'a';
        sam[now].len=sam[p].len+1;
        for (;p>0&&!sam[p].ch[x];p=sam[p].fa) sam[p].ch[x]=now;
        if(!p) sam[now].fa=1;
        else
        {
            int v=sam[p].ch[x];
            if(sam[v].len==sam[p].len+1) sam[now].fa=v;
            else
            {
                sam[++cnt]=sam[v];
                sam[cnt].len=sam[p].len++;
                sam[v].fa=sam[now].fa=cnt;
                for (;p>0&&sam[p].ch[x]==v;p=sam[p].fa) sam[p].ch[x]=v;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>s,n=s.size();
    cin>>p,m=p.size();
    reverse(s.begin(),s.end());
    reverse(p.begin(),p.end());
    s=" "+s,p=" "+p;
    build();
    int now=1;
    for (int i=1;i<=m;i++) now=sam[now].ch[p[i]-'a'];
    vector<int>bz(2*n+5,0);
    vector<int>v(2*n+5,0);
    vector<vector<int>>e(2*n+5);
    for (int i=2;i<=cnt;i++) e[sam[i].fa].push_back(i);

    auto tag=[&](auto && self,int x) -> void
    {
        if(bz[x]) return;
        bz[x]=1;
        for (int v:e[x]) self(self,v);
    };

    auto dfs=[&](auto && self,int x,int maxlen) -> void
    {
        if(!x||bz[x]) return;
        v[x]=max(0,maxlen-sam[sam[x].fa].len);
        tag(tag,x);
        for (int i=0;i<26;i++) self(self,sam[x].ch[i],maxlen+1);
    };

    dfs(dfs,now,m-1);
    for (int i=2;i<=cnt;i++)
    {
        if(!bz[i])
            v[i]=sam[i].len-sam[sam[i].fa].len;
    }
    // cout<<now<<"\n";
    // for (int i=1;i<=cnt;i++) cout<<bz[i]<<" "<<v[i]<<"\n";

    vector<ll>f(2*n+5,0);
    auto solve=[&](auto && self,int x) -> void
    {
        if(bz[x]==1)
        {
            f[x]=v[x];
            return;
        }
        f[x]=1;
        for (int v:e[x])
        {
            self(self,v);
            f[x]=f[x]*(1+f[v])%mo;
        }
        f[x]=(f[x]-1+v[x]+mo)%mo;
    };
    solve(solve,1);
    cout<<f[1];
    return 0;
}