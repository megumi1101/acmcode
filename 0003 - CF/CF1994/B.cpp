#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int inf = 1e18;
    void sol() {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        s=' '+s;
        t=' '+t;
        int x=0;
        for(int i=1;i<=n+1;i++) {
            if(s[i]=='0')x++;
            else {
                break;
            }
        }
        for(int i=1;i<=x;i++) {
            if(s[i]!=t[i]) {
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
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
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
