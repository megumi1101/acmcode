
## ST表
```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template <typename T, T (*comp)(T, T) = nullptr>
struct ST {
    vector<vector<T>> t;
    vector<int> lg;

    ST() {}
    
    ST(const vector<T>& data) {
        build(data);
    }
    
    void build(const vector<T>& data) {
        int n = data.size() - 1;  // 因为数据从1开始，size()包含0位置
        int logn = log2(n) + 1;
        t.assign(n + 1, vector<T>(logn));  // 调整为n+1
        
        // 从1开始填充数据
        for (int i = 1; i <= n; ++i) {
            t[i][0] = data[i];
        }
        
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                if constexpr (comp == nullptr) {
                    t[i][j] = min(t[i][j-1], t[i + (1 << (j-1))][j-1]);
                } else {
                    t[i][j] = comp(t[i][j-1], t[i + (1 << (j-1))][j-1]);
                }
            }
        }
        
        lg.resize(n + 2);  // 调整为n+2
        lg[0] = lg[1] = 0;
        for (int i = 2; i <= n + 1; ++i) {
            lg[i] = lg[i/2] + 1;
        }
    }

    T query(int l, int r) {
        int k = lg[r - l + 1];
        if constexpr (comp == nullptr) {
            return min(t[l][k], t[r - (1 << k) + 1][k]);
        } else {
            return comp(t[l][k], t[r - (1 << k) + 1][k]);
        }
    }
};

// 示例比较函数
int my_min(int a, int b) {
    return min(a, b);
}

int my_max(int a, int b) {
    return max(a, b);
}

int main() {
    // 注意：data[0]不使用，从data[1]开始
    vector<int> data = {0, 3, 1, 4, 2, 5, 7, 9, 6}; // 第一个元素0占位
    
    // 使用默认的min函数
    ST<int> st_min(data);
    cout << "RMQ [2,5] min: " << st_min.query(2, 5) << endl; // 1
    
    // 使用自定义的比较函数
    ST<int, my_max> st_max(data);
    cout << "RMQ [2,5] max: " << st_max.query(2, 5) << endl; // 5
    
    return 0;
}
```

## 并查集
```cpp
struct DSU {
    vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};
```
## 平板电视

### 头文件
```cpp
#include<ext/pb_ds/assoc_container.hpp> //必写
#include<ext/pb_ds/tree_policy.hpp>//用tree
#include<ext/pb_ds/hash_policy.hpp>//用hash
#include<ext/pb_ds/trie_policy.hpp>//用trie
#include<ext/pb_ds/priority_queue.hpp>//用priority_queue

using namespace __gnu_pbds; 
```

### 平衡树
#### 定义
```cpp
tree<
    Key,                  // 键类型
    Mapped,               // 值类型（若为集合则用 null_type）
    Compare,              // 比较函数（如 less<int>）
    Tag,                  // 树类型标签（rb_tree_tag ）
    Node_Update           // 节点更新策略（tree_order_statistics_node_update）
> tr;
//example
tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, 
tree_order_statistics_node_update> tr;
```


#### 操作
```cpp
tr.insert(make_pair(x, y)); //插入;
tr.erase(make_pair(x, y)); //删除;
tr.order_of_key(make_pair(x, y)); //base 0 求排名 （即小于该元素的个数）
tr.find_by_order(k); //base 0 查询排名为 k 的元素（即第 k+1 小的元素）返回迭代器
tr.join(b); //将b并入tr，前提是两棵树类型一样且没有重复元素 
tr.split(v, b); //分裂，key小于等于v的元素属于tr，其余的属于b
tr.lower_bound(x); //返回第一个大于等于x的元素的迭代器
tr.upper_bound(x); //返回第一个大于x的元素的迭代器
```
元素不能重复,如果你想要重复的话,可以再开一维加上编号
```cpp
//example
for (int i = 0; i < n; ++i) tr.insert(make_pair(a[i], i));

//然后这样找到小于一个元素x的个数
it = ps.lower_bound(make_pair(x, -1));
int ans = ps.order_of_key(*it);
```

### priority_queue
#### 定义
```cpp

__gnu_pbds:: priority_queue<Key, // 键类型
                            Compare, // 比较函数（如 less<int>）
                            Tag // 实现方式
                            > Q;
//加上命名空间pbds, 否则可能和<queue>的pq冲突

/*其中的TAG为类型，有以下几种：
pairing_heap_tag
thin_heap_tag
binomial_heap_tag
rc_binomial_heap_tag 
binary_heap_tag
其中pairing_help_tag最快*/

/*使用合并的时候使用 pairing_heap_tag
做dijisktra的时候使用 thin_heap_tag*/

//example
__gnu_pbds:: priority_queue<int, less<int>, pairing_heap_tag> Q;
```

#### 操作
1.基本操作

```cpp
Q.push(x);
Q.pop();
Q.top();
Q.empty();
Q.size();
```
2.将另一个堆加入Q

```cpp
Q.join(b);
```

3.删除修改 

```cpp
Q.modify(it,6);
Q.erase(it);

// 获取元素句柄（Iterator/Handle）
// 插入元素时，push 方法会返回一个指向该元素的 句柄（point_iterator），后续可通过句柄操作该元素
auto it1 = Q.push(10);  // 插入10，获取句柄it1
auto it2 = Q.push(20);  // 插入20，获取句柄it2
auto it3 = Q.push(15);  // 插入15，获取句柄it3

Q.erase(it2); // 删除元素20，堆中剩余{15, 10}
Q.modify(it, 50); //将it指向的元素修改为50，并重新调整堆
```

4.分裂

```cpp
Q.push(10); Q.push(20); Q.push(30); Q.push(15); // Q = {30, 20, 15, 10}
Q.split(15, Q2); // 以15为界分裂

// 结果：
// Q = {15, 10}     (所有 ≤15 的元素)
// Q2 = {30, 20}     (所有 >15 的元素)
```


## 线段树

### 区间修改，区间查询。
```cpp
#define int long long
#define ls (u << 1)
#define rs (u << 1 | 1)
    template<typename Info, typename Tag>
    struct SegmentTree {
        int n;
        vector<Info> info;
        vector<Tag> tag;
        SegmentTree(auto l, auto r) {
            n = r - l;
            info.assign(4 << __lg(n), Info{});
            tag.assign(4 << __lg(n), Tag{});
            build(1, 1, n, l);
        }
        void pull(int u) {
            info[u] = info[ls] + info[rs];
        }
        void apply(int u, const Tag& v) {
            info[u].apply(v);
            tag[u].apply(v);
        }
        void push(int u) {
            apply(ls, tag[u]), apply(rs, tag[u]);
            tag[u] = Tag{};
        }
        void build(int u, int l, int r, auto it) {
            if (l == r) {
                info[u] = *it;
                return;
            }
            int m = (l + r) >> 1;
            build(ls, l, m, it);
            build(rs, m + 1, r, it + m - l + 1);
            pull(u);
        }
        void modify(int L, int R, int u, int l, int r, const Tag& v) {
            if (L <= l && r <= R) {
                apply(u, v);
                return;
            }
            int m = (l + r) >> 1;
            push(u);
            if (L <= m) modify(L, R, ls, l, m, v);
            if (R > m) modify(L, R, rs, m + 1, r, v);
            pull(u);
        }

        void modify(int l, int r, const Tag& v) {
            assert(l <= r);
            modify(l, r, 1, 1, n, v);
        }

        Info query(int L, int R, int u, int l, int r) {
            if (L <= l && r <= R) {
                return info[u];
            }
            push(u);
            int m = (l + r) >> 1;
            if (R <= m) {
                return query(L, R, ls, l, m);
            } else if (L > m) {
                return query(L, R, rs, m + 1, r);
            } else {
                return query(L, R, ls, l, m) + query(L, R, rs, m + 1, r);
            }
        }

        Info query(int l, int r) {
            assert(l <= r);
            return query(l, r, 1, 1, n);
        }
    };
#undef ls
#undef rs
    constexpr int Mod = 998244353;

    struct Tag {
        int add;
        Tag (int x = 0) {
            add = x;
        }
        void apply(const Tag &v) {
            add += v.add;
        }
    };

    struct Info {
        int sum, siz;
        Info (int x = 0) {
            sum = x; siz = 1;
        }
        Info (int x, int y) {
            sum = x; siz = y;
        }
        void apply(const Tag &v) {
            sum += siz * v.add;
        }
    };

    Info operator+(const Info& x, const Info& y) {
        return {x.sum + y.sum, x.siz + y.siz};
    }
```


### 单点修改, 区间查询
```cpp
#define ls (u << 1)
#define rs (u << 1 | 1)
    template<typename Info>
    struct SegmentTree {
        int n;
        vector<Info> info;
        SegmentTree(int n_) {
            n = n_;
            info.assign(4 << __lg(n_), Info{});
        }
        void pull(int u) {
            info[u] = info[ls] + info[rs];
        }
        void modify(int u, int l, int r, int x, const Info &v) {
            if (r == l) {
                info[u] = v;
                return;
            }
            int m = (l + r) >> 1;
            if (x <= m) {
                modify(ls, l, m, x, v);
            } else {
                modify(rs, m + 1, r, x, v);
            }
            pull(u);
        }
        void modify(int u, const Info &v) {
            modify(1, 1, n, u, v);
        }
        Info query(int L, int R, int u, int l, int r) {
            if (L <= l && r <= R) {
                return info[u];
            }
            int m = (l + r) >> 1;
            if (R <= m) {
                return query(L, R, ls, l, m);
            } else if (L > m) {
                return query(L, R, rs, m + 1, r);
            } else {
                return query(L, R, ls, l, m) + query(L, R, rs, m + 1, r);
            }
        }
        Info query(int l, int r) {
            assert(l <= r);
            return query(l, r, 1, 1, n);
        }
    };
#undef ls
#undef rs
```
## 树链剖分

```cpp
#include <vector>
#include <algorithm>
using namespace std;

constexpr int Mod = 998244353;

template<typename SegmentTree>
struct HPD {
    vector<int> top, siz, dep, son, id, fa, a, na;
    vector<vector<int>> ed;
    // a 存储原始节点值 na 存储按照ID映射后的值
    int cnt = 0, n;
    SegmentTree seg;  
    
    HPD(int n, const vector<int>& vals) 
        : n(n), a(vals), 
          top(n + 1), siz(n + 1), dep(n + 1),
          son(n + 1, -1), id(n + 1), fa(n + 1),
          ed(n + 1), na(n + 1) {}

    // 添加边
    void add_edge(int u, int v) {
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    // 第一次DFS，计算大小、深度、重儿子
    void dfs1(int u, int f, int deep) {
        siz[u] = 1;
        dep[u] = deep;
        fa[u] = f;
        int maxson = -1;
        for (auto v : ed[u]) {
            if (v == f) continue;
            dfs1(v, u, deep + 1);
            siz[u] += siz[v];
            if (siz[v] > maxson) {
                maxson = siz[v];
                son[u] = v;
            }
        }
    }

    // 第二次DFS，分配ID并确定链顶
    void dfs2(int u, int topfa) {
        id[u] = ++cnt;
        top[u] = topfa;
        na[cnt] = a[u];  // 按照新ID存储值
        
        if (son[u] == -1) return;
        dfs2(son[u], topfa);
        for (auto v : ed[u]) {
            if (v == fa[u] || v == son[u]) continue;
            dfs2(v, v);
        }
    }
    
    // int lca(int x, int y) {
    //     while (top[x] != top[y]) {
    //         if (dep[top[x]] < dep[top[y]]) swap(x, y);
    //         x = fa[top[x]];
    //     }
    //     if (dep[x] > dep[y]) swap(x, y);
    //     return x;
    // }

    // 初始化HPD和线段树
    void build(int u) {
        dfs1(u, 0, 1);
        dfs2(u, u);
        // 现在用映射后的值初始化线段树
        seg = SegmentTree(na.begin() + 1, na.end());
    }

    // 路径加法
    void add_path(int x, int y, int k) {
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            seg.modify(id[top[x]], id[x], k);
            x = fa[top[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        seg.modify(id[x], id[y], k);
    }

    // 路径查询
    int query_path(int x, int y) {
        int res = 0;
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            res += seg.query(id[top[x]], id[x]).sum;
            res %= Mod;
            x = fa[top[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        res += seg.query(id[x], id[y]).sum;
        res %= Mod;
        return res;
    }

    // 子树加法
    void add_subtree(int u, int k) {
        seg.modify(id[u], id[u] + siz[u] - 1, k);
    }

    // 子树查询
    int query_subtree(int u) {
        return seg.query(id[u], id[u] + siz[u] - 1).sum % Mod;
    }
};
```

## 树状数组

```cpp
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
    //查找满足前缀和 <= k 的最大位置
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i] <= k) {
                x += i;
                cur = cur + a[x];
            }
        }
        return x;
    }
};
```

## Kruskal 重构树
Kruskal 重构树（Kruskal Reconstruction Tree, KRT）是一个在图论和竞赛中常用的结构，它本质上是把原图通过 Kruskal 算法的过程转化为一棵「树状结构」，常用于解决一些关于 **路径上边权的最大/最小值查询** 的问题。下面我帮你从原理到应用梳理一下：

1. 构造原理

* **普通 Kruskal 算法**：按边权从小到大加入边，维护并查集。
* **重构树的关键**：

  * 每次合并两个连通块时，**新建一个“父节点”**，代表这条边的权值。
  * 这个新建节点连向被合并的两个子块的根节点。
  * 最终得到一棵二叉树，树高是对数级别。

形式化：

* 原图有 $n$ 个点，标号 $1 \dots n$。
* Kruskal 算法过程中，每次合并 $u, v$ 时，创建一个新节点 $w$，编号从 $n+1$ 往上递增。
* 令 $w$ 的权值 = 当前合并用的边权。
* 把 $u, v$ 当前所在集合的代表节点作为 $w$ 的两个儿子。
* 并查集更新：代表元素改为 $w$。

最后会得到一棵（或森林，若原图不连通）二叉树，高度约为 $O(\log n)$。


2. 性质

1. **LCA 与路径最大边权**
   在 Kruskal 重构树上，两个原始节点 $u, v$ 的最近公共祖先（LCA）的权值，等于原图中 $u, v$ 之间路径的最大边权（在最小生成树中）。

2. **单调性**
   新节点的权值一定大于等于其子节点的权值，形成“单调非减”的树。

3. **点数**
   最终节点数不超过 $2n-1$。

3. 应用场景

* **动态连通性 / 离线查询**：
  例如询问在“边权 ≤ k”时，两个点是否连通。
  → 只需在重构树上看两点 LCA 的权值是否 ≤ k。

* **路径最大边权**：
  给定两点，问它们在 MST 路径上的最大边。
  → 找到 LCA 节点，读它的权值即可。

* **二分答案**：
  在很多「最小化最大边」或「最大化最小边」的题目里，可以用重构树 + LCA 优化。

```cpp
#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n+1) { iota(fa.begin(), fa.end(), 0); }
    int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
    void unite(int x, int y, int w, vector<vector<int>>& G, vector<int>& val, int& tot){
        x=find(x), y=find(y);
        if(x==y) return;
        ++tot; val[tot]=w;
        G[tot].push_back(x);
        G[tot].push_back(y);
        fa[x]=fa[y]=tot;
    }
};

struct Edge {int u,v,w;};
int main(){
    int n,m; cin>>n>>m;
    vector<Edge> edges(m);
    for(auto &e:edges) cin>>e.u>>e.v>>e.w;
    sort(edges.begin(), edges.end(), [](auto a, auto b){return a.w<b.w;});
    
    int tot=n; // 新点编号从 n+1 开始
    vector<vector<int>> G(2*n+5);
    vector<int> val(2*n+5,0);

    DSU dsu(2*n);
    for(auto &e:edges) dsu.unite(e.u, e.v, e.w, G, val, tot);

    // 此时 G 表示 Kruskal 重构树
    // val[x] 表示节点 x 对应的权值（<=n 的点 val=0，>n 的点 val=合并边权）
    // 可以用 LCA 做路径最大边权查询
}
```

