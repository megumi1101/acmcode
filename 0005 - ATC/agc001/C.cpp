// AtCoder user: lnxbb
// Contest: agc001
// Problem: agc001_c
// Submission: https://atcoder.jp/contests/agc001/submissions/75131143
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long
void sol() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ed(n + 1);
    vector<pair<int, int>> edges; // 存边，用于 K 为奇数时枚举
    
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
        edges.push_back({x, y});
    }

    int max_keep = 0;

    // DFS 辅助函数：计算 u 的连通块中，距离 <= limit 的节点数
    // ignore_node 用于在奇数情况时断开边
    auto get_cnt = [&](auto&& self, int u, int p, int depth, int limit, int ignore_node) -> int {
        if (depth > limit) return 0;
        int cnt = 1;
        for (int v : ed[u]) {
            if (v != p && v != ignore_node) {
                cnt += self(self, v, u, depth + 1, limit, ignore_node);
            }
        }
        return cnt;
    };

    if (k % 2 == 0) {
        // K 是偶数：枚举点作为中心
        int limit = k / 2;
        for (int i = 1; i <= n; i++) {
            max_keep = max(max_keep, get_cnt(get_cnt, i, 0, 0, limit, 0));
        }
    } else {
        // K 是奇数：枚举边作为中心
        int limit = (k - 1) / 2;
        for (auto [u, v] : edges) {
            int cnt_u = get_cnt(get_cnt, u, 0, 0, limit, v); // u这边，不走向v
            int cnt_v = get_cnt(get_cnt, v, 0, 0, limit, u); // v这边，不走向u
            max_keep = max(max_keep, cnt_u + cnt_v);
        }
    }

    cout << n - max_keep << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) sol();
}