#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    const int mod = 998244353;
    void sol() {
        int n;
        cin>>n;
        string s[n+5];
        int a[n+5];
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++) {
            cin>>s[i];
            s[i]=' '+s[i];
        }
        for(int i=1;i<=n;i++) {
            int res=0;
            for(int j=i+1;j<=n;j++) {
                if(s[i][j]=='0')res++;
            }
            for(int j=1;j<=n;j++) {
                if(res==0) {
                    if(a[j]==0) {
                        a[j]=i;
                        break;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    if(a[j]==0) {
                        res--;
                    }
                    else {
                        continue;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)  {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin>>T;
        // init();
        while(T--) {
            sol();
        }
    }
    #undef int 
}
 
int main() {
    return xbbbz::main(), 0;
}
