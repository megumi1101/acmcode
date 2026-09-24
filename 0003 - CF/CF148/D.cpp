#include<bits/stdc++.h>
using namespace std;


namespace xbbbz {
    #define int long long
    typedef long double db ;
    long double f[1005][1005];
    long double g[1005][1005];
    void sol() {
        int w, b;
        cin>>w>>b;
        for(int i=1;i<=1000;i++) {
            f[i][0] = 1.0;
            g[i][0] = 1.0;
            g[0][i] = 1.0;
        }
        for(int i=1;i<=w;i++) {
            for(int j=1;j<=b;j++) {
                f[i][j] = (db)i/(db)(i+j) + db((db)j/(db)(i+j)) * (1.0 - g[i][j-1]);
                g[i][j] = db((db)i/(db)(i+j)) + db((db)j/(db)(i+j)) * (db((db)i/(db)(i+j-1)) * (1.0 - f[i-1][j-1]) + db((db)(j-1)/(db)(i+j-1)) * (1.0 - f[i][j-2]));
            }
        }
        cout<<fixed<<setprecision(10);
        cout<<f[w][b];
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
