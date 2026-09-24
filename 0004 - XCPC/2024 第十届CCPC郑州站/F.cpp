// QOJ user: xbbbz
// Contest: 2024 第十届CCPC郑州�?// Problem: #9773. Infinite Loop (9773)
// Submission: https://qoj.ac/submission/1433066
// Language: C++23


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define N 200010
int n,q,k,x,y,a[N],b[N],t[N],sum[N];
void print(int x)
{
    x--;
    // cerr<<"ans="<<" ";
    cout<<(x-1)/k+1<<" "<<((x%k==0)?k:(x%k))<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>k>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        sum[i]=sum[i-1]+b[i];
    }
    for (int i=1;i<=n;i++)
    {
        if(t[i-1]>=a[i]) t[i]=t[i-1]+b[i];
        else t[i]=a[i]+b[i];
    }
    // for (int i=1;i<=n;i++) cout<<"t:"<<t[i]<<endl;
    ll ti=t[n];
    int bz=0;
    for (int i=1;i<=n;i++)
    {
        // cout<<ti<<endl;
        if(ti<=a[i]+k) {bz=i;break;}
        ti+=b[i];
    }
    // cout<<"bz="<<bz<<endl;
    if(sum[n]>=k)
    {
        for (int i=1;i<=q;i++)
        {
            cin>>x>>y;
            if(x==1) print(t[y]);
            else print(t[n]+(x-2)*sum[n]+sum[y]);
        }
        return 0;
    }
    for (int i=1;i<=q;i++)
    {
        cin>>x>>y;
        if(x==1) print(t[y]);
        else
        {
            if(t[n]<=k+1) print((x-1)*k+t[y]);
            else
            {
                if(y<bz) print(t[n]+(x-2)*k+sum[y]);
                else print((x-1)*k+t[y]);
            }
        }
    }
    return 0;
}
/*
2 6 1
1 2
2 3
3 1
*/
</code>