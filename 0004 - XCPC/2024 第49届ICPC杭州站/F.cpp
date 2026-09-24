// QOJ user: xbbbz
// Contest: 2024 Á¨?9Â±äICPCÊù≠Â∑ûÁ´?// Problem: #9731. Fuzzy Ranking (9731)
// Submission: https://qoj.ac/submission/1508073
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define N 400010
#define int long long
int T,rev[N],n,q,k;
int query(int x){return x*(x-1)/2;}
void solve()
{
    cin>>n>>k>>q;
    vector<vector<int>> a(k+5,vector<int>(n+5));
    vector<int>zuo(n+5,0);
    vector<int>you(n+5,0);
    vector<int>sum(n+5,0);
    for (int i=1;i<=k;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=n;i++) rev[a[1][i]]=i;
    for (int i=1;i<=k;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=rev[a[i][j]];
    int ma=0,lastma=0;
    for (int j=1;j<=n;j++)
    {
        for (int i=1;i<=k;i++) ma=max(ma,a[i][j]);
        if(ma==j)
        {
            sum[j]=sum[j-1]+query(j-lastma);
            for (int i=lastma+1;i<=j;i++) zuo[i]=lastma,you[i]=ma;
            lastma=ma,ma=0;
        }
        else sum[j]=sum[j-1];
    }
    int lastans=0;
    for (int i=1;i<=q;i++)
    {
        int id,l,r;
        cin>>id>>l>>r;
        id=(id+lastans)%k+1;
        l=(l+lastans)%n+1;
        r=(r+lastans)%n+1;
        // cout<<id<<" "<<l<<" "<<r<<endl;
        if(zuo[l]==zuo[r]) lastans=query(r-l+1);
        else lastans=sum[zuo[r]]-sum[you[l]]+query(you[l]-l+1)+query(r-zuo[r]);
        cout<<lastans<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) solve();
    return 0;
}
/*
2
5 2 2
1 2 3 4 5
5 4 3 2 1
1 0 2
1 2 1
5 3 3
1 2 3 4 5
1 3 2 4 5
1 2 3 5 4
0 0 2
0 2 3
1 0 3
*/
</code>