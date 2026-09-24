// QOJ user: xbbbz
// Contest: 2022 Á¨?7Â±äICPCÂçó‰∫¨Á´?// Problem: #5426. Drain the Water Tank (5426)
// Submission: https://qoj.ac/submission/1528969
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define N 100010
struct node{ld x,y;}a[N],b[N];
int n;
const ld pi=acos(-1);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    ld mi=10000000.0;
    int pos=0;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i]={(ld)x,(ld)y};
        if(mi>(ld)y) mi=(ld)y,pos=i;
    }
    for (int i=pos;i<=n;i++) b[i-pos+1]=a[i];
    for (int i=1;i<pos;i++) b[n-pos+i+1]=a[i];
    for (int i=1;i<=n;i++) a[i]=b[i];
    // for (int i=1;i<=n;i++) cout<<a[i].x<<" "<<a[i].y<<endl;
    a[0]=a[n],a[n+1]=a[1];
    int cnt=0,bz=1;
    for (int i=1;i<=n;i++)
    {
        ld x=atan2(a[i+1].y-a[i].y,a[i+1].x-a[i].x);
        ld y=atan2(a[i-1].y-a[i].y,a[i-1].x-a[i].x);
        // cout<<x<<" "<<y<<endl;
        if(0.0<x&&0.0<y&&x<y) cnt+=bz,bz=0;
        if(x<-1e-9) bz=1;
        if(x>1e-9) bz=0;
    }
    cout<<cnt<<endl;
    return 0;
}
/*
6
3 0
3 2
0 2
0 0
1 1
2 1
*/
</code>