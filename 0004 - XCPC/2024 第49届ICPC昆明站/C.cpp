// QOJ user: xbbbz
// Contest: 2024 ç¬?9å±ŠICPCæ˜†æ˜Žç«?// Problem: #9864. Coin (9864)
// Submission: https://qoj.ac/submission/1502963
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,T;
int main()
{
    cin>>T;
    while (T--)
    {
        cin>>n>>k;
        ll x=1;
        while (1)
        {
            ll y=(x-1)/(k-1)+1;
            if(n<=y*(k-1)) {x+=(n-x)/(y)*(y);break;}
            x+=(y*(k-1)-x)/y*y;
            if(x+y<=n) x+=y;
            else break;
        }
        cout<<x<<endl;
    }
    return 0;
}
</code>