#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define ll long long
#define int long long
int tot,p[N],b[N],cnt[N];
int n,m,a[N];
signed main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];

    cnt[1]=1;
    for (int i=2;i<=N-10;i++)
    {
        if(!b[i]) p[++tot]=i,cnt[i]=2;
        for (int j=1;j<=tot&&i*p[j]<=N-10;j++)
        {
            b[i*p[j]]=1;
            if(i%p[j]==0)
            {
                cnt[i*p[j]]=2*cnt[i]-cnt[i/p[j]];
                break;
            }
            else cnt[i*p[j]]=cnt[i]*2;
        }
    }

    ll ans=0;
    cnt[0]=m;
    for (int i=2;i<n;i++)
    {
        ll g=0;
        for (int l=i-1,r=i+1;l>0&&r<=n;l--,r++)
        {
            g=gcd(g,abs(a[l]-a[r]));
            ans+=(cnt[g]-1);
            // if(cnt[g]-1>0) cout<<l<<" "<<r<<"\n";
        }
    }
    for (int i=1;i<n;i++)
    {
        ll g=0;
        for (int l=i,r=i+1;l>0&&r<=n;l--,r++)
        {
            g=gcd(g,abs(a[l]-a[r]));
            ans+=(cnt[g]-1);
            // if(cnt[g]-1>0) cout<<l<<" "<<r<<"\n";
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/*
5 4
1 3 2 4 3
*/