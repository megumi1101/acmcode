#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

struct AC {
    static const int A = 26;
    static const char B = 'a';

    struct Node {
        array<int, A> ch;
        int ct, fail, up, len;
        Node() {
            ch.fill(0);
            ct = fail = up = 0;
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
        t[u].ct = 1;
        t[u].len = (int)s.size();
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
                    int f = t[v].fail;
                    if (t[f].ct == 1) {
                        t[v].up = f;
                    } else {
                        t[v].up = t[f].up;
                    }
                    q.push(v);
                } else {
                    t[u].ch[i] = t[t[u].fail].ch[i];
                }
            }
        }
    }
};

void norm(int &x) {
    x %= mod;
    if (x < 0) x += mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> premx(n + 5), sufmx(n + 5);
    for (int i = 1; i <= n; i++) {
        premx[i] = max(a[i], premx[i - 1] + a[i]);
    }

    for (int i = n; i >= 1; i--){ 
        sufmx[i] = max(a[i], sufmx[i + 1] + a[i]);
    }

    vector<int> pres(n + 5), sufs(n + 5);
    vector<int> sum(n + 5);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        pres[i] = pres[i - 1] +  i * a[i] % mod;
        pres[i] %= mod;
    }

    for (int i = n; i >= 1; i--) {
        sufs[i] = sufs[i + 1] + (n + 1 - i) * a[i] % mod;
        sufs[i] %= mod;
    }

    AC ac;
    
    vector<int> id(q + 1); // 第t个的字符串的去重后的下标
    vector<int> to(3e5 + 10); // 自动机上点对应去重后下标
    int cnt = 0;
    for (int i = 1; i <= q; i++) {
        string t;
        cin >> t;
        int u = ac.ins(t);
        if (to[u] == 0) {
            to[u] = ++cnt;
        }
        id[i] = to[u];
    }

    ac.build();
    int u = 0;
    vector<int> ansmx(q + 1, -1e18), anssum(q + 1), lst(q + 1);
    for (int i = 1; i <= n; i++) {
        int v = s[i] - 'a';
        u = ac.t[u].ch[v];
        int now = u;
        while (now) {
            if (ac.t[now].ct) {
                int idx = to[now];
                int len = ac.t[now].len;

                int L_mx = i - len + 1;
                int L_mn = lst[idx] + 1;
                int R_mn = i;
                int R_mx = n;

                ansmx[idx] = max(ansmx[idx], max(0ll, premx[L_mx - 1]) + max(0ll, sufmx[R_mn + 1]) + sum[R_mn] - sum[L_mx - 1]);
                
                int summid = (L_mx - L_mn + 1) * (R_mx - R_mn + 1) % mod * ((sum[R_mn] - sum[L_mx - 1]) % mod) % mod;
                
                int suml = pres[L_mx - 1] - pres[L_mn - 1] - (L_mn - 1) * ((sum[L_mx - 1] - sum[L_mn - 1]) % mod) % mod;
                norm(suml);
                suml = suml * (R_mx - R_mn + 1) % mod;

                int sumr = sufs[R_mn + 1] * (L_mx - L_mn + 1) % mod;
                
                anssum[idx] += suml + sumr + summid;
                norm(anssum[idx]);

                lst[idx] = L_mx;
            }
            now = ac.t[now].up;
        }
    }

    for (int i = 1; i <= q; i++) {
        cout << ansmx[id[i]] << " " << anssum[id[i]] << "\n";
    }
}

/*
8 1
bbbabaab
333213212 -132332121 432132321 -11232312 513132322 -913132232 212332132 -631323212
b
*/