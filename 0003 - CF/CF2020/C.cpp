#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    int vis[2][30],visb[2][30];
    void sol() {
        int b,c,d;
        cin>>b>>c>>d;
        int ans=0;
        for(int j=1;j<=2e18;j*=2) {
            int x=(b&j)/j;
            int y=(c&j)/j;
            int z=(d&j)/j;
            if(x==0&&y==0&&z==1)ans+=j;
            if(x==1&&y==0&&z==0)ans+=j;
            if(x==1&&y==1&&z==0)ans+=j;
            if((x==0&&y==1&&z==1)||(x==1&&y==0&&z==0)) {
                cout<<"-1\n";
                return;
            }
        }
        cout<<ans<<"\n";
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
