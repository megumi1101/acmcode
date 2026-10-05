#include<bits/stdc++.h>
using namespace std;
#define N 2010
long double f[2010][5010][2][2];
int a[N],b[N],c[N],d[N],e[N],n,m;
long double p[N];
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i]>>p[i],p[i]/=100;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=m;j++)
            for (int a=0;a<=1;a++)
                for (int b=0;b<=1;b++)
                    f[i][j][a][b]=-1e18;
    for (int i=n;i>0;i--)
        for (int j=0;j<=m;j++)
        {
            if(j>=d[i]+e[i]) f[i][j][1][1]=f[i+1][j-d[i]-e[i]][0][0]+c[i];
            if(j>=d[i])
            {
                f[i][j][0][1]=f[i+1][j-d[i]][0][1]*(1-p[i])+f[i+1][j-d[i]][1][1]*p[i]+c[i];
                f[i][j][1][0]=f[i+1][j-d[i]][1][0]*p[i]+f[i+1][j-d[i]][1][1]*(1-p[i])+c[i];
                f[i][j][0][0]=f[i+1][j-d[i]][1][0]*p[i]+f[i+1][j-d[i]][0][1]*(1-p[i])+c[i];
            }
            if(j>=b[i]) f[i][j][1][1]=max(f[i][j][1][1],f[i+1][j-b[i]][1][1]+a[i]);
            if(j>=b[i])
            {
                f[i][j][0][1]=max(f[i][j][0][1],f[i+1][j-b[i]][0][1]*(1-p[i])+f[i+1][j-b[i]][1][1]*p[i]+a[i]);
                f[i][j][1][0]=max(f[i][j][1][0],f[i+1][j-b[i]][1][0]*p[i]+f[i+1][j-b[i]][1][1]*(1-p[i])+a[i]);
                f[i][j][0][0]=max(f[i][j][0][0],f[i+1][j-b[i]][1][0]*p[i]+f[i+1][j-b[i]][0][1]*(1-p[i])+a[i]);
            }
        }
    long double ans=-1;
    for (int j=0;j<=m;j++)
        ans=max(ans,f[1][j][0][0]);
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}