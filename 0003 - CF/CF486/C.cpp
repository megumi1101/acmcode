#include <bits/stdc++.h>
using namespace std;

namespace xbbbz {
    void main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;s='0'+s;
        int ans=0;
        for(int i=1;i<=n/2;i++) {
            int j=n-i+1;
            int x = (26+s[i]-s[j])%26;
            ans += min(x,26-x);
            // cout<<ans<<"\n";
        }
        if(k>n/2){
            reverse(s.begin(),s.end());
            k=n-k+1;
            s='0'+s;
        }
        // cout<<s;
        int fg1=0,fg2=0;
        for(int i=k+1;i<=n/2;i++) {
            int j = n-i+1;
            if(s[i]!=s[j])fg1=i;
        }
        for(int i=k-1;i>=1;i--) {
            int j = n-i+1;
            if(s[i]!=s[j])fg2=i;
        }
        if(fg1)fg1=fg1-k;
        if(fg2)fg2=k-fg2;
        ans+=fg1+fg2+min(fg1,fg2);
        cout<<ans;
    }
}
int main() {
    return xbbbz::main(), 0;
}
