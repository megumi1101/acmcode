#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    void sol() {
        int n;
        cin>>n;
        string s;
        cin>>s;
        s=' '+s;
        queue<int>q;
        int ans=0;
        for(int i=1;i<=n;i++)ans+=i;
        for(int i=n;i>=1;i--) {
            if(s[i]=='1') {
                q.push(i);
            }
            else {
                if(!q.empty()) {
                    int x = q.front();
                    ans-=x;
                    q.pop();
                }
            }
        }
        if(q.size()>=2) {
            int up = q.size()/2;
            for(int i=1;i<=up;i++) {
                int x = q.front();
                ans-=x;
                q.pop();
            }
        }
        while(!q.empty())q.pop();
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
