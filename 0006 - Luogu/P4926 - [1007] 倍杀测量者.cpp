#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {

struct Flag {
    int u, v;       // 题面顺序 O A B K：统一存 u=A, v=B
    double k;
    int type;       // 1: 我没k倍杀B就女装；2: B k倍杀我就女装（严格 <）
    Flag(int u=0,int v=0,double k=0,int type=0):u(u),v(v),k(k),type(type){}
};

int n, s, t;
vector<Flag> flags;
vector<pair<int,double>> known; // (选手 C, 已知分数 x0)

static bool spfa_has_positive_cycle(const vector<vector<pair<int,double>>>& g) {
    const int S = (int)g.size() - 1;     // 超级源编号：n+1
    const int V = S + 1;                 // 总点数：0..n 与 S

    const double NEG_INF = -1e100;
    vector<double> dist(V, NEG_INF);
    vector<int> cnt(V, 0);
    vector<char> inq(V, 0);
    queue<int> q;

    // 从超级源出发
    dist[S] = 0.0;
    q.push(S); inq[S] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        for (auto [v, w] : g[u]) {
            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                if (++cnt[v] >= V) return true;   // 正环：‘没人女装’系统无解
                if (!inq[v]) { q.push(v); inq[v] = 1; }
            }
        }
    }
    return false;
}

// check(T): 返回“是否必有人女装”（即‘没人女装’系统是否无解）
static bool check(double T) {
    const int S = n + 1;                            // 超级源
    vector<vector<pair<int,double>>> g(n + 2);      // 节点 0..n, S

    // 超级源到所有点（含 0）0 边
    for (int i = 0; i <= n; ++i) g[S].push_back({i, 0.0});

    // 固定已知分数：d[C] = log(x0)
    for (auto [c, x0] : known) {
        double lx = log(x0);
        g[0].push_back({c, +lx});   // d[c] >= d[0] + log x0
        g[c].push_back({0, -lx});   // d[0] >= d[c] - log x0
    }

    // 由两类 flag 构造“没人女装”的差分约束
    const double EPS = 1e-12;       // 处理 O=2 的严格不等式
    for (auto e : flags) {
        if (e.type == 1) {
            // sA >= (k - T) sB  => dA >= dB + log(k - T)
            if (e.k - T > 0.0) {
                g[e.v].push_back({e.u, log(e.k - T)});   // B -> A, +log(k-T)
            }
            // k - T <= 0 时恒成立，不加边
        } else {
            // sB < (k + T) sA   => dA >= dB - log(k + T) + EPS
            g[e.v].push_back({e.u, -log(e.k + T) + EPS}); // B -> A, -log(k+T)+EPS
        }
    }

    return spfa_has_positive_cycle(g);
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s >> t;
    flags.clear(); known.clear();
    flags.reserve(s); known.reserve(t);

    for (int i = 0; i < s; ++i) {
        int O, A, B; double k;
        cin >> O >> A >> B >> k;
        flags.emplace_back(A, B, k, O);    // 按题面 O A B K 存
    }
    for (int i = 0; i < t; ++i) {
        int C; double x0;
        cin >> C >> x0;
        known.emplace_back(C, x0);
    }

    // 若 T=0 时“没人女装”可行（check(0)==false），无法保证“必有人女装”
    if (!check(0.0)) {
        cout << -1 << '\n';
        return;
    }

    // 二分“最大 T 仍然必有人女装”（check(T)==true）
    double L = 0.0, R = 1e9, ans = 0.0;
    for (int it = 0; it < 70; ++it) {     // 充足精度
        double mid = (L + R) * 0.5;
        if (check(mid)) { ans = mid; L = mid; }
        else R = mid;
    }
    if (ans < 1e-4) {
        cout << -1 << '\n';
    } else {
        cout.setf(std::ios::fixed);
        cout << setprecision(6) << ans << '\n';
    }

}

} // namespace Xbbbz

int main() {
    Xbbbz::solve();
    return 0;
}
