#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    int gcd(int a,int b) {
        return b?gcd(b,a%b):a;
    }
    void sol() {
        int k,n,d=0,x;
        cin>>n>>k;
        for(int i=1;i<=n;i++) {
            cin>>x;
            d=gcd(d,x);
        }
        if(n==1)cout<<k-(x>=k)<<"\n";
        else {
            if(k>(n-1)*(d-1))cout<<k+(n-1)<<"\n";
            else cout<<(k-1)/(d-1)*d+(k-1)%(d-1)+1<<"\n";
        }
    }
    void main() {
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}  
int main() {
    return xbbbz::main(), 0;
}
