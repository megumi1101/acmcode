#include <bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    const int N=1005;
    string s[N];
    int fnx, fny, ans=-1;
    int n, m, k;
    struct node {
        int x,y,deep;
    };
    queue<node>q;
    int plusx[4]={-1,0,1,0};
    int plusy[4]={0,-1,0,1};
    // bool vis[N][N];
    bool vis[N][N][2];
    void bfs(int stx,int sty) {
        q.push({stx,sty,0});
        vis[stx][sty][0] = 1;
        vis[stx][sty][1] = 1;
        while(!q.empty()) {
            node u = q.front();q.pop();
            if(u.x==fnx && u.y==fny) {ans = u.deep;break;}
            for(int dn = 0; dn <= 3; dn++) {
                    for(int i=1; i<=k; i++) {
                    int x = u.x + plusx[dn]*i;
                    int y = u.y + plusy[dn]*i;
                    if(x<1||x>n||y<1||y>m)break;
                    if(s[x][y]=='#')break;
                    if(!vis[x][y][dn%2]) {
                        q.push({x, y, u.deep+1});
                        vis[x][y][dn%2] = 1;
                    }
                    else break;
                }
            }
        }
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)cin>>s[i],s[i]='0'+s[i];
        int x,y;
        cin>>x>>y>>fnx>>fny;
        bfs(x,y);;
        cout<<ans;
    }    
}
int main() {
    return xbbbz::main(), 0;
}
