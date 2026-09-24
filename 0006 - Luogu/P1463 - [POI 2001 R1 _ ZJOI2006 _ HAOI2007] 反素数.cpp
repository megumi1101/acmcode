#include<bits/stdc++.h>
using namespace std;


namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    int n,ans,mx;
    int pr[15]={0,2,3,5,7,11,13,17,19,23,29,31,37};
    void dfs(int dep,int lim,int now,int num) {
        if(dep>10)return;
        int res=now;
        if(num>mx||(num==mx&&now<ans))ans=now,mx=num;
        for(int i=1;i<=lim;i++) {
            res*=pr[dep];
            if(res<=n)dfs(dep+1,i,res,num*(i+1));
            else break;
        }
    }
    void sol() {
        cin>>n;
        dfs(1,35,1,1);
        cout<<ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin>>T;
        // init();
        while(T--) {
            sol();
        }
    }
    #undef int 
}

int main() {
    return xbbbz::main(), 0;
}