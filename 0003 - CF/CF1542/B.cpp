#include <bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int n,a,b;
        cin>>n>>a>>b;
        for(int i=1;i<=n;i*=a) {
            if((n-i)%b==0) {
                cout<<"Yes\n";
                return;
            }
            if(a==1)break;
        }
        cout<<"No\n";
    }
    void main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
