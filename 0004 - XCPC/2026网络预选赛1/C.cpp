#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n, m;
    cin >> n >> m;

    
    priority_queue<int, vector<int>, greater<>> q;

    vector<vector<int>> ed(n + 1);
    vector<int> in(n + 1);
    while (m--) {
        int l, r;
        cin >> l >> r;
        vector<int> p;
        for (int i = l; i <= r; i++) {
            int x;
            cin >> x;
            p.push_back(x);
        }

        for (int i = 0; i + 1 < p.size(); i++) {
            ed[p[i]].push_back(p[i + 1]);
            in[p[i + 1]]++;
        }
    }


    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(i);
    }

    vector<int> ans(n + 1);
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        ans[u] = ++now;
        for (auto v : ed[u]) {
            --in[v];
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }

    if (now == n) {
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}

/*
4
4 1
2 4 3 2 4
3 2
1 3 1 2 3
1 3 3 2 1
5 2
2 4 4 2 3
2 4 4 2 3
4 2
2 2 2
1 4 2 1 4 3
*/