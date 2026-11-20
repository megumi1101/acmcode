#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int> > mark;
void solution(){
    int n,m,k;
    vector<int> x,y,z;
    cin>>n>>m>>k;
    x.resize(m),y.resize(m),z.resize(m);
    for(int i=0;i<m;++i) cin>>x[i]>>y[i]>>z[i];
    mark.resize(k);
    for(int i=0;i<k;++i){
        mark[i].resize(n+1);
        for(int j=1;j<=n;++j) mark[i][j]=-1;
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<k;++j){
            if(z[i]&(1<<j)){
                // cout<<"i = "<<i<<" j = "<<j<<" x[i] = "<<x[i]<<" y[i] = "<<y[i]<<" z[i] = "<<z[i]<<'\n';
                if(mark[j][x[i]]==0||mark[j][y[i]]==0){
                    cout<<"-1\n";
                    return;
                }
                mark[j][x[i]]=mark[j][y[i]]=1;
            }
        }
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<k;++j){
            if(!(z[i]&(1<<j))){
                if(mark[j][x[i]]==1&&mark[j][y[i]]==1){
                    cout<<"-1\n";
                    return;
                }
            }
        }
    }
    long long res=0ll;
    for(int i=0;i<k;++i) for(int j=1;j<=n;++j) if(mark[i][j]==1) res+=(1<<i);
    cout<<res<<'\n';
}
int main(){
    int T;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solution();
    return 0;
}
/*
1
3 3 1
1 2 0
1 3 0
2 3 1

5
3 3 1
1 2 0
1 3 0
2 3 1
3 2 30
1 2 1073741823
2 3 1073741823
3 3 1
1 2 1
1 3 1
2 3 0
100 1 16
1 1 4514
3 4 3
1 1 5
2 2 6
1 2 4
1 3 5


*/