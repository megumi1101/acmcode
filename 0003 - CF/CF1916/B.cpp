#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    int gcd(int a,int b){return b?gcd(b,a%b):a;}
    void sol() {
        int a,b;
        cin>>a>>b;
        if(b%a==0)cout<<b/a*b<<"\n";
        else cout<<a*b/gcd(a,b)<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        int T=1;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
