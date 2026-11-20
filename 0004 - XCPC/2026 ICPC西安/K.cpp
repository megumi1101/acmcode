#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string op;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>op;
    if(op=="first"){
        int n,m;
        vector<int> x,y,p,rk;
        cin>>n>>m;
        x.resize(m),y.resize(m),p.resize(n+1),rk.resize(n+1);
        for(int i=0;i<m;++i) cin>>x[i]>>y[i];
        for(int i=1;i<=n;++i) cin>>p[i],rk[p[i]]=i;
        for(int i=0;i<m;++i) cout<<(rk[x[i]]<rk[y[i]]);
    }
    else{
        int n,m;
        cin>>n>>m;
        vector<int> x(m),y(m);
        vector<vector<int> > g(n+1);
        for(int i=0;i<m;++i) cin>>x[i]>>y[i],g[x[i]].push_back(y[i]);
        string s;
        cin>>s;
        ;
    }
    return 0;
}