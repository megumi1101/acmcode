// QOJ user: xbbbz
// Contest: 2025 ç¬?0å±ŠICPCæ­¦æ±‰ç«?// Problem: #14721. Not Aqre (14721)
// Submission: https://qoj.ac/submission/1644901
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define N 2010
int T,n,m,nn,mm,a[N][N],z[N][N];
void print(int type)
{
    if(type==1)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++) cout<<a[i][j];
            cout<<"\n";
        }
    }
    else
    {
        for (int j=1;j<=m;j++)
        {
            for (int i=1;i<=n;i++) cout<<a[i][j];
            cout<<"\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    z[1][1]=z[2][2]=z[3][3]=z[3][4]=z[2][5]=z[1][6]=0;
    z[2][1]=z[1][2]=z[1][3]=z[2][4]=z[3][5]=z[3][6]=1;
    z[3][1]=z[3][2]=z[2][3]=z[1][4]=z[1][5]=z[2][6]=2;
    for (int i=1;i<=3;i++)
        for (int j=7;j<N;j++)
            z[i][j]=z[i][(j-1)%6+1];
    for (int i=4;i<=6;i++)
        for (int j=1;j<N;j++)
            z[i][j]=z[7-i][j];
    for (int i=7;i<N;i++)
        for (int j=1;j<N;j++)
            z[i][j]=z[(i-1)%6+1][j];
    while (T--)
    {
        cin>>nn>>mm;
        if(nn%3==0) n=nn,m=mm;
        else n=mm,m=nn;
        if(n%3==0&&m%3==0&&n>m) swap(n,m);
        if(m==1)
        {
            if(n==3) a[1][1]=0,a[2][1]=1,a[3][1]=2;
            else if(n==6) a[1][1]=a[2][1]=0,a[3][1]=a[4][1]=1,a[5][1]=a[6][1]=2;
            else a[1][1]=-1;
        }
        else if(m==2)
        {
            if(n==3) a[1][1]=a[1][2]=0,a[2][1]=a[2][2]=1,a[3][1]=a[3][2]=2;
            else if(n==6) a[1][1]=a[1][2]=a[2][1]=a[2][2]=0,a[3][1]=a[3][2]=a[4][1]=a[4][2]=1,a[5][1]=a[5][2]=a[6][1]=a[6][2]=2;
            else a[1][1]=-1;
        }
        else
        {
            if(m==4)
            {
                a[1][1]=a[1][2]=a[2][3]=a[3][4]=a[4][4]=a[5][3]=a[6][2]=a[6][1]=0;
                a[1][3]=a[2][1]=a[2][2]=a[3][1]=a[4][2]=a[4][3]=a[5][4]=a[6][4]=1;
                a[1][4]=a[2][4]=a[3][2]=a[3][3]=a[4][1]=a[5][1]=a[5][2]=a[6][3]=2;
                for (int i=7;i<=n;i++)
                    for (int j=1;j<=m;j++)
                        a[i][j]=a[(i-1)%6+1][j];
            }
            else
            {
                for (int i=1;i<=n;i++)
                    for (int j=1;j<=m;j++)
                        a[i][j]=z[i][j];
            }
        }
        if(a[1][1]==-1) {cout<<"No\n";continue;}
        cout<<"Yes\n";
        print((n==nn)&(m==mm));
    }
    return 0;
}
/*
0012
1102
1220
2110
2201
0021

0012
1102
1220
2110
2201
0021
*/
</code>