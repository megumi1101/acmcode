## AC自动机
给你一个文本串 S 和 n 个模式串 T 1~n,请你分别求出每个模式串 T i 在 S 中出现的次数。
fail 存回跳边,最长公共后缀
ch[i] 存回跳边和转移边
```cpp
struct AC {
    static const int A = 26;
    static const char B = 'a';

    struct Node {
        array<int, A> ch;
        int ct, fail;
        Node() {
            ch.fill(0);
            ct = fail = 0;
        }
    };

    vector<Node> t;
    int cnt;

    AC(int n = 0) {
        init(n);
    }

    void init(int n = 0) {
        t.clear();
        t.reserve(n + 1);
        t.push_back(Node());
        cnt = 0;
    }

    int newnode() {
        t.push_back(Node());
        return ++cnt;
    }

    int ins(const string &s) {
        int u = 0;
        for (char c : s) {
            int v = c - B;
            if (!t[u].ch[v]) t[u].ch[v] = newnode();
            u = t[u].ch[v];
        }
        return u;
    }

    void build() {  // !!!!! 一定要build()
        queue<int> q;
        for (int i = 0; i < A; i++) {
            if (t[0].ch[i]) {
                q.push(t[0].ch[i]);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < A; i++) {
                int v = t[u].ch[i];
                if (v) {
                    t[v].fail = t[t[u].fail].ch[i];
                    q.push(v);
                } else {
                    t[u].ch[i] = t[t[u].fail].ch[i];
                }
            }
        }
    }
};
```

