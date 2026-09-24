#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int inf = 1e18;
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
        int n;
        cin >> n;
        int c[n + 5];
        memset(c, 0, sizeof(c));
        Per z[n + 5];
        z[0].val = -inf;
        z[0].rk = 0;
        for (int i = 1; i <= n; i++) {
            cin >> z[i].val;
            z[i].id = i;
        }
        sort(z + 1, z + n + 1);
        for (int i = 1; i <= n; i++) {
            if(z[i].val != z[i - 1].val) z[i].rk = z[i - 1].rk + 1;
            else z[i].rk = z[i - 1].rk;
        }
        sort(z + 1, z + n + 1, [&] (Per a, Per b) {
            return a.id < b.id;
        });
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            add(c, n, z[i].rk, 1);
            ans += min(cx(c, z[i].rk - 1), i - cx(c, z[i].rk));
        }
        cout << ans << "\n";
    }
 
    void main() {
        int T;
        cin>>T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
