// QOJ user: xbbbz
// Contest: 2025 ç¬?0å±ŠICPCæ²ˆé˜³ç«?// Problem: #14945. The Bond Beyond Time (14945)
// Submission: https://qoj.ac/submission/1761760
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define N 2010
#define pb push_back
vector<int>e[N];
int n,m,x,y,st,en,mi,T,alice,bob;
int d[N][N];
int find(int st,int en)
{
    vector<int>b(n+5,0);
    vector<vector<int>>trail(n+5);
    queue<int>q;
    q.push(st),b[st]=1,trail[st].pb(st);
    while (q.size())
    {
        int x=q.front();
        q.pop();
        for (int v:e[x])
        {
            if(b[v]||x==st&&v==en) continue;
            b[v]=1,q.push(v);
            trail[v]=trail[x],trail[v].pb(v);
        }
    }
    if(b[en])
    {
        vector<int>dep(n+5,0);
        for (int i=0;i<trail[en].size();i++)
        {
            dep[trail[en][i]]=1,q.push(trail[en][i]);
            if(i+1<trail[en].size()) d[trail[en][i]][trail[en][i+1]]=1;
            else d[en][st]=1;
        }
        while (q.size())
        {
            int x=q.front();
            q.pop();
            for (int v:e[x])
            {
                if(!dep[v]) dep[v]=dep[x]+1,q.push(v);
                if(dep[v]>dep[x]) d[v][x]=1;
            }
        }
        return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>n>>m>>alice>>bob;
        for (int i=1;i<=n;i++) e[i].clear();
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                d[i][j]=0;
        for (int i=1;i<=m;i++)
        {
            cin>>x>>y;
            e[x].pb(y),e[y].pb(x);
        }
        int type=0;
        for (int v:e[bob])
            if(v==alice)
                type=1;
        if(type==1)
        {
            if(n==m+1) {cout<<"No\n";continue;}
            queue<int>q;
            vector<int>b(n+5,0);
            q.push(alice),q.push(bob);
            b[alice]=b[bob]=1;
            int bz=find(alice,bob);
            if(!bz) while (q.size())
            {
                int x=q.front();
                q.pop();
                for (int v:e[x])
                {
                    if((x==alice&&v==bob)||(x==bob&&v==alice)) continue;
                    if(find(x,v)) goto end;
                    if(!b[v]) b[v]=1,q.push(v);
                }
            }
            end:
        }
        else
        {
            for (int v:e[alice]) d[v][alice]=1;
            for (int v:e[bob]) d[v][bob]=1;
        }
        cout<<"Yes\n";
        for (int i=1;i<=n;i++)
            for (int v:e[i])
                if(!d[i][v]&&!d[v][i])
                    d[i][v]=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if(d[i][j])
                    cout<<i<<" "<<j<<"\n";
    }
}
/*
1 
5 10 2 3
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4 
3 5
4 5
*/
</code>