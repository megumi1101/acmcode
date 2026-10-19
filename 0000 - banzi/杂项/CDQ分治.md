# CDQ 分治

CDQ 把一个有方向的贡献关系 `j → i` 分成三部分：两端都在左半、两端都在右半、左半贡献给右半。前两部分递归处理，当前层只计算跨过中点的贡献。常用来解决三维偏序、带时间的二维数点，以及有先后依赖的 DP 转移。

参考：[OI Wiki CDQ 分治](https://oi-wiki.org/misc/cdq-divide/)（[CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/) / [SATA](https://github.com/zTrix/sata)）。

数据下标从 `1` 开始，分治区间为闭区间。树状数组沿用 [树状数组.md](../数据结构/树状数组.md) 的 `Fenwick / add / sum / getsum` 接口。

## 1 分治的是什么

假设贡献只允许从序列中较早的点流向较晚的点，分治 `[l,r]`，中点为 `mid`。

| 贡献关系 | 处理方式 |
| --- | --- |
| `l ≤ j < i ≤ mid` | 递归左半 |
| `mid < j < i ≤ r` | 递归右半 |
| `l ≤ j ≤ mid < i ≤ r` | 当前层统计左半对右半的贡献 |

每个合法点对都在递归树中有唯一一个节点，使两端第一次分居左右儿子。因此只要当前层没有重复统计，整棵递归树就不会漏算、重算。

CDQ 只负责分配贡献关系。真正加速的是跨区间处理：原来需要枚举左右点对，现在通过排序、扫描线、树状数组等批量计算。

| 问题 | 分治维度 | 当前层需要处理的事情 |
| --- | --- | --- |
| 三维偏序 | 按第一维排序后的顺序 | 扫第二维，树状数组统计第三维 |
| 动态二维数点 | 操作时间 | 左半修改对右半查询的二维贡献 |
| DP 转移 | 状态下标或拓扑顺序 | 左半已经算好的 DP 更新右半 |

若长度为 `s` 的区间可以在 `O(s log n)` 内完成跨区间处理，则总时间为 `O(n log² n)`。三维偏序中若第三维压缩后大小为 `V`，更细的界为 `O(n log n log V + n log n)`。

## 2 三维偏序

对每个点 `i`，统计满足下面条件的其他点数：

\[
a_j\le a_i,\quad b_j\le b_i,\quad c_j\le c_i,\quad j\ne i.
\]

### 2.1 三个维度分别怎么处理

1. 按 `(a,b,c)` 字典序排序。之后跨区间时，左半的 `a` 一定不大于右半的 `a`。
2. 递归结束时，使每个子区间按 `b` 有序。合并时依次扫描右半点，把左半中所有 `b ≤ 当前 b` 的点加入树状数组。
3. 树状数组下标是离散化后的 `c`，查询 `sum(c)`，得到第三维也满足条件的点数。

**排序后下标更小，并不等价于第一维更小。** 这里成立的是“跨区间的左点第一维不大于右点”。对于第一维相同的合法支配关系，字典序会让被统计的点排在前面；完全相同的点需要另行合并。

递归内部虽然会把区间改成按 `b` 排序，但不会让点越过当前区间的边界。进入父层时，左右两组仍分别属于原来按第一维划分的两半，所以第一维条件仍成立。分组依靠区间归属，不能在合并后把当前下标解释成原来的排名。

### 2.2 完全相同的点

如果有 `cnt` 个完全相同的点，它们两两都满足条件。直接按下标分治只能统计其中一个方向，所以先合成一个带权点：

```text
cnt = 这一组原来有多少个点
ans = 其他组对这一组中任意一个点的贡献
```

树状数组加入 `cnt`，不能只加入 `1`。这一组中每个原始点的答案都是：

\[
ans+cnt-1.
\]

如果题目要求答案分布，则执行 `res[ans+cnt-1] += cnt`。

### 2.3 完整模板

对应 [洛谷 P3810 三维偏序](https://www.luogu.com.cn/problem/P3810)：输入 `n k` 和 `n` 个三元组；输出答案为 `0,1,...,n-1` 的点各有多少个。输入中的 `k` 是第三维上界，代码另做离散化。

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using ll = long long;
#define int long long

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n + 5, T{});
    }

    void add(int x, const T &v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }

    T getsum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

struct node {
    int a, b, c;
    int cnt = 1, ans = 0;
};

void sol() {
    int n, k;
    cin >> n >> k;
    vector<node> a(n + 5), b(n + 5), tmp(n + 5);
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b >> a[i].c;
        v.push_back(a[i].c);
    }
    sort(a.begin() + 1, a.begin() + n + 1, [&](const node &x, const node &y) {
        return tie(x.a, x.b, x.c) < tie(y.a, y.b, y.c);
    });
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (m && tie(a[i].a, a[i].b, a[i].c) == tie(b[m].a, b[m].b, b[m].c)) {
            b[m].cnt++;
        } else {
            b[++m] = a[i];
        }
    }
    for (int i = 1; i <= m; i++) {
        b[i].c = lower_bound(v.begin(), v.end(), b[i].c) - v.begin() + 1;
    }

    Fenwick<int> tr(v.size());
    auto cdq = [&](auto &&self, int l, int r) -> void {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        self(self, l, mid);
        self(self, mid + 1, r);

        int i = l, j = mid + 1, p = l;
        while (j <= r) {
            while (i <= mid && b[i].b <= b[j].b) {
                tr.add(b[i].c, b[i].cnt);
                tmp[p++] = b[i++];
            }
            b[j].ans += tr.sum(b[j].c);
            tmp[p++] = b[j++];
        }
        // 只撤销本层实际加入的左点，必须在覆盖 b 之前完成。
        for (int t = l; t < i; t++) tr.add(b[t].c, -b[t].cnt);
        while (i <= mid) tmp[p++] = b[i++];
        for (int t = l; t <= r; t++) b[t] = tmp[t];
    };
    cdq(cdq, 1, m);

    vector<int> ans(n + 5);
    for (int i = 1; i <= m; i++) {
        ans[b[i].ans + b[i].cnt - 1] += b[i].cnt;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) sol();
}
```

时间 `O(n log² n)`，空间 `O(n)`。若要按原点编号输出答案，在去重时保存每组的原编号，最后把 `ans+cnt-1` 分配回去。

### 2.4 检查样例

```text
输入
5 3
1 1 1
1 1 1
1 2 1
2 1 2
2 2 2

输出
0
2
2
0
1
```

前两个重复点各被另一个重复点贡献一次，答案为 `1`；第三、第四个点答案为 `2`；最后一个点答案为 `4`。

## 3 CDQ 优化 DP

例如求二维严格上升子序列：

\[
f_i=1+\max\{f_j\mid j<i,\ a_j<a_i,\ b_j<b_i\},
\]

不存在合法 `j` 时，最大值按 `0` 处理。这里的顺序必须是：

```text
算完左半 → 左半更新右半 → 算右半
```

左半更新右半时，左半的 `f` 已经完整；右半继续递归时，也已经收到所有来自左半的贡献。如果先算右半，右半内部可能用尚未收全贡献的状态继续转移。

下面保留原下标顺序，只临时排序下标数组。`a[i][0]、a[i][1]` 是第 `i` 个元素的两个属性，`a[0]` 占位；返回的 `f` 同样从 `1` 开始。复制上面文件头，再使用这一块即可。

```cpp
struct FenwickMax {
    int n;
    vector<int> a;

    FenwickMax(int n) : n(n), a(n + 5) {}

    void add(int x, int v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] = max(a[i], v);
        }
    }

    int sum(int x) {
        int ans = 0;
        for (int i = x; i; i -= i & -i) ans = max(ans, a[i]);
        return ans;
    }

    void clear(int x) {
        for (int i = x; i <= n; i += i & -i) a[i] = 0;
    }
};

vector<int> cdq_dp(const vector<array<int, 2>> &a) {
    int n = (int)a.size() - 1;
    vector<int> v, b(n + 5), f(n + 1, 1);
    f[0] = 0;
    for (int i = 1; i <= n; i++) v.push_back(a[i][1]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++) {
        b[i] = lower_bound(v.begin(), v.end(), a[i][1]) - v.begin() + 1;
    }

    FenwickMax tr(v.size());
    auto cdq = [&](auto &&self, int l, int r) -> void {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        self(self, l, mid);

        vector<int> x, y;
        for (int i = l; i <= mid; i++) x.push_back(i);
        for (int i = mid + 1; i <= r; i++) y.push_back(i);
        auto cmp = [&](int i, int j) {
            return a[i][0] < a[j][0];
        };
        sort(x.begin(), x.end(), cmp);
        sort(y.begin(), y.end(), cmp);

        int p = 0;
        for (auto i : y) {
            while (p < (int)x.size() && a[x[p]][0] < a[i][0]) {
                tr.add(b[x[p]], f[x[p]]);
                p++;
            }
            f[i] = max(f[i], tr.sum(b[i] - 1) + 1);
        }
        for (int i = 0; i < p; i++) tr.clear(b[x[i]]);

        self(self, mid + 1, r);
    };
    cdq(cdq, 1, n);
    return f;
}
```

时间 `O(n log² n)`，空间 `O(n)`。树状数组维护的是最大值，无法通过“加相反数”撤销。这里保证每层进入时树为空，查询全部结束后才把所有碰过的节点重置为 `0`；`0` 只适用于本题非负长度的语义。若维护可能为负的收益，单位元和初始化应按转移重新设置。

严格小于对应两处：第一维插入条件为 `<`，第二维查询为 `sum(b[i]-1)`。不能只改其中一个。

## 4 把动态问题变成静态贡献

二维点加、矩形求和可以将时间视为第三维：

\[
t_{修改}<t_{询问},\quad x_{修改}\le X,\quad y_{修改}\le Y.
\]

先把所有操作按时间放入序列，CDQ 按操作序列分治。当前层只处理左半的点加对右半前缀查询的贡献，再按 `x` 扫描，用树状数组处理 `y`。每一层的修改都是独立加法，递归两边以后再统计跨区间贡献即可。

### 4.1 矩形查询拆成四个前缀

令 `S(X,Y)` 为所有 `x≤X、y≤Y` 的点权和，则：

\[
\operatorname{sum}([x_1,x_2]\times[y_1,y_2])
=S(x_2,y_2)-S(x_1-1,y_2)-S(x_2,y_1-1)+S(x_1-1,y_1-1).
\]

一次查询展开成四个相邻事件，携带相同的答案编号和各自的正负号。一次修改仍然是一个事件。离散化时：

- 只收集修改坐标，则查询 `Y` 应使用 `upper_bound` 得到有多少个修改坐标 `≤Y`，结果可能为 `0`。
- 同时收集修改和查询坐标，则都能按排序后的坐标压缩，查询仍取前缀和。

坐标是整数时才能这样直接写 `x1-1、y1-1`，且要保证不会溢出。实数坐标应通过严格小于的边界或压缩排名处理。

### 4.2 赋值要先转成可加的事件

如果原操作是把点权从 `old` 改成 `v`，读入时按时间维护旧值，把操作转成点加 `v-old`。初始非零点也应作为最早的修改事件加入。

**不能把所有赋值都当成独立的加法。** 若操作依赖之前的状态，必须先完成这种转化，或另外设计有时间依赖的分治过程。

### 4.3 矩形加和矩形求和

OI Wiki 还讨论了矩形加、矩形求和。对从 `1` 开始的整数网格，先做二维差分，一次矩形加拆成四个角点加。设差分为 `d[i][j]`，原数组的二维前缀和为：

\[
S(X,Y)=\sum_{i\le X,j\le Y}d[i][j](X-i+1)(Y-j+1).
\]

展开后同时维护四类贡献 `d、i*d、j*d、i*j*d`，就能计算：

\[
S(X,Y)=(X+1)(Y+1)D-(Y+1)D_x-(X+1)D_y+D_{xy}.
\]

再按时间做 CDQ、按空间做扫描线即可。乘法使用原坐标，离散化编号只作为树状数组下标；四类贡献及最终乘积都要检查溢出范围。

## 5 和整体二分的区别

| 方法 | 递归划分依据 | 当前层的任务 |
| --- | --- | --- |
| CDQ 分治 | 下标、时间或某一维排序后的顺序 | 把左半对右半的贡献计入答案 |
| [整体二分](整体二分.md) | 答案的值域 | 判定每个询问的答案在值域左半还是右半 |

二者都常用离线、树状数组和回滚，但 CDQ 拆的是贡献关系，整体二分缩小的是每个询问的答案范围。

## 6 易错点和练习

- 三维非严格偏序先按三元组字典序排序，并合并完全重复点。
- 合并时第二维相等应先加入左点，第三维查询包含当前值；严格偏序要重新分析相等值的处理，第一维严格时不能直接套本模板。
- 每一层只撤销实际加入的数据；不要每个递归节点都 `assign` 清空整个树状数组。
- DP 必须先左递归，再跨区间转移，最后右递归；保留原来的状态编号。
- 统计原始序列的 `i<j` 关系时，下标顺序本身是一个约束，不能先随意按坐标重排原序列。
- 普通逆序对只需归并排序；多一维约束或有离线时间维时再考虑 CDQ。

练习可依次看 [P3810 三维偏序](https://www.luogu.com.cn/problem/P3810)、[P3157 动态逆序对](https://www.luogu.com.cn/problem/P3157)、[P2487 拦截导弹](https://www.luogu.com.cn/problem/P2487)。进阶的 [P3206 城市建设](https://www.luogu.com.cn/problem/P3206) 用时间分治、Kruskal 筛边和缩点压缩图规模，属于另一种应用，不能直接套三维偏序模板。
