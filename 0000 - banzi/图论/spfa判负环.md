```cpp
// 单源 s 出发检查是否存在“可从 s 到达”的负环
// 多源的话就一开始全都push一下
bool has_negative_cycle(int s) {
    vector<int> dis(n + 1, inf), len(n + 1), inq(n + 1);
    queue<int> q;
    dis[s] = 0, q.push(s), inq[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w, len[v] = len[u] + 1;
                if (len[v] >= n) return true;
                if (!inq[v]) q.push(v), inq[v] = 1;
            }
        }
    }
    return false;
}
