#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
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

        for (int out = 0; out < n; ++out) {
            int pick = -1;

            for (int v = 0; v < n; ++v) {
                if (vis[v]) continue;
                int indeg = 0;
                for (int u = 0; u < n; ++u) indeg += a[u * n + v];
                if (indeg == 0) { pick = v; break; } 
            }

            if (pick == -1) {
                for (int v = 0; v < n; ++v) if (!vis[v]) { pick = v; break; }
            }

            cout << pick << ' ';
            vis[pick] = 1;

            for (int j = 0; j < n; ++j) a[pick * n + j] = 0;
        }
        cout << '\n';

        delete[] vis;
        delete[] a;
    }
    return 0;
}
