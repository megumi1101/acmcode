#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    constexpr int N = 1e6 + 10;
    int ans = 0;
    struct SAM {
        // static constexpr int ALPHABET_SIZE = 26;
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
                ans += t[p].len - t[t[p].link].len;
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
    
    void sol() {
        SAM sam;
        int n;
        cin >> n;
        vector<int> a(n + 10);
        int p = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            sam.t[0].next[a[i]] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
           
            p = sam.extend(p, a[i]);
            cout << ans << "\n";
        }
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