#include <bits/stdc++.h>

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<vector<int>> ed(2 * n + 1);
    for (int i = 1; i < 2 * n; i++) {
        int u, v;
        cin >> u >> v;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    vector<int> p;
    vector<int> col(2 * n + 1, -1);
    array<int, 2> sum{0, 0};

    auto dfs = [&](this auto &&dfs, int u, int fat, int dep) -> void {
        if (ed[u].size() == 1) {
            p.push_back(u);
        } else {
            sum[dep & 1]++;
            col[u] = dep & 1;
        }
        for (auto v : ed[u]) if (v != fat) {
            dfs(v, u, dep + 1);
        }
    };
    dfs(1, 0, 0);

    for (int i = 0; i < p.size(); i++) {
        if (i < (n - sum[0])) col[p[i]] = 0;
        else col[p[i]] = 1;
    }
    
    for (int i = 1; i <= 2 * n; i++) cout << col[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
    
    
}

/*
1
4
1 2
2 3
3 4
4 5
5 6
6 7
7 8

4
3
1 2
2 3
2 4
4 5
4 6
3
1 2
1 3
1 4
1 5
1 6
4
1 2
2 3
3 4
4 5
5 6
6 7
7 8
5
1 2
1 4
4 3
4 5
5 6
5 8
8 7
8 9
9 10
*/