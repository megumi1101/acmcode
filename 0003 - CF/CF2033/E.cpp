#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    priority_queue<int, vector<int>, greater<int>> q1,q2;
    void sol() {
        int n;
        cin>>n;
        vector<int>a(n+5);
        vector<int>pos(n+5);
        int res=0;
        for(int i=1;i<=n;i++)cin>>a[i],pos[a[i]]=i;
        for(int i=1;i<=n;i++) {
            if(a[a[i]]==i)continue;
            else {
                int x = a[i];
                int y = pos[i];
                int z = a[a[i]];
                swap(a[x],a[y]);
                swap(pos[z],pos[i]);
                res++;
            }
        }
        cout<<res<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--) {
            sol();
        }
    }
}
int main() {
    return xbbbz::main(), 0;
}
