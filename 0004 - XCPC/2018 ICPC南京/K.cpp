#include<bits/stdc++.h>
using namespace std;
#define N 100
#define debug(x) cerr<<#x<<" == "<<(x)<<endl;
int a[N][N],cnt[N][N],b[N][N];
pair<int,int> fa[N][N];
int vis[N][N],dfn[N][N],siz[N][N];
vector<pair<int,int>>e[N][N];
int n,m,tot;
string s;
int w[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void sol(int x,int y)
{
    if(x==0&&y==-1)  cout<<"L";
    if(x==0&&y==1)  cout<<"R";
    if(x==-1&&y==0)  cout<<"U";
    if(x==1&&y==0)  cout<<"D";
    
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            b[i][j]=cnt[i][j];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if(!a[i][j]) continue;
            if(a[i+x][j+y]) b[i][j]=cnt[i-x][j-y];
            else b[i][j]=cnt[i][j]+cnt[i-x][j-y];
        }

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cnt[i][j]=b[i][j];
}

void move(int &x,int &y,int q,int p)
{
    if(a[x+q][y+p]) x+=q,y+=p;
}

void solve(int x,int y,int q,int p)
{
    while (fa[x][y].first)
    {
        auto [xx,yy]=fa[x][y];
        sol(xx-x,yy-y);
        move(x,y,xx-x,yy-y);
        move(q,p,xx-x,yy-y);
    }
    

    while (x!=q||y!=p)
    {
        int t=dfn[q][p];
        for (auto [xx,yy]:e[x][y])
        {
            if(xx==fa[x][y].first&&yy==fa[x][y].second) continue;
            if(t<dfn[xx][yy]||t>=dfn[xx][yy]+siz[xx][yy]) continue;
            sol(xx-x,yy-y);
            move(x,y,xx-x,yy-y);
            move(q,p,xx-x,yy-y);
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        s=" "+s;
        for (int j=1;j<=m;j++) a[i][j]=s[j]-'0',cnt[i][j]=a[i][j];
    }
    int rx=0,ry=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            if(a[i][j])
            {
                rx=i,ry=j;
                goto end;
            }
    }

    end:

    for (int i=0;i<=n+1;i++)
        for (int j=0;j<=m+1;j++)
            if(i==0||i>n||j==0||j>m)
                vis[i][j]=1;

    auto dfs=[&](auto && self,int x,int y) -> void
    {
        // cout<<x<<" "<<y<<" "<<fa[x][y].first<<" "<<fa[x][y].second<<" !!! "<<endl;
        vis[x][y]=1;
        siz[x][y]=1;
        dfn[x][y]=++tot;
        for (int i=0;i<4;i++)
        {
            int xx=x+w[i][0],yy=y+w[i][1];
            if(a[xx][yy]&&!vis[xx][yy])
            {
                e[x][y].push_back({xx,yy});
                fa[xx][yy]={x,y};
                self(self,xx,yy);
                siz[x][y]+=siz[xx][yy];
            }
        }
    };

    dfs(dfs,rx,ry);

    for (int i=1;i<n;i++) sol(-1,0);
    for (int i=1;i<m;i++) sol(0,1);
    for (int i=1;i<n;i++) sol(1,0);
    for (int i=1;i<m;i++) sol(0,-1);
    
    while (1)
    {
        int x=0,y=0,xx=0,yy=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if(cnt[i][j])
                {
                    if(x&&y) xx=i,yy=j;
                    else x=i,y=j;
                }
        if(!xx) break;
        // debug(x);debug(y);debug(xx);debug(yy);
        solve(x,y,xx,yy);
        // for (int i=1;i<=n;i++)
        // {
        //     for (int j=1;j<=m;j++)
        //         cout<<cnt[i][j]<<" ";
        //     cout<<"\n";
        // }
    }
    return 0;
}
/*
4 4
1111
1001
1001
1110
*/