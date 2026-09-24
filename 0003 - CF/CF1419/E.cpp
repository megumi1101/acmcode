#include<bits/stdc++.h>
using namespace std;
const int warma = 1e5+114;
int t,n;
void solve(){
    cin>>n;
    set<int> S;
    for(int i=1;i<=min(n,warma);i++){
        if(n%i==0) S.insert(i);
        if(n%(n/i)==0) S.insert(n/i);
    }
    S.erase(1);
    vector<int> p;
    vector<int> end;
    int N=n;
    for(int x:S){
        if(N%x==0){
            p.push_back(x);
            while(N%x==0) N/=x;
        }
    }
    if(p.size()==2&&p[0]*p[1]==n){
        cout<<p[0]<<' '<<p[1]<<' '<<n<<'\n';
        cout<<1<<'\n';
        return ;
    }
    for(int i=0;i<p.size();i++){
        int u=p[i]*p[(i+1)%p.size()];
        if(S.find(u)==S.end()) u=n;
        end.push_back(u);
        S.erase(u);
    }
    vector< vector<int> > d;
    d.resize(p.size());
    for(int x:S){
        for(int i=0;i<p.size();i++){
            if(x%p[i]==0){
                d[i].push_back(x);
                break;
            }
        }
    }
    for(int i=0;i<p.size();i++){
        for(int x:d[i]) cout<<x<<' ';
        cout<<end[i]<<' ';
    }
    cout<<'\n';
    cout<<0<<'\n';
    return ;
}
int main(){
    cin>>t;
    while(t--) solve();
    return 0;
}
//by ChiFAN
