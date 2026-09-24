#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace Std
{
    inline ll read(void)
    {
        ll now=0,nev=1;
        char c=getchar();
        while(c<'0'||c>'9'){if(c=='-'){nev=-1;}c=getchar();}
        while(c>='0'&&c<='9'){now=(now<<1)+(now<<3)+(c^48);c=getchar();}
        return now*nev;
    }
    ll n,q,s,ls[400001],rs[400001],rt1,rt2,tot=0,head[400001],to[3000001],len[3000001],nxt[3000001],cnt=0,dis[400001],inf=0x3f3f3f3f3f3f3f3f,ans[100001];
    bool vis[400001];
    vector<ll>vv1,vv2;
    queue<ll>qq;
    inline void add(ll x,ll y,ll z)
    {
        to[++cnt]=y;
        len[cnt]=z;
        nxt[cnt]=head[x];
        head[x]=cnt;
    }
    inline ll build1(ll l,ll r)
    {
        ll x=++tot;
        if(l!=r)
        {
            ll mid=l+r>>1;
            ls[x]=build1(l,mid);
            rs[x]=build1(mid+1,r);
            add(ls[x],x,0);
            add(rs[x],x,0);
        }
        return x;
    }
    inline ll build2(ll l,ll r)
    {
        ll x=++tot;
        if(l!=r)
        {
            ll mid=l+r>>1;
            ls[x]=build2(l,mid);
            rs[x]=build2(mid+1,r);
            add(x,ls[x],0);
            add(x,rs[x],0);
        }
        return x;
    }
    void adddfs(ll x1,ll x2,ll l,ll r)
    {
        if(l==r){add(x1,x2,0);add(x2,x1,0);return;}
        ll mid=l+r>>1;
        adddfs(ls[x1],ls[x2],l,mid);
        adddfs(rs[x1],rs[x2],mid+1,r);
    }
    inline void find1(ll x,ll l,ll r,ll L,ll R)
    {
        if(L<=l&&r<=R){vv1.push_back(x);return;}
        ll mid=l+r>>1;
        if(L<=mid)find1(ls[x],l,mid,L,R);
        if(mid<R)find1(rs[x],mid+1,r,L,R);
    }
    inline void find2(ll x,ll l,ll r,ll L,ll R)
    {
        if(L<=l&&r<=R){vv2.push_back(x);return;}
        ll mid=l+r>>1;
        if(L<=mid)find2(ls[x],l,mid,L,R);
        if(mid<R)find2(rs[x],mid+1,r,L,R);
    }
    inline void change(ll l1,ll r1,ll l2,ll r2,ll num)
    {
        vv1.clear();
        find1(rt1,1,n,l1,r1);
        vv2.clear();
        find2(rt2,1,n,l2,r2);
        for(ll i=0;i<vv1.size();i++)
        {
            for(ll j=0;j<vv2.size();j++)
            {
                add(vv1[i],vv2[j],num);
            }
        }
    }
    inline ll find(ll x,ll num,ll l,ll r)
    {
        if(l==r)return x;
        ll mid=l+r>>1;
        if(num<=mid)return find(ls[x],num,l,mid);
        else return find(rs[x],num,mid+1,r);
    }
    inline void spfa(ll x)
    {
        memset(dis,0x3f,sizeof(dis));
        dis[x]=0;
        qq.push(x);
        while(!qq.empty())
        {
            ll u=qq.front();
            qq.pop();
            vis[u]=0;
            for(ll i=head[u];i;i=nxt[i])
            {
                if(dis[to[i]]>dis[u]+len[i])
                {
                    dis[to[i]]=dis[u]+len[i];
                    if(!vis[to[i]])
                    {
                        vis[to[i]]=1;
                        qq.push(to[i]);
                    }
                }
            }
        }
    }
    inline void dfs(ll x,ll l,ll r)
    {
        if(l==r)
        {
            if(dis[x]==inf)ans[l]=-1;
            else ans[l]=dis[x];
            return;
        }
        ll mid=l+r>>1;
        dfs(ls[x],l,mid);
        dfs(rs[x],mid+1,r);
    }
    inline int main(void)
    {
        n=read(),q=read(),s=read();
        rt1=build1(1,n);
        rt2=build2(1,n);
        adddfs(rt1,rt2,1,n);
        for(ll i=1;i<=q;i++)
        {
            ll opt=read(),u,v,l,r,w;
            switch(opt)
            {
                case 1:
                u=read(),v=read(),w=read();
                change(u,u,v,v,w);
                break;
                case 2:
                u=read(),l=read(),r=read(),w=read();
                change(u,u,l,r,w);
                break;
                case 3:
                v=read(),l=read(),r=read(),w=read();
                change(l,r,v,v,w);
            }
        }
        spfa(find(rt1,s,1,n));
        dfs(rt2,1,n);
        for(ll i=1;i<=n;i++)
        {
            printf("%lld ",ans[i]);
        }
        return 0;
    }
}
int main()
{
    return Std::main();
}
