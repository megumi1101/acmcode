#include<bits/stdc++.h>
using namespace std;
int n,a[500010],T;
void sol()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int sum=0;
    for (int i=1;i<=n;i++) sum+=a[i];
    if(sum>100)
    {
        int cnt=(sum-100)*2;
        for (int i=1;i<=n;i++)  a[i]*=10;
        for (int i=1;i<=n&&cnt>0;i++)
        {
            if(a[i]>0)
            {
                a[i]-=5;
                cnt--;
            }
        }
        if(cnt) cout<<"No\n";
        else
        {
            cout<<"Yes\n";
            for (int i=1;i<=n;i++) cout<<a[i]<<" ";
            cout<<"\n";
        }
    }
    else
    {
        int cnt=(100-sum)*2,r=cnt+1;
        if(cnt>=n)
        {
            cout<<"No\n";
            return;
        }
        for (int i=1;i<=n;i++) a[i]*=10;
        for (int i=1;i<=n&&cnt>0;i++)
        {
            a[i]+=5;
            cnt--;
        }
        for (int i=1;i<=n;i++) a[i]*=1000;
        a[r]++;
        cout<<"Yes\n";
        for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) sol();
    return 0;
}