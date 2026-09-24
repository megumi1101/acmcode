// QOJ user: xbbbz
// Contest: 2023 ç¬?8å±ŠICPCæµå—ç«?// Problem: #7902. Strange Sorting (7902)
// Submission: https://qoj.ac/submission/1453742
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define N 201
int n,T,a[N];
void solve()
{
    cin>>n;
    int cnt=0;
    int x[N],y[N];
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        if(a[i]==i) continue;
        for (int j=n;j>i;j--)
            if(a[j]<a[i])
            {
                sort(a+i,a+j+1);
                x[++cnt]=i,y[cnt]=j;
                break;
            }
    }
    cout<<cnt<<endl;
    for (int i=1;i<=cnt;i++) cout<<x[i]<<" "<<y[i]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) solve();
    return 0;
}
</code>