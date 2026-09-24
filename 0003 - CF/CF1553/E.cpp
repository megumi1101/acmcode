#include <bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    void sol() {
        int n,m;
        cin>>n>>m;
        int a[n+5],cnt[n+5],b[n+5],c[n+5],pos[n+5];
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            if(a[i]==n)a[i]=0;
            cnt[(i-a[i]+n)%n]++;
        }
        vector<int>xx,ans;
        for(int i=0;i<n;i++) {
            if(cnt[i]>=n-2*m) {
                xx.push_back(i);
            }
        }
        for(int v : xx) {
            int res=0;
            for(int i=1;i<=n;i++) {
                c[i]=a[i];
                pos[a[i]]=i;
                b[i]=(i-v+n)%n;
            }
            for(int i=1;i<=n;i++) {
                if(b[i]!=c[i]) {
                    int x = pos[b[i]];
                    swap(pos[c[i]],pos[c[x]]);
                    swap(c[i],c[x]);
                    res++;
                }
            }
            if(res<=m)ans.push_back(v);
        }
        cout<<ans.size();
        for(int v : ans)cout<<" "<<v;
        cout<<"\n";
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
