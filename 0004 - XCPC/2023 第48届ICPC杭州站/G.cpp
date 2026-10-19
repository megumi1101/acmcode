#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define ll long long
int n,m,k;
int x[N],y[N];
int w[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct node
{
    int x,y;
    ll t;
    friend bool operator <(const node &a,const node &b)
    {
        return a.t>b.t;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    vector t(n+5,vector<int>(m+5,0));
    vector ans(n+5,vector<ll>(m+5,-1));
    vector ch(n+5,vector<int>(m+5,-1));
    for (int i=1;i<=k;i++) cin>>x[i]>>y[i];
    for (int i=k,j=1;i>0;i--,j++)
    {
        t[x[i]][y[i]]=j;
    }
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for (int j=1;j<=m;j++)
        {
            if(s[j-1]=='.') ch[i][j]=0;
            else ch[i][j]=1;
        }
    }
    priority_queue<node>q;
    q.push({x[1],y[1],0});
    while (q.size())
    {
        auto [x,y,z]=q.top();
        q.pop();
        if(ans[x][y]==-1) ans[x][y]=z;
        else continue;
        for (int i=0;i<4;i++)
        {
            int xx=x+w[i][0],yy=y+w[i][1];
            if(ans[xx][yy]==-1&&ch[xx][yy]==0) q.push({xx,yy,max((ll)t[xx][yy],ans[x][y]+1)});
        }
    }
    unsigned long long sum=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if(ans[i][j]>=0) sum+=ans[i][j]*ans[i][j];
    cout<<sum<<"\n";
    return 0;
}
/*
4 5 5
3 5
3 4
3 3
3 2
4 2
.....
.....
.....
.....
*/