// QOJ user: xbbbz
// Contest: 2023 �?8届ICPC沈阳�?// Problem: #7778. Turning Permutation (7778)
// Submission: https://qoj.ac/submission/1681206
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define ll __int128
#define N 55
int n,a[N],b[N];
long long k;
ll f[N][N][N];
const __int128 inf=1e18+1;
struct node{int x,y;}c[N];
bool cmp(node a,node b){return a.x<b.x;}
ll solve(int k)
{
    if(k==n) return 0;
    ll sum=1;
    for (int i=1;i<=k;i++) c[i]={a[i],i};
    c[k+1]={n+1,n+1};
    sort(c+1,c+k+2,cmp);
    int direct=1,blank=n-k;
    for (int i=1;i<=k+1;i++)
    {
        if(c[i].x>c[i-1].x+1)
        {
            if(direct==0||(c[i-1].x>0&&c[i].x<=n&&(c[i].x-c[i-1].x-1)%2==0)) return 0;
            sum*=f[blank][0][c[i].x-c[i-1].x-1];
            if(sum>inf) sum=inf;
            blank-=c[i].x-c[i-1].x-1;
            direct=1;
        }
        else
        {
            if(i==k+1) break;
            if(i==1)
            {
                if(c[2].x==2) direct=(c[2].y>c[1].y);
                else direct=1;
            }
            else
            {
                if((c[i].y>c[i-1].y)!=direct) return 0;
                direct^=1;
            }
        }
    }
    return sum;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) f[i][1][1]=i;
    for (int w=2;w<=n;w++)//位数
        for (int k=2;k<=w;k++)//序列长度
            for (int i=1;i<=k;i++)
            {
                f[w][i][k]=f[w-1][i][k];
                for (int j=i;j<k;j++)
                {
                    f[w][i][k]+=f[w-1][k-j][k-1];
                    if(f[w][i][k]>inf) {f[w][i][k]=inf;break;}
                }
            }
    for (int w=1;w<=n;w++)
        for (int k=1;k<=w;k++)
            for (int i=1;i<=k;i++)
            {
                f[w][0][k]+=f[w][i][k];
                if(f[w][0][k]>inf) {f[w][0][k]=inf;break;}
            }
    if(2*f[n][0][n]<k)
    {
        cout<<"-1";
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if(b[j]) continue;
            a[i]=j;
            ll sum=solve(i);
            // cerr<<i<<" "<<j<<" "<<(long long)sum<<"\n";
            if(sum<k) k-=sum;
            else {b[j]=1;break;}
        }
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}
</code>