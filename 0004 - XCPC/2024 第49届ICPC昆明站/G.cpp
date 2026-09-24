// QOJ user: xbbbz
// Contest: 2024 ç¬?9å±ŠICPCæ˜†æ˜Žç«?// Problem: #9868. GCD (9868)
// Submission: https://qoj.ac/submission/1500611
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define N 5010
#define int long long
#define ll long long
int g[N][N],T,cnt,sum;
ll a,b;
int gcd(int x,int y)
{
    int t;
    while (y)
    {
        t=y,y=x%y,x=t;
    }
    return x;
}
void dfs(int x,int y,int z)
{
    if(x<y) swap(x,y);
    if(x==0&&y==0) {sum=min(sum,z);return;}
    if(x==0||y==0) {sum=min(sum,z+1);return;}
    if(z==cnt) return;
    dfs(x-g[y][x%y],y,z+1);
    dfs(x,y-g[y][x%y],z+1);
}
signed main()
{
    cin>>T;
    for (int i=0;i<=5000;i++)
        for (int j=0;j<=5000;j++)
            g[i][j]=gcd(i,j);
    while (T--)
    {
        cin>>a>>b;
        cnt=0;
        while (1<<cnt<=a) cnt++;
        cnt*=2;
        sum=1000;
        // cout<<cnt<<endl;
        dfs(a,b,0);
        cout<<sum<<endl;
    }
    return 0;
}
/*
1
5000 1000000000000000000
*/
</code>