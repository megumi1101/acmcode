#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010
#define mo 1000000007
ll n,T,a[N],b[N],w[N];
ll fac[N];
ll ksm(ll x,ll y)
{
    ll ans=1;
    while (y)
    {
        if(y%2==1) ans=ans*x%mo;
        x=x*x%mo,y/=2;
    }
    return ans;
}
void sol()
{
    cin>>n;
    vector<ll>dep(n+5,1);
    vector<ll>type(n+5,-1);
    vector<ll>d(n+5,0);
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=n;i++) type[i]=-1,dep[i]=1;

    vector<vector<int>>e(n+5);
    for (int i=1;i<=n;i++)
    {
        if(a[i]<a[b[i]]) type[i]=1;
        else if(b[i]==i||(a[i]>=a[b[i]]&&a[i]>=a[b[i]]+w[b[i]])) type[i]=0;
        else e[b[i]].push_back(i),d[i]++;
    }

    queue<int>q;
    for (int i=1;i<=n;i++)
        if(d[i]==0)
            q.push(i);
    
    while (q.size())
    {
        int x=q.front();
        q.pop();
        for (int v:e[x])
        {
            dep[v]=dep[x]+1;
            type[v]=type[x];
            d[v]--;
            if(!d[v]) q.push(v);
        }
    }

    for (int i=1;i<=n;i++)
    {
        if(type[i]==1)
        {
            ll x=dep[i];
            ll sum=ksm(fac[x],mo-2)*(a[i]+w[i])%mo;
            sum=(sum+(fac[x]-1)*ksm(fac[x],mo-2)%mo*a[i]%mo)%mo;
            cout<<sum<<" ";
        }
        else cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    fac[0]=1;
    for (ll i=1;i<=500010;i++) fac[i]=fac[i-1]*i%mo;
    cin>>T;
    while (T--) sol();
    return 0;
}
/*
4
4
2 5 5 2
4 2 1 3
3 2 1 4
3
5 4 3
1 1 1
6 6 6
3
5 4 3
2 3 1
1 2 3
5
2 1 3 2 1
5 1 1 3 4
1 3 4 2 4
*/