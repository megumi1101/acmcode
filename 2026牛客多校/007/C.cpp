#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    vector s(x, vector<string>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> s[i][j];
        }
    }

    int n = x + y + z;
    auto R = [&](int i) { return i; };
    auto G = [&](int j) { return x + j; };
    auto B = [&](int k) { return x + y + k; };

    vector ls(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) ls[i][i] = 0;

    auto add = [&](int u, int v) {
        ls[u][v] = 1;
        ls[v][u] = 0;
    };

    auto addE = [&](int a, int b, int c) {
        add(a, b);
        add(a, c);
        add(b, c);
    };

    auto getmid = [&](int i, int j, int k) {
        char c = s[i][j][k];
        if (c == 'R') return R(i);
        if (c == 'G') return G(j);
        return B(k);
    };

    auto upd = [&](int a, int b, int c, int mid) {
        if (ls[a][b] != 1) swap(a, b);
        if (mid == a) {
            addE(c, a, b);
        } else if (mid == b) {
            addE(a, b, c);
        } else {
            addE(a, c, b);
        }
    };

    add(G(0), B(0));
    for (int i = 0; i < x; i++) {
        upd(G(0), B(0), R(i), getmid(i, 0, 0));
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            upd(R(i), B(0), G(j), getmid(i, j, 0));
        }
    }

    for (int i = 0; i < x; i++) {
        for (int k = 0; k < z; k++) {
            upd(R(i), G(0), B(k), getmid(i, 0, k));
        }
    }

    for (int j = 0; j < y; j++) {
        for (int k = 0; k < z; k++) {
            upd(R(0), G(j), B(k), getmid(0, j, k));
        }
    }

    vector<vector<int>> ed(n);
    vector<int> in(n);
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (ls[u][v] == 1) {
                ed[u].push_back(v);
                in[v]++;
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) q.push(i);
    }

    vector<int> ans(n);
    int now = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans[u] = now++;
        for (auto v : ed[u]) {
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }
    
    for (int i = 0; i < x; i++)
        cout << ans[R(i)] << " ";
    cout << "\n";
    for (int j = 0; j < y; j++)
        cout << ans[G(j)] << " ";
    cout << "\n";
    for (int k = 0; k < z; k++)
        cout << ans[B(k)] << " ";
    cout << "\n";
}