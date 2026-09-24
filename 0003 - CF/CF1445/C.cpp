#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 4e6+10;
    int gcd(int a, int b) {
        return b?gcd(b,a%b):a;
    }
    void sol() {
        int p, q;
        cin >> p >> q;
        if(p<q||gcd(p,q)!=q) {
            cout<<p<<"\n";
            return;
        }
        map<int,int> mp;
        for(int i=2;i*i<=q;i++)
            while(q%i==0)  q/=i, mp[i]++;;
        if(q!=1) mp[q]++;
        int ans=1e18;
        for(auto it : mp) {
            int res = 1;
            int cnt = 0;
            int tt = p;
            int x = it.first;
            int y = it.second;
            while(tt%x==0) {
                tt/=x;
                cnt++;
            }
            for(int i=1;i<=cnt-y+1;i++) {
                res*=x;
            }
            ans=min(ans,res);
        }
        cout << p/ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
