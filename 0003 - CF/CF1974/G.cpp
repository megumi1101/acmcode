#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    void sol() {
        int n,x;
        cin>>n>>x;
        priority_queue<int> q;
        int now = 0;
        int ans = 0;
        for(int i=1;i<=n;i++) {
            int c;
            cin>>c;
            if(now>=c) {
                ans++;
                now-=c;
                q.push(c);
            }
            else {
                if(!q.empty()&&q.top()>c) {
                    now+=q.top()-c;
                    q.pop();
                    q.push(c);
                }
            }
            now+=x;
        }
        cout<<ans<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin>>T;
        // init();
        while(T--) {
            sol();
        }
    } 
}
 
int main() {
    return xbbbz::main(), 0;
}
