- [kmp](#kmp)
- [双模hash](#双模hash)
- [mabacher](#mabacher)
- [AC自动机](#ac自动机)
- [SAM](#sam)

## kmp
pi[i]为以i为结尾的最长公共前后缀(从0开始)
求pi数组
```cpp
vector<int> get_pi(string s) {
    int n = (int)s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
void kmpSearch(string txt, string pat) {
    vector<int> next = buildNext(pat);
    for (int i = 0, j = 0; i < txt.size(); ++i) {
        while (j > 0 && txt[i] != pat[j]) j = next[j - 1];
        if (txt[i] == pat[j]) ++j;
        if (j == pat.size()) {
            cout << "Pattern found at index " << i - j + 1 << endl;
            j = next[j - 1];
        }
    }
}
```

## 双模hash
从 0 开始
```cpp
struct Base {
    array<int, N> pow{};
    Base(int mod) {
        pow[0] = 1;
        for (int i = 1; i < N; ++i) pow[i] = 1LL * pow[i - 1] * B % mod;
    }
    const int operator[](int idx) const { return pow[idx]; }
} p1(mod1), p2(mod2);

struct Hash {
    vector<int> h1, h2; // 前缀哈希，h[0] = 0

    void build(const string& s) {
        int n = (int)s.size();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            h1[i + 1] = ( (long long)h1[i] * B + (s[i] - 'a' + 1) ) % mod1;
            h2[i + 1] = ( (long long)h2[i] * B + (s[i] - 'a' + 1) ) % mod2;
        }
    }

    static int merge(int x, int y) { return (x << 31) | y; } 

    // 0-based 闭区间 [l, r]
    int calc(int l, int r) const {
        int len = r - l + 1;
        int res1 = ( h1[r + 1] - 1LL * h1[l] * p1[len] % mod1 + mod1 ) % mod1;
        int res2 = ( h2[r + 1] - 1LL * h2[l] * p2[len] % mod2 + mod2 ) % mod2;
        return merge(res1, res2);
    }
};


```
## mabacher
在O(n)的时间内求出一个字符串的最长回文串
可以在两个字符之间添加 # ,这样可以保证所有的回文串都是奇回文串
d[i]表示回文半径,例如 #a#b#a# 的回文半径为 4, 我们同样可以得知在原字符串中该回文串的长度就是 **回文半径 - 1**
维护当前**右端点最靠右**的最长回文串的l, r (左右端点)
```cpp
vector get_d (string s) {
    int n = (int)s.size();
    vector<int> d(n);
    d[1] = 1;
    for (int i = 2, l, r = 1, i < s.size(); i++) {
        if (i <= r) d[i] = min(d[r + l - i], r - i + 1);
        while (s[i + d[i]] == s[i - d[i]]) d[i]++;
        if (i + d[i] - 1 > r) r = i + d[i] - 1, l = i - d[i] + 1;
    } 
    return d;
}
string s = "&#";
string tmp; cin >> tmp;
for (char c : string tmp) {
    s += c;
    s += "#"
}
```
## AC自动机
给你一个文本串 S 和 n 个模式串 T 1~n,请你分别求出每个模式串 T i 在 S 中出现的次数。
ne[u] 存回跳边,最长公共后缀
ch[u][i] 存回跳边和转移边
```cpp
struct AC {
    static const int SIGMA = 26;
    static const char BASE = 'a';
    int Maxnode;
    struct Node {
        vector<int> ch;
        int ct, fail;
        Node() {
            fail = 0, ct = 0;
            ch.assign(26, 0);
        }
    };
    
    vector<Node> t;
    int cnt, maxnode;

    AC (int maxnode) {
        init(maxnode);
    }

    void init(int maxnode) {
        Maxnode = maxnode;
        t.assign(Maxnode, Node());
        cnt = 0;
    }

    int newnode () {
        cnt++;
        if (cnt >= Maxnode) {
            Maxnode = Maxnode * 3 / 2 + 1000;
            t.resize(Maxnode);
        }
        t[cnt] = Node();
        return cnt;
    }

    int ins(const string &s) {
        int u = 0;
        for (char c : s) {
            int v = c - BASE;
            if (!t[u].ch[v]) t[u].ch[v] = newnode();
            u = t[u].ch[v];
            t[u].ct++;
        }
        return u;
    }

    void build (vector<int> &a) {
        queue<int> q;
        for (int i = 0; i < 26; i++) if (t[0].ch[i]) q.push(t[0].ch[i]), a.push_back(t[0].ch[i]);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < 26; i++) {
                int v = t[u].ch[i];
                if (v) t[v].fail = t[t[u].fail].ch[i], q.push(v), a.push_back(v);
                else t[u].ch[i] = t[t[u].fail].ch[i]; 
            }
        }
    }
};


void add(string s) {
    int u = 0;
    for(int i = 0; i < s.size(); i++) {
        int v = s[i] - 'a';
        if(!ch[u][v]) ch[u][v] = ++count;
        u = ch[u][v];
        if(i == s.size() - 1) cnt[u]++;
    }
}
void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (ch[0][i]) q.push(ch[0][i]);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < 26; i++) {
            int v = ch[u][i];
            if (v) ne[v] = ch[ne[u]][i], q.push(v), in[ne[v]]++;
            else ch[u][i] = ch[ne[u]][i];
        }
    }
}
// int cx(string s) {
//         int ans=0, u=0;
//         for(int i=0;i<s.size();i++) {
//             u=ch[u][s[i]-'a'];
//             for(int j=u;j&&~cnt[j];j=ne[j]) {
//                 ans+=cnt[j];cnt[j]=-1;
//             }
//         }
//         return ans;
// }
void cx(string s) {
    int u = 0;
    for(int i = 0; i < s.size(); i++) {
        u = ch[u][s[i] - 'a'];
        num[u]++;
    }
    queue<int> q;
    for(int i = 1; i <= count; i++) {
        if (in[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ans[u] = num[u] * cnt[u];
        int v = ne[u];
        in[v]--;
        if(!in[v]) q.push(v);
        num[v] += num[u];
    }
}   

```

## SAM
```cpp
struct SAM {
    static constexpr int ALPHABET_SIZE = 26;
    struct Node {
        int len;
        int link;
        array<int, ALPHABET_SIZE> next;
        Node() : len{}, link{}, next{} {}
    };
    vector<Node> t;
    SAM() { init();}
    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }
    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }
    int extend(int p, int c) {
        if (t[p].next[c]) {
            int q = t[p].next[c];
            if (t[q].len == t[p].len + 1) {
                return q;
            }
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = t[q].link;
            t[r].next = t[q].next;
            t[q].link = r;
            while (t[p].next[c] == q) {
                t[p].next[c] = r;
                p = t[p].link;
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        while (!t[p].next[c]) {
            t[p].next[c] = cur;
            p = t[p].link;
        }
        t[cur].link = extend(p, c);
        return cur;
    }
    
    int next(int p, int x) { return t[p].next[x];}
    int link(int p) {return t[p].link;}
    int len(int p) {return t[p].len;}
    int size() {return t.size();}
};
```

```cpp
struct SAM {
    static constexpr int ALPHABET_SIZE = 26;
    struct Node {
        int len;
        int link;
        array<int, ALPHABET_SIZE> next;
        Node() : len{}, link{}, next{} {}
    };
    vector<Node> t;
    vector<int> siz;
    int last;

    SAM() { init(); }

    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
        siz.assign(2, 0);  
        last = 1;
    }

    int newNode() {
        t.emplace_back();
        siz.push_back(1);  
        return t.size() - 1;
    }
    
    void build(const string& s) {
        last = 1;  
        for (char ch : s) {
            last = extend(last, ch - 'a');
        }
    }

    int extend(int p, int c) {
        if (t[p].next[c]) {
            int q = t[p].next[c];
            if (t[q].len == t[p].len + 1) {
                return q;
            }
            int r = newNode();
            siz[r] = 0;
            t[r].len = t[p].len + 1;
            t[r].link = t[q].link;
            t[r].next = t[q].next;
            t[q].link = r;
            while (t[p].next[c] == q) {
                t[p].next[c] = r;
                p = t[p].link;
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        while (!t[p].next[c]) {
            t[p].next[c] = cur;
            p = t[p].link;
        }
        t[cur].link = extend(p, c);
        return cur;
    }

    vector<int> calc_endpos_size() {
        vector<int> order(t.size() - 1);
        for (int i = 1; i < t.size(); i++) order[i - 1] = i;
        sort(order.begin(), order.end(), [&](int a, int b) {
            return t[a].len > t[b].len;
        });
        for (int u : order) {
            if (t[u].link >= 0) {
                siz[t[u].link] += siz[u];
            }
        }
        return order;
    }
    int next(int p, int c) { return t[p].next[c]; }
    int link(int p) { return t[p].link; }
    int len(int p) { return t[p].len; }
    int size() { return t.size(); }
};
```
```cpp
struct SAM {
    struct Node {
        int len;
        int link;
        map<int, int> next;
        Node() : len{}, link{}, next{} {}
    };
    vector<Node> t;
    SAM() { init();}
    void init() {
        t.assign(2, Node());
        t[0].len = -1;
    }
    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }
    int extend(int p, int c) {
        if (t[p].next.count(c)) {
            int q = t[p].next[c];
            if (t[q].len == t[p].len + 1) {
                return q;
            }
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = t[q].link;
            t[r].next = t[q].next;
            t[q].link = r;
            while (t[p].next[c] == q) {
                t[p].next[c] = r;
                p = t[p].link;
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        while (!t[p].next.count(c)) {
            t[p].next[c] = cur;
            p = t[p].link;
        }
        t[cur].link = extend(p, c);
        return cur;
    }

    int next(int p, int x) { return t[p].next.count(x) ? t[p].next[x] : 0; }
    int link(int p) {return t[p].link;}
    int len(int p) {return t[p].len;}
    int size() {return t.size();}
};
```