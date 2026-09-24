#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    const int inf =1e9;
    map <string ,int>mp,vis;
    void sol() {
        int n, k;
        cin >> n >> k;
        vector<bool>vis(300);
        vector<int>a(200005),sum(300),f(300),tun(300),lst(300);
        vector<vector<int>>cost(300,vector<int>(300,0));
        for(int i=1;i<=255;i++)tun[i]=i;
        for(int i=1;i<=255;i++)lst[i]=i;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            if(vis[a[i]])continue;
            vis[a[i]]=1;
            for(int j=a[i];j>=0&&j>=lst[a[i]]-k+1;j--) {
                if(tun[j]+k-1>=lst[a[i]])tun[a[i]]=tun[j];
            }
            for(int j=tun[a[i]];j<=lst[a[i]];j++) {
                tun[j] = tun[a[i]];
                lst[j] = lst[a[i]];
            }
        }
        for(int i=1;i<=n;i++)cout<<tun[a[i]]<<" ";
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        while(T--) sol();
    }
}
 
int main() {
    return xbbbz::main(), 0;
}
