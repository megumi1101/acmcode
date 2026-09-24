#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int inf = 1e18;
    const int N = 1e5+10;
    const int mod = 998244353;
    int a[N], f[2][205][3], sum[2][205][3], dsum[2][205][3];
    void sol() {
        int n;
        cin>>n;
        int op = 0;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            op^=1;
            for(int j=1;j<=200;j++) {
                for(int k=0;k<3;k++)
                    f[op][j][k] = 0;   
            }
            if(a[i]!=-1) {
                if(i==1) {
                    f[op][a[i]][0] = 1;
                }
                else {
                    f[op][a[i]][0] = sum[op^1][a[i]-1][0] + sum[op^1][a[i]-1][1] + sum[op^1][a[i]-1][2];
                    f[op][a[i]][1] = f[op^1][a[i]][0] + f[op^1][a[i]][1] + f[op^1][a[i]][2];
                    f[op][a[i]][2] = dsum[op^1][a[i]+1][1] + dsum[op^1][a[i]+1][2];
                    f[op][a[i]][0] %=mod; f[op][a[i]][1] %=mod; f[op][a[i]][2] %=mod;
                }
            }
            else {
                if(i==1) {
                    for(int j=1;j<=200;j++) {
                        f[op][j][0] = 1;
                    }
                }
                else {
                    for(int j=1;j<=200;j++) {
                        f[op][j][0] = sum[op^1][j-1][0] + sum[op^1][j-1][1] + sum[op^1][j-1][2];
                        f[op][j][1] = f[op^1][j][0] + f[op^1][j][1] + f[op^1][j][2];
                        f[op][j][2] = dsum[op^1][j+1][1] + dsum[op^1][j+1][2];
                        f[op][j][0] %=mod; f[op][j][1] %=mod; f[op][j][2] %=mod;
                    }
                }
            }
            for(int j=1;j<=200;j++) {
                for(int k=0;k<3;k++)
                    sum[op][j][k] = (sum[op][j-1][k] + f[op][j][k]) %mod;   
            }
            for(int j=200;j>=1;j--) {
                for(int k=0;k<3;k++)
                    dsum[op][j][k] = (dsum[op][j+1][k] + f[op][j][k]) %mod;   
            }
        }
        cout<< (sum[op][200][1] + sum[op][200][2]) %mod;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin>>T;
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
