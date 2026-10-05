#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mo 1000000007
#define N 1000010
int n;
ll m,a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    int bz=0;
    for (int i=1;i<=n;i++)
        if(a[i]>=2&&a[i]<n)
            bz=1;
    if(a[1]==1||a[n]==1) bz=1;

    for (int i=1;i<n;i++)
        if(a[i]==1&&a[i+1]==1)
            bz=1;
    if(bz==1)
    {
        ll ans=1;
        for (int i=1;i<=n;i++)
            if(a[i]==-1)
                ans=ans*m%mo;
        cout<<ans;
        return 0;
    }
    vector f(n+5,vector<ll>(2,0));
    ll res=max(0ll,m-n+1);
    if(a[1]==-1) f[1][0]=res;
    else f[1][0]=1;
    for (int i=2;i<=n;i++)
    {
        if(a[i]!=-1)
        {
            if(a[i]!=1) f[i][0]=(f[i-1][0]+f[i-1][1])%mo;
            else f[i][1]=f[i-1][0];
        }
        else
        {
            f[i][0]=(f[i-1][0]+f[i-1][1])%mo*res%mo;
            f[i][1]=f[i-1][0];
        }
        // cout<<i<<" "<<f[i][0]<<" "<<f[i][1]<<"\n";
    }

    ll ans=mo-f[n][0];
    ll t=1;
    for (int i=1;i<=n;i++)
        if(a[i]==-1)
            t=t*m%mo;
    ans=(ans+t)%mo;
    
    int bj=1;
    for (int i=1;i<=n;i++)
        if(a[i]!=-1&&a[i]!=1)
            bz=0;
    if(bj==1&&n%2==1) ans=(ans+mo-1)%mo;
    cout<<ans<<"\n";
    return 0;
}