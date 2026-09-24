// QOJ user: xbbbz
// Contest: 2024 ç¬?9å±ŠICPCæ˜†æ˜Žç«?// Problem: #9865. Dolls (9865)
// Submission: https://qoj.ac/submission/1513706
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define N 200010
int n,T,a[N];
struct node{int l,r;}b[N];
bool check(int x,int y)
{
    int n=y-x+1;
    vector<int>rank(n+5);
    for (int i=x;i<=y;i++) b[i-x+1].l=a[i];
    for (int i=1;i<=n;i++) rank[i]=b[i].l;
    sort(rank.begin()+1,rank.end());
    for (int i=1;i<=n;i++) b[i].l=b[i].r=lower_bound(rank.begin()+1,rank.end(),b[i].l)-rank.begin();
    // for (int i=x;i<=y;i++) cout<<a[i]<<" ";cout<<endl;
    // for (int i=1;i<=n;i++) cout<<b[i].l<<" ";cout<<endl;

    stack<int>q;
    for (int i=1;i<=n;i++)
    {
        while (q.size()&&(b[q.top()].l==b[i].r+1||b[q.top()].r==b[i].l-1))
        {
            b[i].l=min(b[i].l,b[q.top()].l);
            b[i].r=max(b[i].r,b[q.top()].r);
            q.pop();
        }
        q.push(i);
    }
    if(q.size()==1) return 1;
    else return 0;
}
void solve()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int cnt=0,st=1;
    while (st<=n)
    {
        for (int j=0;j<=17;j++)
        {
            int en=min(n,st+(1<<j));
            int l=st,r=en,mid;
            while (l<r)
            {
                mid=(l+r)/2;
                if(mid==l) mid=r;
                if(check(st,mid)) l=mid;
                else r=mid-1;
            }
            if(r<en||r==n) {st=r+1,cnt++;break;}
        }
    }
    cout<<n-cnt<<endl;
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