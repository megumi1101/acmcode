// QOJ user: xbbbz
// Contest: 2024 Á¨?9Â±äICPCÊù≠Â∑ûÁ´?// Problem: #9738. Make It Divisible (9738)
// Submission: https://qoj.ac/submission/1487227
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100010
int a[N],l[N],rev[N],r[N],f[N][18],n,k,T,po[18];
ll ans,cnt;
stack<int>d;
int gcd(int x,int y)
{
    int t;
    while (y!=0){
        t=y,y=x%y,x=t;
    }
    return x;
}
int solve(int x)
{
    if(x<1||x>k) return 0;
    for (int i=1;i<=n;i++)
    {
        if(l[i]==r[i]) continue;
        int j=rev[r[i]-l[i]],y=gcd(f[l[i]][j],f[r[i]-po[j]][j]);
        if(y%(a[i]+x)) return 0;
    }
    return 1;
}
int main()
{
    po[0]=1;for (int i=1;i<=17;i++) po[i]=po[i-1]*2;
    for (int i=1,j=0;i<=N-10;i++)
    {
        if(po[j]*2==i) j++;
        rev[i]=j;
    }
    cin>>T;
    while (T--)
    {
        cnt=ans=0;
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>a[i];
        int bz=0;
        for (int i=2;i<=n;i++)
            if(a[i]!=a[i-1])
                bz=1;
        if(bz==0) {cout<<k<<" "<<(ll)k*(ll)(k+1)/2<<"\n";continue;}

        a[0]=a[n+1]=0;
        d.push(0);
        for (int i=1;i<=n;i++)
        {
            while (d.size()&&a[i]<a[d.top()]) d.pop();
            l[i]=d.top()+1;
            d.push(i);
        }
        while (!d.empty()) d.pop();
        d.push(n+1);
        for (int i=n;i>0;i--)
        {
            while(d.size()&&a[i]<a[d.top()]) d.pop();
            r[i]=d.top()-1;
            d.push(i);
        }
        while (!d.empty()) d.pop();
        for (int i=1;i<n;i++) f[i][0]=abs(a[i+1]-a[i]);
        for (int j=1;j<17;j++)
            for (int i=1;i<=n-po[j];i++)
                f[i][j]=gcd(f[i][j-1],f[i+po[j-1]][j-1]);
        ll x,y;
        for (int i=1;i<n;i++)
            if(a[i]!=a[i+1])
            {
                if(a[i]>a[i+1]) x=a[i]-a[i+1],y=a[i+1];
                else x=a[i+1]-a[i],y=a[i];
                break;
            }
        for (ll i=1;i*i<=x;i++)
        {
            if(x%i!=0) continue;
            if(solve(i-y)) cnt++,ans+=(i-y);
            if(i*i!=x&&solve(x/i-y)) cnt++,ans+=(x/i-y);
        }
        cout<<cnt<<" "<<ans<<endl;
    }
    return 0;
}
/*
3
5 10
7 79 1 7 1
5 2
7 79 1 7 1
5 1
7 79 1 7 1
*/
</code>