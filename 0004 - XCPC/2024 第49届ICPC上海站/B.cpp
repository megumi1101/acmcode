// QOJ user: xbbbz
// Contest: 2024 ç¬?9å±ŠICPCä¸Šæµ·ç«?// Problem: #9038. Basic Graph Algorithm (9038)
// Submission: https://qoj.ac/submission/1540300
// Language: C++23

#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define int long long
#define ll long long
int n,m,x,y,ans,fa[N],cnt[N],a[N];
vector<int>e[N];
map<ll, int> mp;
const ll p=1e9;
struct node{int x,y;}edge[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y;
        cnt[x]++,cnt[y]++;
        e[x].push_back(y);
        e[y].push_back(x);
        mp[x*p+y]=mp[y*p+x]=1;
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    int now=0;
    for (int i=1;i<=n;i++)
    {
        while (now&&!cnt[now]) now=fa[now];
        if(!now) now=a[i];
        else
        {
            if(!mp[now*p+a[i]]) edge[++ans]={now,a[i]};
            fa[a[i]]=now,now=a[i];
        }
        for (int v:e[a[i]]) cnt[v]--;
    }
    cout<<ans<<"\n";
    for (int i=1;i<=ans;i++) cout<<edge[i].x<<" "<<edge[i].y<<"\n";
    return 0;
}
/*
6 5
1 2
2 3
3 4
2 4
5 6
1 2 3 4 5 6
*/
</code>