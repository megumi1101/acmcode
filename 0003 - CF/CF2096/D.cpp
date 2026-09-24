#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    vector<int> tmp[2];
    int vis[N][2];
    void sol() {
        int n;
        cin >> n;
 
        map<int, int> xx, xy;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            xx[x]++;
            xy[x + y]++;
        }
 
        int s;
        for (auto [c, cnt]: xx) {
            if (cnt % 2 == 1) {
                s = c;
                break;
            }
        }
 
        int t;
        for (auto [c, cnt]: xy) {
            if (cnt % 2 == 1) {
                t = c - s;
                break;
            }
        }
 
        cout << s << " " << t << '\n';
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) sol();
    }   
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}
/*
1 3
5 4 3
*/
