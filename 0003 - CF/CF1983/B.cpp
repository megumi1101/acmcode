#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    void sol() {
        int n,m;
        cin>>n>>m;
        string a[n+1];
        string b[n+1];
        for(int i=1;i<=n;i++)cin>>a[i],a[i]=' '+a[i];
        for(int i=1;i<=n;i++)cin>>b[i],b[i]=' '+b[i];
        bool flag=1;
        for(int i=1;i<=n;i++) {
            int suma=0,sumb=0;
            for(int j=1;j<=m;j++) {
                suma+=a[i][j]-'0';
                sumb+=b[i][j]-'0';
            }
            suma%=3;
            sumb%=3;
            if(suma!=sumb)flag=0;
        }
        for(int j=1;j<=m;j++) {
            int suma=0,sumb=0;
            for(int i=1;i<=n;i++) {
                suma+=a[i][j]-'0';
                sumb+=b[i][j]-'0';
            }
            suma%=3;
            sumb%=3;
            if(suma!=sumb)flag=0;
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
