#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> fa, sz;
    DSU(int n = 0) { init(n); }
    void init(int n) { fa.resize(n + 1); sz.assign(n + 1, 1); iota(fa.begin(), fa.end(), 0); }
    int find(int x){ return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void unite(int a, int b){
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        fa[b] = a; sz[a] += sz[b];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, d;
    if (!(cin >> N >> d)) return 0;
    vector<pair<int,int>> pos(N + 1);
    for (int i = 1; i <= N; ++i) cin >> pos[i].first >> pos[i].second;

    long long D2 = 1LL * d * d;
    vector<vector<int>> near_(N + 1);
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            long long dx = pos[i].first - pos[j].first;
            long long dy = pos[i].second - pos[j].second;
            if (dx*dx + dy*dy <= D2) {
                near_[i].push_back(j);
                near_[j].push_back(i);
            }
        }
    }

    DSU dsu(N);
    vector<char> on(N + 1, 0);

    string op;
    while (cin >> op) {
        if (op[0] == 'O') {
            int p; cin >> p;
            if (!on[p]) {
                on[p] = 1;
                for (int q : near_[p]) if (on[q]) dsu.unite(p, q);
            }
        } else if (op[0] == 'S') {
            int p, q; cin >> p >> q;
            if (on[p] && on[q] && dsu.find(p) == dsu.find(q)) cout << "SUCCESS\n";
            else cout << "FAIL\n";
        }
    }
    return 0;
}
