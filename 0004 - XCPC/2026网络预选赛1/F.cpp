#include<bits/stdc++.h>
using namespace std;
long long x,ans=0,pre=0,sum;
int n,m;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        sum=0;
        for (int j=1;j<=m;j++)
            cin>>x,sum+=x;
        if(sum<pre) ans++;
        pre=sum;
    }
    cout<<ans<<"\n";
    return 0;
}