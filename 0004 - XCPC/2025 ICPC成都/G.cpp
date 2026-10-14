#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,m,T;
void sol()
{
    cin>>n>>k>>m;
    ll num=n/k-1;
    ll ans=min(m,n-num-1);
    m-=ans;
    ll x=0;
    if(m>0) x=min(num,m);
    ans+=x,num-=x;
    ans+=1+num/2;
    cout<<ans<<"\n";

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) sol();
    return 0;
}