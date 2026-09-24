#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N=3e5+10;
    const int inf = 1e18;
    int n,m;
    int a[N],ans[N],tans;
    vector<int>xx[N];
    struct node {
        int l,r,k,num;
        friend bool operator < (const node &a, const node &b) {
            return a.r < b.r;
        }
    }b[N];
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        mt19937 gen(time(0));
        cin>>n>>m;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        for(int i=1;i<=m;i++) {
            cin>>b[i].l>>b[i].r>>b[i].k;
            b[i].num=i;
        }
        sort(b+1,b+1+m);
        int rr=0;
        for(int i=1;i<=m;i++) {
            while(rr<b[i].r) {
                xx[a[++rr]].push_back(rr);
            }
            int l = b[i].l;
            int r = b[i].r;
            int k = b[i].k;
            int t = (r-l+1)/k+1;
            uniform_int_distribution <> RD(l,r);
            int tans=inf;
            for(int j=1;j<=100;j++) {
                int x = RD(gen);
                if(xx[a[x]].size()>=t&&xx[a[x]][xx[a[x]].size()-t]>=l) {
                    tans=min(tans,a[x]);
                }
            }
            if(tans==inf)ans[b[i].num]=-1;
            else ans[b[i].num]=tans;
        }
        for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
    }    
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
