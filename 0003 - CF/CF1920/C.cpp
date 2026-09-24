#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    #define int long long
    int pr[200005],pvis[200005];
    vector<int>a(200005);
    int n;
    int gcd(int a,int b) {
        return b?gcd(b,a%b):a;
    }
    bool jud(int x) {
        int  ngcd = 0;
        for(int i=1;i<=x;i++) {
            for(int j=1;j<=n/x;j++) {
                if(j==1)ngcd=gcd(ngcd,0);
                else {
                    ngcd=gcd(abs(a[(j-2)*x+i]-a[(j-1)*x+i]),ngcd);
                }
            }
        }
        if(ngcd==1)return 0;
        else return 1;
    }
    void sol() {
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=sqrt(n);i++) {
            if(n%i==0) {
                ans+=jud(i);
                if(i*i!=n)ans+=jud(n/i);
            }
        }
        cout<<ans<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int T;
        cin >> T;
        while(T--) {
            sol();
        }
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
