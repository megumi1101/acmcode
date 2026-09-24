#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    void sol() {
        int n;
        cin>>n;
        int a[n+1],b[n+1];
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++) {
            cin>>b[i];
        }
        int m;
        cin>>m;
        int c[m+1];
        for(int i=1;i<=m;i++)cin>>c[i];
        map<int,int>vis,vis2;
 
        int res=0;
        string ans;
        for(int i=1;i<=n;i++) {
            vis[b[i]]++;
            if(a[i]!=b[i]) {
                vis2[b[i]]++;
                res++;
            }
        }
 
        
        for(int i=1;i<=m;i++) {
            if(vis2[c[i]]) {
                vis2[c[i]]--;
                res--;
            }
        }
        ans="NO";
        if(!res)if(vis[c[m]])ans="YES";
        cout<<ans<<"\n";
        
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
