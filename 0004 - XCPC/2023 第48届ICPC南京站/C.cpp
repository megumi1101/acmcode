// QOJ user: xbbbz
// Contest: 2023 Á¨?8Â±äICPCÂçó‰∫¨Á´?// Problem: #7735. Primitive Root (7735)
// Submission: https://qoj.ac/submission/1627343
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define double long double
ll T,p,m;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>p>>m;
        ll prem=0,prep=0,ans=0;
        for (ll i=60;i>=0;i--)
        {
            ll w=(m&(1ll<<i))>0;
            prem=(prem<<1)+w;
            prep=(prep<<1)+(((p-1)&(1ll<<i))>0);
            if(w==0) continue;
            ll l=(((prem-1)^prep)<<i),r=((((prem-1)^prep)+1)<<i)-1;
            ans+=floorl((double)(r-1)/(double)p)-ceill((double)(l-1)/(double)p)+1;
            // cout<<i<<" "<<((prem-1)^prep)<<" "<<l<<" "<<r<<endl;
        }
        ll l=prem^prep,r=l;
        ans+=floorl((double)(r-1)/(double)p)-ceill((double)(l-1)/(double)p)+1;
        cout<<ans<<endl;
    }
    return 0;
}
/*
1
4 2
*/
</code>