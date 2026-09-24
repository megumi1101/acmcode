#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
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
    
    void build(const string& s, const string &t) {
        last = 1;  
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int op = t[i] - '0';
            last = extend(last, ch - 'a', op);
        }
    }

    int extend(int p, int c, int op) {
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
        
        if (op) siz[cur] = 0;

        t[cur].len = t[p].len + 1;
        while (!t[p].next[c]) {
            t[p].next[c] = cur;
            p = t[p].link;
        }
        t[cur].link = extend(p, c, op);
        return cur;
    }

    i64 calc() {
        i64 ans = 0;
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

        for (int i = 1; i < t.size(); i++) {
            ans = max(ans, 1LL * siz[i] * t[i].len);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s, t;
    cin >> n >> s >> t;
    SAM sam;
    sam.build(s, t);
    cout << sam.calc() << "\n";
}