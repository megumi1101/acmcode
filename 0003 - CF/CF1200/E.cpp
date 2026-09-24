#include<bits/stdc++.h>
using namespace std;
 
 
namespace xbbbz {
    #define int long long
    const int N = 2e6+10;
    const int inf =1e18;    
    void pre(string s, int *pi) {
        pi[0]=0;
        for(int i=1;i<s.size();i++) {
            int j = pi[i-1];
            while(j>0&&s[i]!=s[j])j=pi[j-1];
            if(s[i]==s[j])j++;
            pi[i]=j;
        }
    }
    int n;
    int pi[N];
    void sol() {
        cin>>n;
        string ans;
        for(int i=1;i<=n;i++) {
            string t;
            cin>>t;
            int x = min(ans.size(), t.size());
            string s = ans.substr(ans.size() - x, x);
            reverse(s.begin(),s.end());
            reverse(t.begin(),t.end());
            string tmp = s+'#'+t;
            pre(tmp,pi);
            reverse(t.begin(),t.end());
            int len = t.size() - pi[tmp.size()-1];
            ans += t.substr(t.size() - len, len);
        }
        cout<<ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin>>T;
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
