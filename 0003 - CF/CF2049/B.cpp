#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int sump=0,sums=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='p') sump++;
            if(s[i]=='s') {
                if(sump) {
                    cout<<"NO\n";
                    return;
                }
                sums++;
            }
        }
        if(sums>=2&&sump>=2) {
            cout<<"NO\n";
            return;
        }
        if(sums==1&&sump==1) {
            if(s[0]=='s'||s[n-1]=='p')cout<<"YES\n";
            else cout<<"NO\n";
            return;
        }
        if(sums==1&&sump>1) {
            if(s[0]=='s')cout<<"YES\n";
            else cout<<"NO\n";
            return;
        }
        if(sump==1&&sums>1) {
            if(s[s.size()-1]=='p')cout<<"YES\n";
            else cout<<"NO\n";
            return;
        }
        cout<<"YES\n";
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
