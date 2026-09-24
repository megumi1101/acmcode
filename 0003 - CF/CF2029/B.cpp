#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int n;
        string s, t;
        cin>>n>>s>>t;
        int res1=0,res0=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='0')res1++;
            else res0++;
        }
        for(int i=0;i<n-1;i++) {
            if((res1==0||res0==0)) {
                cout<<"NO\n";
                return;
            }
            if(t[i]=='0')res0--;
            else res1--;
            
        }
        cout<<"YES\n";
        return;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
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
