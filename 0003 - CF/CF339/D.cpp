#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    const int N = 2e5 + 10;
    int a[N];
    int b[N << 2];
    int sum[N << 2];
    int n, m;
    #define ls (u << 1)
    #define rs ((u << 1) | 1)
    #define mid ((l + r) / 2)
    void pushup(int u, int op) {
        if (op & 1) {
            sum[u] = sum[ls] | sum[rs];
        }
        else {
            sum[u] = sum[ls] ^ sum[rs];
        }
    }

    void build(int u, int l, int r, int op) {
        b[u] = op;
        if (l == r) {
            sum[u] = a[l];
            return;
        }
        build(ls, l, mid, op ^ 1);
        build(rs, mid + 1, r, op ^ 1);
        pushup(u, op);
        // cout << u << " " << sum[u] << "ddd\n";
        
    }

    void update(int u, int l, int r, int k, int x) {
        if (l == r) {
            sum[u] = x;
            return;
        }
        if (k <= mid) update(ls, l, mid, k, x);
        else update(rs, mid + 1, r, k, x);
        pushup(u, b[u]);
        // cout << u << " " << sum[u] << "ddd\n";
    }

    #undef ls
    #undef rs
    #undef mid

    void sol() {
        cin >> n >> m;
        int op0 = n % 2;
        n = pow(2, n);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        build(1, 1, n, op0);
        while (m--) {
            int p, x;
            cin >> p >> x;
            update(1, 1, n, p, x);
            cout << sum[1] << "\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }
    #undef int
}

int main() {
    return Xbbbz :: main(), 0;
}
