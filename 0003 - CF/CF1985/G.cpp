#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    const int mod=1e9+7;
    int fap(int a,int b) {
        int res=1;
        while(b) {
            if(b&1)res=res*a%mod;
            a=a*a%mod;b/=2;
        }
        return res;
    }
    void sol() {
        int l,r,k;
        cin>>l>>r>>k;
        int x=9/k;
        if(k>=10){cout<<"0\n";return;}
        cout<<(fap(x+1,r)-fap(x+1,l)+mod) %mod<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
