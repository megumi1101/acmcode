2-SAT 处理布尔变量，每条约束形如 `(x=a) 或 (y=b)`，其中 `a、b` 为 `0` 或 `1`。模板返回一组可行赋值，无解时返回空数组。

使用 C++17，变量从 `1` 编号。先复制 [tarjan.md](tarjan.md) 中的 `scc()` 函数，再使用这里的 `SAT`。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
```

**拆点与建边**

| 条件 | 图中编号 |
| --- | --- |
| `x=0` | `2*x-1` |
| `x=1` | `2*x` |

条件 `x=a` 的编号是 `2*x-1+a`，相反条件的编号是 `2*x-a`。对 `(x=a) 或 (y=b)`，加入：

```text
(x=!a) → (y=b)
(y=!b) → (x=a)
```

只保留一个建边接口 `add(x,a,y,b)`，其余约束直接转成“或”，避免为每种约束再写一层函数：

| 条件 | 写法 |
| --- | --- |
| `(x=a)`、`(y=b)` 至少一个成立 | `sat.add(x,a,y,b)` |
| `x=a ⇒ y=b` | `sat.add(x,!a,y,b)` |
| 不能同时 `x=a`、`y=b` | `sat.add(x,!a,y,!b)` |
| 固定 `x=a` | `sat.add(x,a,x,a)` |
| `x=y` | `sat.add(x,0,y,1); sat.add(x,1,y,0);` |
| `x!=y`，即恰好选一个 | `sat.add(x,0,y,0); sat.add(x,1,y,1);` |

每次 `add` 都会加入一对互为逆否的蕴含边，不要只手动加入其中一条。这一转换可参看 [CP-Algorithms 的 2-SAT 说明](https://cp-algorithms.com/graph/2SAT.html)。

```cpp
struct SAT {
    int n;
    vector<vector<int>> ed;
    SAT(int n) : n(n), ed(2 * n + 1) {}

    int var() {                           // 新增一个辅助变量
        ed.resize(2 * ++n + 1);
        return n;
    }
    void add(int x, int a, int y, int b) {
        ed[2 * x - a].push_back(2 * y - 1 + b);
        ed[2 * y - b].push_back(2 * x - 1 + a);
    }
    vector<int> solve() {
        auto bel = scc(ed);
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (bel[2 * i - 1] == bel[2 * i]) return {};
            ans[i] = bel[2 * i] < bel[2 * i - 1];
        }
        return ans;
    }
};
```

**判断无解与恢复方案**

`x=0` 和 `x=1` 如果在同一个 SCC 中，就会互相推出，无论选择哪个都矛盾，因此无解。

本模板的 `scc()` 按弹栈顺序编号，缩点 DAG 上越靠近终点的分量编号越小。每个变量选择编号更小的那个条件即可，所以写 `ans[i] = bel[2*i] < bel[2*i-1]`。

为什么不会违反蕴含？设有边 `A → B`，却选了 `A`、没有选 `B`，则有：

```text
bel[A] < bel[!A] <= bel[!B] < bel[B] <= bel[A]
```

两个 `<=` 分别来自逆否边 `!B → !A` 和原边 `A → B`，矛盾。比较方向依赖这里的 SCC 编号方式，换 SCC 模板时需要确认。

```cpp
signed main() {
    SAT sat(3);
    sat.add(1, 1, 2, 1);                 // x1、x2 至少选一个
    sat.add(1, 0, 2, 0);                 // x1、x2 不能同时选
    sat.add(2, 0, 3, 1);                 // 选 x2 必须选 x3
    sat.add(1, 0, 1, 0);                 // 固定 x1=0
    auto ans = sat.solve();
    if (ans.empty()) cout << "IMPOSSIBLE\n";
    else for (int i = 1; i <= 3; ++i) cout << ans[i] << ' '; // 0 1 1
}
```

两个变量“至多选一个”只需 `sat.add(x,0,y,0)`；“恰好选一个”还要 `sat.add(x,1,y,1)`。

一组 `k` 个条件至多一个成立，可以用 [前缀优化](前缀优化建图.md) 把两两冲突的 `O(k²)` 建边降到 `O(k)`。三个或更多条件的“至少一个成立”一般不能直接写成 2-SAT 子句。

设共有 `N` 个变量（包括辅助变量）、`M` 个子句，时间和空间复杂度都是 `O(N + M)`。可以追加约束后再次调用 `solve()`，每次重新跑 SCC。`ans[1..n]` 是任意可行解，不保证字典序最小；若有辅助变量，只输出原变量。
