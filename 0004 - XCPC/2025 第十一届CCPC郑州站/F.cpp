#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int x[]={-1,0,1,0},y[]={0,-1,0,1};
string s;
bool map_[1001][1001],mark[1001][1001],end_[1001][1001];
int n,m;
struct node{
    int x,y,cnt;
    node(int x_=-1,int y_=-1,int cnt_=-1,bool mark_=false) :x(x_),y(y_),cnt(cnt_) {}
};
queue<node> q,q1;
int bfs(){
    while(!q.empty()) q.pop();
    int a,b;
    node now;
    q.push(node(n,m)),mark[n][m]=true,end_[n][m]=true;
    while(!q.empty()){
        now=q.front(),q.pop();
        for(int i=0;i<4;++i){
            a=now.x+x[i],b=now.y+y[i];
            if(1<=a&&a<=n&&1<=b&&b<=m&&map_[a][b]&&!mark[a][b]) q.push(node(a,b)),mark[a][b]=true,end_[a][b]=true;
        }
    }
    if(end_[1][1]) return 0;
    while(!q1.empty()) q1.pop();
    q1.push(node(1,1,0,false)),mark[1][1]=true,q.push(node(1,1,0,false));
    while(!q1.empty()){
        now=q1.front(),q1.pop();
        for(int i=0;i<4;++i){
            a=now.x+x[i],b=now.y+y[i];
            if(1<=a&&a<=n&&1<=b&&b<=m&&map_[a][b]&&!mark[a][b]) q1.push(node(a,b,0)),q.push(node(a,b,0)),mark[a][b]=true;
        }
    }
    while(!q.empty()){
        now=q.front(),q.pop();
        // cout<<"now.x="<<now.x<<" now.y="<<now.y<<" now.cnt="<<now.cnt<<'\n';
        for(int i=0;i<4;++i){
            a=now.x+x[i],b=now.y+y[i];
            if(1<=a&&a<=n&&1<=b&&b<=m){
                // cout<<"a="<<a<<" b="<<b<<" map_[a][b]="<<map_[a][b]<<" mark[a][b]="<<mark[a][b]<<'\n';
                if(end_[a][b]) return now.cnt;
                if(!mark[a][b]) q.push(node(a,b,now.cnt+1)),mark[a][b]=true;
            }
        }
    }
    return 0;
}
int main(){
    // freopen("F.out","w",stdout);
    int T;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            cin>>s;
            for(int j=1;j<=m;++j) map_[i][j]=(s[j-1]=='.'),mark[i][j]=false,end_[i][j]=false;
        }
        // for(int i=1;i<=n;++i){
        //     for(int j=1;j<=m;++j) cout<<(int)map_[i][j];
        //     cout<<'\n';
        // }
        cout<<bfs()<<'\n';
    }
    return 0;
}
/*
2
3 4
..##
###.
.##.
3 2
..
##
..
 
*/
