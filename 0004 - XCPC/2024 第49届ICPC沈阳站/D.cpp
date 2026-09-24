#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define ll long long
#define ing long long
int T,n,a[N],b[N],tree[N],l,r,d;
char ch;
int lowbit(int x){return x&(-x);}
void add(int x,int y)
{
    for (int i=x;i<=n;i+=lowbit(i)) tree[i]+=y;
}
int query(int x)
{
    int sum=0;
    for (int i=x;i>0;i-=lowbit(i)) sum+=tree[i];
    return sum;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>n;
        ll sum=0;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++) cin>>b[i];
        for (int i=n;i>0;i--) sum+=query(a[i]),add(a[i],1);
        for (int i=1;i<=n;i++) add(i,-1);
        for (int i=n;i>0;i--) sum+=query(b[i]),add(b[i],1);
        for (int i=1;i<=n;i++) add(i,-1);
        sum%=2;
        if(sum==0) cout<<"B";
        else cout<<"A";
        for (int i=1;i<n;i++)
        {
            cin>>ch>>l>>r>>d;
            sum=(sum+(r-l)*d)%2;
            if(sum==0) cout<<"B";
            else cout<<"A";
        }
        cout<<"\n";
    }
    return 0;
}
