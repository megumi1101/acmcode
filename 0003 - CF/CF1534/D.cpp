#include <bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    vector<int> ed[2005];
    bool vise[2005][2005];
    bool vis[2005];
    int a[2005], n;
    vector<int>xx;
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        cin>>n;
        cout<<"? 1"<<endl;
        int res1=0,res2=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=2;i<=n;i++) {
            if(a[i]&1)res1++;
            else res2++;
            if(a[i]==1) {
                int nu=1;
                int nv=i;
                if(nu>nv)swap(nu,nv);
                if(!vise[nu][nv]) {
                    ed[nu].push_back(nv);
                    vise[nu][nv] =1;
                }
            }
        }
        if(res1<res2) {
            for(int i=2;i<=n;i++) {
                if(a[i]&1)xx.push_back(i);
            }
        }
        else {
            for(int i=2;i<=n;i++) {
                if(!(a[i]&1))xx.push_back(i);
            }
        }
        for(int u : xx) {
            cout<<"? "<<u<<endl;
            for(int i=1;i<=n;i++)cin>>a[i];
            for(int i=1;i<=n;i++) {
                if(a[i]==1) {
                    int nu=u;
                    int nv=i;
                    if(nu>nv)swap(nu,nv);
                    if(!vise[nu][nv]) {
                        ed[nu].push_back(nv);
                        vise[nu][nv] =1;
                    }
                }
            }    
        }
        cout<<"!\n";
        for(int u=1;u<=n;u++) {
            for(int v : ed[u]) {
                cout<<u<<" "<<v<<"\n";
            }
        }
    }
}
int main() {
    return xbbbz::main(), 0;
}
