#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    constexpr int N = 1e6 + 10;
    long long ans = 0;
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
    
    void sol() {
        SAM sam;
        string s;
        int T, k;
        cin >> s >> T >> k;
        sam.build(s);
        vector<int> order;
        order = sam.calc_endpos_size();
        
        if (T == 0) {
            fill(sam.siz.begin(), sam.siz.end(), 1);
        }
        sam.siz[1] = 0;

        vector<int> sum = sam.siz;
        for (auto u : order) {
            for (int i = 0; i < 26; i++){
                int x = sam.next(u, i);
                if (x) sum[u] += sum[x];
            }
        }

        if (sum[1] < k) {cout << -1; return;}
        string ans;

        function<void(int)> dfs = [&](int u) {
            if (k <= sam.siz[u]) return;
            k -= sam.siz[u];
            for (int i = 0; i < 26; i++) {
                int v = sam.next(u, i);
                if (!v) continue;
                if (k > sum[v]) k -= sum[v];
                else {
                    ans += char('a' + i);
                    dfs(v);
                    break;
                }
            }
        };
        dfs(1);
        cout << ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz ::main(), 0;
}