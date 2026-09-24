#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    void sol() {
        int n;
        cin>>n;
        int a[n+5];
        vector<int>xx;
        xx.clear();
        for(int j=1;j<=n;j++) {
            for(int i=1;i<=n;i++) {
                cin>>a[i];
            }
            int res=0;
            for(int i=n;i>=1;i--) {
                if(a[i]==1)res++;
                else break;
            }
            if(res)xx.push_back(res);
        }
        sort(xx.begin(),xx.end());
        int ans=1;
        for(int i=0;i<xx.size();i++) {
            if(xx[i]>=ans)ans++;
            else continue;
        }
        cout<<min(n,ans)<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T;
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
