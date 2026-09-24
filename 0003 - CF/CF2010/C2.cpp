#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    const int N = 4e5+10;
    const int mod = 1e9+21;
    int p10[N],n, has[N];
    string s;
    void hass () {
        int cnt=0;
        for(int i=s.size()-1;i>=0;i--) {
            ++cnt;
            has[cnt]=(p10[cnt-1]*(int)s[i]+has[cnt-1])%mod;
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        cin>>s;
        n = s.size();
        p10[0]=1;
        for(int i=1;i<=(int)4e5;i++) {
            p10[i]=p10[i-1]*131%mod;
        }
        hass();
        int res=0;
        for(int i=1;i<=(n-1)/2;i++) {
            if(((has[i]*p10[i]+has[i])%mod==has[i*2])&&((has[n]-has[2*i]+mod)%mod==(has[n-i]-has[i]+mod)%mod*p10[i]%mod)) {
                res=i;
                break;
            }
        }
        if(res==0)cout<<"NO\n";
        else {
            cout<<"YES\n";
            for(int i=1;i<=res;i++)s.pop_back();
            cout<<s;
        }
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}//
