#include <iostream>
using namespace std;

void dfs(int u, int n, const int* a, int* vis, bool rev) {
    vis[u] = 1;
    for (int v = 0; v < n; ++v) {
        int has = rev ? a[v * n + u] : a[u * n + v];
        if (!vis[v] && has) dfs(v, n, a, vis, rev);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    if (!(cin >> k)) return 0;
    while (k--) {
        int n;
        cin >> n;
        int* a = new int[n * n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                int x; cin >> x;
                a[i * n + j] = x;
            }

        int* vis = new int[n];
        for (int i = 0; i < n; ++i) vis[i] = 0;

        dfs(0, n, a, vis, false);
        bool ok = true;
        for (int i = 0; i < n; ++i) if (!vis[i]) { ok = false; break; }

        if (ok) {
            for (int i = 0; i < n; ++i) vis[i] = 0;
            dfs(0, n, a, vis, true);
            for (int i = 0; i < n; ++i) if (!vis[i]) { ok = false; break; }
        }

        cout << (ok ? "Yes" : "No") << '\n';

        delete[] vis;
        delete[] a;
    }
    return 0;
}
