// QOJ user: xbbbz
// Contest: 2025 第十一届CCPC重庆站热身赛
// Problem: #15343. 动态的果子合并 (15343)
// Submission: https://qoj.ac/submission/1795199
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define N 600010
#define ll long long
#define int long long
ll cnt[60],x,n,m,type;
ll get(ll x)
{
    ll cnt=0;
    for (ll i=1;;i*=2)
    {
        if(i==x) return cnt;
        if(i>x) return cnt-1;
        cnt++;
    }
}
ll solve(ll x)
{
    return x*(55-get(x));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    ll sum=0,tot=0;
    for (int i=1;i<=n;i++) cin>>x,tot+=x,sum+=solve(x),cnt[get(x)]++;
    for (ll i=2;i<=(1ll<<54);i*=2) sum+=solve(i),cnt[get(i)]++;
    for (int j=1;j<=m;j++)
    {
        cin>>type>>x;
        if(type==1) cnt[get(x)]++,sum+=solve(x),tot+=x;
        else cnt[get(x)]--,sum-=solve(x),tot-=x;
        if(tot<2)
        {
            if(tot==0) cout<<"72057594037927822"<<"\n";
            else cout<<"72057594037927932"<<"\n";
            continue;
        }
        ll ans=sum;
        vector<ll>cnt1(60,0);
        for (int i=0;i<=54;i++) cnt1[i]=cnt[i];
        for (int i=0;i<=53;i++)
        {
            if(cnt1[i]%2==1) ans+=(1ll<<(i+1));
            cnt1[i+1]+=cnt1[i]/2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
</code>