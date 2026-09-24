#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    int cnt=0;
    int ch[N*31][2];
    void add(int x) {
        int u = 0;
        for(int i=30;i>=0;i--) {
            int v = (x>>i)&1;
            if(!ch[u][v])ch[u][v]=++cnt;
            u=ch[u][v];
        }
    }
    int dfs(int u) {
        if(!ch[u][0] && !ch[u][1]) return 1;
        else if(!ch[u][0] && ch[u][1]) return dfs(ch[u][1]);
        else if(ch[u][0] && !ch[u][1]) return dfs(ch[u][0]);
        else return max(dfs(ch[u][0]), dfs(ch[u][1])) + 1;
    }
    void sol() {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=1;i<=n;i++)cin>>a[i], add(a[i]); 
        cout<<n-dfs(0)<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin>>T;
        while(T--) {
            sol();
        }
    }
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
