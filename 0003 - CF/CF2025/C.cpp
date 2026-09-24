#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    void sol() {
        int n,m;
        cin>>n>>m;
        vector<int>a(n+5);
        deque<int>q;
        while(!q.empty())q.pop_back();
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a.begin()+1,a.begin()+1+n);
        int ans=0;
        for(int i=1;i<=n;i++) {
            if(!q.empty()&&a[i]>q.back()+1) {
                while(!q.empty()) q.pop_back();
            }
            if(!q.empty()) {
                if(a[i]-q.front()>=m)q.pop_front();
            }
            q.push_back(a[i]);
            ans=max(ans,(int)q.size());
        }
        cout<<ans<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--) {
            sol();
        }
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
