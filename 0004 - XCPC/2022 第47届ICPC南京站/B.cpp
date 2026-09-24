// QOJ user: xbbbz
// Contest: 2022 �?7届ICPC南京�?// Problem: #5415. Ropeway (5415)
// Submission: https://qoj.ac/submission/1521904
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010
#define inf 0x3f3f3f3f3f3f3f3f
int T,n,k,x,m,b[N];
ll sum,ans,a[N],f[N][2],g[N][2],y;
string s;
int main()
{
    cin>>T;
    while (T--)
    {
        cin>>n>>k;
        for (int i=0;i<=2*n+1;i++) f[i][0]=f[i][1]=g[i][0]=g[i][1]=inf;
        for (int i=1;i<=n;i++) cin>>a[i];
        cin>>s;
        for (int i=0;i<n;i++) b[i+1]=s[i]-'0';
        a[0]=a[n+1]=0,b[0]=b[n+1]=1;
        sum=0;
        for (int i=1;i<=n;i++)
            if(b[i]==1)
                sum+=a[i];
        if(k==1)
        {
            sum=0;
            for (int i=1;i<=n;i++) sum+=a[i];
            cin>>m;
            for (int i=1;i<=m;i++)
            {
                cin>>x>>y;
                cout<<sum+y-a[x]<<endl;
            }
            continue;
        }
        deque<int>q;
        q.push_back(0);
        f[0][1]=0,f[0][0]=inf;
        for (int i=1;i<=n+1;i++)
        {
            while (q.size()&&i-q.front()>=k) q.pop_front();
            if(b[i]==1) f[i][0]=inf,f[i][1]=min(f[i-1][0],f[i-1][1]);
            else f[i][0]=f[q.front()][1],f[i][1]=min(f[i-1][0],f[i-1][1])+a[i];
            while (q.size()&&f[i][1]<=f[q.back()][1]) q.pop_back();
            q.push_back(i);
        }
        q.clear();
        q.push_back(n+1);
        g[n+1][1]=0,g[n+1][0]=inf;
        for (int i=n;i>=0;i--)
        {
            while (q.size()&&q.front()-i>=k) q.pop_front();
            if(b[i]==1) g[i][0]=inf,g[i][1]=min(g[i+1][1],g[i+1][0]);
            else g[i][0]=g[q.front()][1],g[i][1]=min(g[i+1][1],g[i+1][0])+a[i];
            while (q.size()&&g[i][1]<=g[q.back()][1]) q.pop_back();
            q.push_back(i);
        }
        q.clear();
        // for (int i=0;i<=n+1;i++) cout<<"i="<<i<<" f[i][0]="<<f[i][0]<<" f[i][1]="<<f[i][1]<<endl;
        // for (int i=0;i<=n+1;i++) cout<<"i="<<i<<" g[i][0]="<<g[i][0]<<" g[i][1]="<<g[i][1]<<endl;
        cin>>m;
        for (int i=1;i<=m;i++)
        {
            cin>>x>>y;
            if(b[x]==1) {cout<<f[n+1][1]+y-a[x]+sum<<endl;continue;}
            ans=inf;
            //选a_i
            for (int i=x+1;i<=min(n+1,x+k);i++) ans=min(ans,f[x][1]+y-a[x]+g[i][1]);
            //不选a_i
            ll mi=inf;
            int st=max(0,x-k+1);
            for (int i=x+1;i<=st+k-1;i++) mi=min(mi,g[i][1]);
            for (int i=st;i<x;i++)
            {
                mi=min(mi,g[i+k][1]);
                ans=min(ans,f[i][1]+mi);
            }
            cout<<ans+sum<<endl;
        }
    }
    return 0;
}
/*
1
10 3
5 10 7 100 4 3 12 5 100 1
0001000010
1
4 1
*/
</code>