#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    int lb(int x) {
        return x & (-x);
    }
 
    void add(int *c, int n, int x, int k) {
        for (; x <= n; x += lb(x)) c[x] += k;
    }
 
    int cx(int *c, int x) {
        int res = 0;
        for (; x; x -= lb(x)) res += c[x];
        return res;
    }
 
    struct Per {
        int val, rk, id, bl;
        friend bool operator < (Per a, Per b) {
            if (a.val == b.val) return a.id < b.id;
            return a.val < b.val;
        }
    };
    void sol() {
        int n, m;
        cin >> n >> m;
        Per z[n * m + 5];
        z[0].val = 0;
        z[0].rk = 0;
        for (int i = 1; i <= n * m; i++) {
            cin >> z[i].val;
            z[i].id = i;
        }
        sort(z + 1, z + n * m + 1);
        for (int i = 1; i <= n * m; i++) {
            if(z[i].val != z[i - 1].val) z[i].rk = z[i - 1].rk + 1;
            else z[i].rk = z[i - 1].rk;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                z[(i - 1) * m + j].bl = i;
            }
        }
        sort(z + 1, z + n * m + 1, [&] (Per a, Per b) {
            if (a.bl == b.bl) return a.id < b.id;
            return a.bl < b.bl;
        });
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int c[n * m + 5];
            memset(c, 0, sizeof (c));
            for (int j = 1; j <= m; j++) {
                int x = (i - 1) * m + j;
                add(c, n * m, z[x].rk, 1);
                ans += cx(c, z[x].rk - 1);
            }
        }
        cout << ans << "\n";
    }
   
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
