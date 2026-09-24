// QOJ user: xbbbz
// Contest: 2025 ç¬?0å±ŠICPCæ­¦æ±‰ç«?// Problem: #14719. Planting Trees (14719)
// Submission: https://qoj.ac/submission/1664111
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
int T,x,y,g,f,n,m;
ll solve(ll a,ll b,ll c,ll n)
{
    if(a<0) return solve(a+c,b,c,n)-n*(n+1)/2;
    if(a==0) return (n+1)*(b/c);
    if(a>=c||b>=c) return solve(a%c,b%c,c,n)+a/c*n*(n+1)/2+b/c*(n+1);
    ll m=(a*n+b)/c;
    return n*m-solve(c,c-b-1,a,m-1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>f>>x>>g>>y>>n>>m;
        f%=m,x%=m,g%=m,y%=m;
        cout<<solve(g-f,y-x+m-1,m,n-1)+solve(f,x,m,n-1)-solve(g,y,m,n-1)<<"\n";
    }
    return 0;
}
/*
1
7 4 6 3 3 4
*/
</code>