#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010
int T,n;
ll a[N];
void sol()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    vector<ll>sum(n+5,0);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for (int i=1;i<=min(n,2);i++) cout<<"0 ";
    for (int i=3;i<=n;i++)
    {
        ll ans=0;
        for (int j=n;j>=i;j--)
            if(a[j]<sum[j-1]-sum[j-i])
            {
                ans=sum[j]-sum[j-i];
                break;
            }
        cout<<ans<<" ";
    }
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