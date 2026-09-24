#include <bits/stdc++.h>

using namespace std;

#define int long long


struct Node {
    int ct = 0, sx = 0, sy = 0, prod = 0;
};

int n, d;
Node f[62][2][2];
bool vis[62][2][2];
const int mod = 998244353;


Node dfs(int bit, int ca, int bo) {
    if (bit == 61) {
        if (bo == 0) {
            return{1, 0, 0, 0};
        }
        return {};
    }

    if (vis[bit][ca][bo]) {
        return f[bit][ca][bo];
    }
    vis[bit][ca][bo] = 1;

    int nbit = (n >> bit) & 1;
    int dbit = (d >> bit) & 1;

    Node res;
    for (int x = 0; x < 2; x++) {
        int nca = (x + ca + dbit) >> 1;
        int y = (x + ca + dbit) & 1;
        int nbo = ((nbit - x - bo) < 0);

        auto[ct, sx, sy, prod] = dfs(bit + 1, nca, nbo);
        (res.ct += ct) %= mod;
        (res.sx += (x * ct % mod + sx) % mod) %= mod;
        (res.sy += (y * ct % mod + sy) % mod) %= mod;
        (res.prod += (prod + x * sy % mod + y * sx % mod + x * y % mod * ct % mod) % mod) %= mod;
    }

    return f[bit][ca][bo] = res;
};

void sol() {
    cin >> n >> d;

    memset(vis, 0, sizeof(vis));
    cout << dfs(0, 0, 0).prod << "\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}
/*
5
0 0
1 1
5 7
314 159
114514 1919810
*/