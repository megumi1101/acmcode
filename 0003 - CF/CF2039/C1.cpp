#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int x,m;
        cin>>x>>m;
        vector<int>xx;
        int ans=0;
        for(int i=1;i*i<=x;i++) {
            if(x%i==0) {
                if((x^i)<=m&&(x^i)>=1)ans++, xx.push_back(x^i);
                if(i*i!=x && (x^(x/i))<=m && (x^(x/i))>=1) {
                    ans++, xx.push_back(x^(x/i));
                }
            }
        }
        for(int u : xx) {
            if(u%(u^x)==0)ans--;
        }
        for(int i=1;i<=min(m,3*x);i++) {
            if(i==x)continue;
            if(i%(i^x)==0)ans++;
        }
        cout<<ans<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
