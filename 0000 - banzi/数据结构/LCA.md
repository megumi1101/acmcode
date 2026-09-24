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
    
    

    // 初始化HPD和线段树
    void build(int u) {
        dfs1(u, 0, 1);
        dfs2(u, u);
    }
    
    int lca(int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            x = fa[top[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        return x;
    }
};
```