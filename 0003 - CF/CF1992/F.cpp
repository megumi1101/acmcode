#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    bool vis[100005],vis2[100005];
    void sol() {
        int n,m;
        cin>>n>>m;
        int a[n+5];
        for(int i=1;i<=n;i++)cin>>a[i];
        int ans=0;
        vector<int>b;
        vector<int>c;
        for(int i=1;i*i<=m;i++) {
            if(m%i==0) {
                vis[i]=1;vis[m/i]=1;
                vis2[i]=1;vis2[m/i]=1;
            }
        }
        for(int i=1;i<=n;i++) {
            if(vis[a[i]]) {
                vector<int>xx;
                for(int v : c) {
                    if(a[i]*v<=m&&vis2[a[i]*v]){
                        vis2[a[i]*v]=0;
                        xx.push_back(a[i]*v);
                    }
                }
                for(int v : xx) c.push_back(v);
                if(vis2[a[i]])c.push_back(a[i]),vis2[a[i]]=0;
            }
            if(!vis2[m]) {
                for(int v : c)vis2[v]=1;
                c.clear();
                ans++;
                c.push_back(a[i]);vis2[a[i]]=0;
            }
        }
        for(int i=1;i*i<=m;i++) {
            if(m%i==0) {
                vis[i]=0;vis[m/i]=0;
                vis2[i]=0;vis2[m/i]=0;
            }
        }
        cout<<ans+1<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
