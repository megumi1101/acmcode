## dij
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
## SPFA判定负环
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
```

## 差分约束

最短路 所满足的 三角形不等式
$dis[v] \le w(u, v) + dis[u]$

相反，给出若干条三角形不等式的限制，求能否找到一组满足条件的解，就是经典的 差分约束 问题

如果若干点的值有上界，求最短路时
会返回满足条件的最大值 
* $x_v \le x_u + w$ → **边** $u \to v$（权 $w$）
* $x_v - x_u = w$ → 同时加：
  $u \to v$（$w$）与 $v \to u$（$-w$）

最长路同理
如果若干点的值有下界,求最长路时
返回满足条件的最小值
* $x_v \ge x_u + w$ → **边** $u \to v$（权 $w$）
* $x_v - x_u = w$ → 同时加：
  $u \to v$（$w$）与 $v \to u$（$-w$）
  
固定值
可以新建个值为 $0$ 的源点，然后与固定值按 $x_v - 0 = w$ 的方式连边

出现负环或正环就是无解