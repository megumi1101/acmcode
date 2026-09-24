#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    int gcd(int a,int b) {
        return b?gcd(b,a%b):a;
    }
    const int mod=1e9+7;
    void sol() {
        int n,m,k;
        cin>>n>>m>>k;
        int sum[n+5][m+5];
        int a[n+5][m+5];
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        int ss=0;
        string s[n+5];
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        }
        for(int i=1;i<=n;i++) {
            cin>>s[i];
            s[i]=' '+s[i];
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                sum[i][j]=sum[i][j-1]+s[i][j]-'0';
            }
        }
        for(int j=1;j<=m;j++) {
            for(int i=1;i<=n;i++) {
                sum[i][j]+=sum[i-1][j];
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i][j]=='0')ss+=a[i][j];
                else ss-=a[i][j];
            }
        }
        ss=abs(ss);
        vector<int>xx;
        for(int i=k;i<=n;i++) {
            for(int j=k;j<=m;j++) {
                xx.push_back(abs(2 * (sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k]) - k*k));
            }
        }
        int d=0;
        for(int v : xx) {
            d=gcd(d,v);
        }
        if(d==0) {
            if(ss==0)cout<<"YES\n";
            else cout<<"NO\n";
            return;
        }
        if(ss%d==0) {
            cout<<"YES\n";
        }
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
