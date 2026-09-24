#include<bits/stdc++.h>
using namespace std;
 
 
namespace xbbbz {
    #define int long long
    const int N = 2e6+10;
    const int inf =1e18;    
    void mlc(string s, int *d) {
        d[1] = 1;
        for(int l,r=1,i=2;i<s.size();i++) {
            d[i] = 0;
            if(i<=r)d[i] = min(d[r-i+l],r-i+1);
            while(s[i-d[i]]==s[i+d[i]])d[i]++;
            if(i+d[i]-1 > r) r=i+d[i]-1, l=i-d[i]+1;
        }
    }
    int n;
    int d[N];
    void sol() {
        string tmp;
        cin>>tmp;
        int n = tmp.size();
        tmp = " "+tmp;
        int res=0;
        for(int i=1;i<=n/2;i++) {
            if(tmp[i] == tmp[n-i+1])res++;
            else break;
        }
        string tmp2;
        for(int i=1;i<=n-2*res;i++) {
            tmp2+=tmp[i+res];
        }
        string s ="$#";
        for(int i=0;i<tmp2.size();i++) {
            s+=tmp2[i]; s+='#';
        }
        mlc(s,d);
        int mx=1,pos=0;
        for(int i=2;i<s.size()-1;i++) {
            if(i-d[i]+1==1||i+d[i]-1==s.size()-1) {
                if(d[i]>mx) {
                    mx = d[i];
                    pos = i;
                }
            }
        }
        string ans;
        if(pos-d[pos]+1==1) {
            ans = tmp.substr(1,res+mx-1)+tmp.substr(n-res+1,res); 
        }
        else {
            ans = tmp.substr(1,res)+tmp.substr(n-res+1-mx+1,res+mx-1);
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
    #undef int 
}
 
int main() {
    return xbbbz::main(), 0;
}
