#include<bits/stdc++.h>
using namespace std;
 
 
namespace xbbbz {
    #define int long long
    void sol() {
        int n;
        cin>>n;
        vector<int> ed[n+5];
        queue<int> q;
        int dep[n+5];
        int rd[n+5];
        memset(dep,0,sizeof(dep));
        memset(rd,0,sizeof(rd));
        for(int i=1;i<=n;i++) {
            int x;
            cin>>x;
            ed[i].push_back(x);
            rd[x]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            if(!rd[i])q.push(i),dep[i]=1,ans=1;
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v:ed[u]) {
                rd[v]--;
                if(rd[v]==0) {
                    dep[v] = dep[u]+1;
                    ans=max(ans,dep[v]);
                    q.push(v);
                }
            }
        }
        cout<<ans+2<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin>>T;
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
