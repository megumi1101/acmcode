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
        int t = pow(p*q, 1.0/3) + 0.5;
        if(t*t*t==p*q && p%t==0 && q%t==0) {
            cout<<"Yes\n";
        }
        else cout<<"No\n";
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
