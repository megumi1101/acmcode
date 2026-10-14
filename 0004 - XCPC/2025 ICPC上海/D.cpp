#include <bits/stdc++.h>
#define N 500010
using namespace std;
int a[N],p[N];
void solve(int x,int w,auto &pos)
{
    if(w==-1) return;
    for (int i=x-1;i>=x-p[w];i--)
    {
        pos[i]=w;
    }
    solve(x-p[w],w-1,pos);
    solve(x-p[w]-p[w],w-1,pos);
}
int main() {
    int n;
    cin >> n;
    for (int i=0;i<(1<<n);i++) cin>>a[i];
    p[0]=1;
    for (int i=1;i<=n;i++) p[i]=p[i-1]*3;

    vector<int>pos(p[n]+1,-1);

    solve(p[n],n-1,pos);

    vector<int>ans(p[n]+1,0);
    for (int i=0;i<(1<<n);i++)
    {
        int x=0;
        for (int j=0;j<n;j++)
            if(i&(1<<j))
                x+=p[j];
        ans[x]=a[i];
    }
    for (int i=0;i<p[n];i++)
    {
        if(pos[i]>-1)
        {
            int j=pos[i];
            ans[i]=ans[i-p[j]]+ans[i-p[j]-p[j]];
        }
    }

    // for (int i=0;i<=4;i++) cout<<ans[i]<<" ";cout<<"\n";
    int sum=0;
    for (int i=0;i<p[n];i++) sum^=ans[i];
    cout<<sum<<"\n";
}