#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    int vis[2][30],visb[2][30];
    void sol() {
        int n;string s;
        memset(vis,0,sizeof(vis));
        memset(visb,0,sizeof(visb));
        cin>>n>>s;
        s=' '+s;
        if(n&1) {
            int ans=n;
            for(int i=1;i<=n;i++)vis[i&1][s[i]-'a']++;
            for(int i=n;i>=1;i--) {
                if(i!=n)visb[i&1][s[i+1]-'a']++;
                vis[i&1][s[i]-'a']--;
                int res0=0,res1=0;
                for(int j=0;j<26;j++) {
                    res0=max(res0,vis[0][j]+visb[0][j]);
                    res1=max(res1,vis[1][j]+visb[1][j]);
                }
                ans=min(ans,n-res0-res1);
            }
            cout<<ans<<"\n";
        }
        else {
            for(int i=1;i<=n;i++)vis[i&1][s[i]-'a']++;
            int res0=0,res1=0;
            for(int j=0;j<26;j++) {
                res0=max(res0,vis[0][j]);
                res1=max(res1,vis[1][j]);
            }
            cout<<n-res0-res1<<"\n";
        }
    }
    void main() {
        int T;
        cin>>T;
        while(T--)sol();
    }
}  
int main() {
    return xbbbz::main(), 0;
}
