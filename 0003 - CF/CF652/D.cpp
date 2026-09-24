#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    const int N = 2e5 + 10;
    struct node {
        int l, r,  id;
    }a[N];
    int lb (int x) {
        return x & (-x);
    }
    int n;
    int c[N * 2];
    int ans[N];
    int b[2 * N];
    void add(int p, int x) {
        for (; p <= n * 2; p += lb(p)) {
            c[p] += x;
        }
    }
    int cx (int p) {
        int res = 0;
        for (; p; p -= lb(p)) {
            res += c[p];
        }
        return res;
    }
    void sol() {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].l >> a[i].r;
            a[i].id = i;
            b[i * 2 - 1] = a[i].l;
            b[i * 2] = a[i].r;
        } 
        sort(b + 1, b + 1 + 2 * n);
        for (int i = 1; i <= n; i++) {
            a[i].l = lower_bound(b + 1, b + 1 + 2 * n, a[i].l) - b;
            a[i].r = lower_bound(b + 1, b + 1 + 2 * n, a[i].r) - b;
        }
        sort(a + 1, a + 1 + n, [&] (node i, node j) {
            return i.r < j.r;
        });
        for (int i = 1; i <= n; i++) {
            ans[a[i].id] = i - 1 - cx(a[i].l);
            add(a[i].l, 1);
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << "\n";
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
