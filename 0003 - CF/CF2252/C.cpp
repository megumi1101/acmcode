#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    vector a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    priority_queue<int> q;
    int ans = m;
    for (int i = n; i >= 1; i--) {
        vector<int> vv;
        for (int j = 1; j <= m; j++) {
            q.push(a[i][j]);
        }

        int res = 0;
        for (int t = 1; t < ans; t++) {
            int u = q.top();
            q.pop();
            vv.push_back(u);
            res += u;
            if (res >= v[i]) {
                ans = t;
                break;
            }
        }
        for (auto x : vv) q.push(x);
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
} 

/*
5
4
0101
3
111
6
100110
6
100010
6
011110
*/