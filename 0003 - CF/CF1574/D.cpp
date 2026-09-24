#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    const int N = 2e5 + 10;
    const int inf = 1e18;
 
 
    
    void output (vector<int> a, int n) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
    }
    void sol () {    
        int n; 
        cin >> n;
        map<vector<int>, int> mp;
        vector<int> c(n + 1);
        vector <vector<int>> a(n + 1);  
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
            a[i].resize(c[i] + 1);
            for (int j = 1; j <= c[i]; j++) {
                cin >> a[i][j];
            }   
        }
        int m;
        cin >> m;
        vector<vector<int>> b(m + 1, vector<int>(n + 1));
 
        for (int i = 1; i <= m; i++) {
            int xx = 0;
            for (int j = 1; j <= n; j++) {
                cin >> b[i][j];
            }
            mp[b[i]] = 1;
        }
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = c[i];
        }
        if (!mp[p]) {output(p, n); return;}
        int tpos = 0;
        int tmx = 0;
        for (int i = 1; i <= m; i++) {
            int mn = inf;
            int pos = 0;
            for (int j = 1; j <= n; j++) {
                if (b[i][j] >= 2) {
                    int x = b[i][j];
                    if (a[j][x] - a[j][x - 1] < mn) {
                        mn = a[j][x] - a[j][x - 1];
                    }
                }
            }
            for (int pp = 1; pp <= n; pp++) {
                if (b[i][pp] >= 2) {
                    int x = b[i][pp];
                    if (a[pp][x] - a[pp][x - 1] == mn) {
                        b[i][pp]--;
                        if (!mp[b[i]]) {
                            int sum = 0;
                            for (int j = 1; j <= n; j++) {
                                sum += a[j][b[i][j]];
                            }
                            if (sum > tmx) {
                                tmx = sum;
                                tpos = i;
                            }
                            break;
                        }
                        b[i][pp]++;
                    }
                }
            }
            if (pos) {
                
            }
        }
        output(b[tpos], n); return;
    }
    void main() {
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int 
}
 
int main() {
    return Xbbbz::main(), 0;
}
