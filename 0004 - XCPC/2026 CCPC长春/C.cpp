#include<bits/stdc++.h>
using namespace std;
#define N 400010
int n,k,a[N],T;
void sol()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>v(k+5,0);
    for (int i=1,j=1;i<=n;i++,j=j%k+1)
    {
        if(a[i]>k) continue;
        v[(a[i]-j+k)%k]++;
    }
    int ans=0;
    for (int i=0;i<k;i++) ans=max(ans,v[i]);
    cout<<n-ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) sol();
    return 0;
}