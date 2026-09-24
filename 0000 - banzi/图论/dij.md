```cpp
auto dij = [&] (int s) -> void {
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(dis[s], s);
    while (!q.empty()) {
        auto[cost, u] = q.top();
        q.pop();
        if (dis[u] == cost) {
            for (auto[v, w] : ed[u]) {
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    q.emplace(dis[v], v);
                }
            }
        }
    }
};
dij(1);
```