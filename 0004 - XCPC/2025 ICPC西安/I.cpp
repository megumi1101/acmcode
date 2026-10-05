#include<bits/stdc++.h>
using namespace std;
#define N 2010
int n,a[N][N],sum[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
            cin>>a[i][j],a[j][i]=a[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            sum[i]^=a[i][j];
    vector<pair<int,int>>ans;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if((sum[i]^sum[j])==0||(sum[i]^sum[j])==i||(sum[i]^sum[j])==j||(sum[i]^sum[j])==(i^j))
            {
                int bz=1;
                for (int k=1;k<=n;k++)
                    if((a[i][k]^a[j][k])!=i&&(a[i][k]^a[j][k])!=j)
                        bz=0;
                if(bz==1) ans.push_back({i,j});
            }
    for (auto [x,y]:ans) cout<<x<<" "<<y<<"\n";
    return 0;
}