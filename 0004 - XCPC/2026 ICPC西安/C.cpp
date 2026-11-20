#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define N 4010
int n,m,T;
ll x,y,z,a[N],b[N];
void sol()
{
    cin>>n>>m>>x>>y>>z;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    vector f(m+1,vector<ll>(n+1,0));
    for (int i=1;i<=n;i++)
    {
        f[1][i]=x+(i-1)*z+abs(b[1]-a[i])*y;
        // cout<<f[1][i]<<" ";
    }
    for (int i=2;i<=m;i++)
    {
        ll ans=0x3f3f3f3f3f3f3f3f;
        for (int j=1;j<=n;j++)
        {
            ans=min(ans,f[i-1][j]+(n-j)*z+x);
        }
        f[i][1]=ans+abs(a[1]-b[i])*y;
        for (int j=2;j<=n;j++)
        {
            ans=min(ans+z,f[i-1][j-1]);
            f[i][j]=ans+abs(a[j]-b[i])*y;
        }

        // for (int j=1;j<=n;j++) cout<<f[i][j]<<" ";cout<<"\n";
    }
    ll ans=0x3f3f3f3f3f3f3f3f;
    for (int i=1;i<=n;i++) ans=min(ans,f[m][i]+(n-i)*z);
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) sol();
    return 0;
}
/*
1
6 7 3 2 5
1 1 4 5 1 4
1 9 1 9 8 1 0



4
6 7 3 2 5
1 1 4 5 1 4
1 9 1 9 8 1 0
3 2 5 6 7
11 45 14
1919 810
1 7 0 0 0
998244353
1 0 1 0 0 0 0
1 1 1000000 1000000 1000000
0
1000000000
*/