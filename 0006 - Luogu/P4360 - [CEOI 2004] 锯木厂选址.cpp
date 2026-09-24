#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 1e18;
    struct Line {
        long long m, b;
        long long f(long long x) const {
            __int128 v = (__int128)m * x + b;
            return (long long)v;
        }
    };

    static inline bool bad_lower(const Line& a, const Line& b, const Line& c){
        // 下凸壳（求最小值）判 b 冗余： (b-b_a)(m_b-m_c) >= (b_c-b_b)(m_a-m_b)
        __int128 L = (__int128)(b.b - a.b) * (b.m - c.m);
        __int128 R = (__int128)(c.b - b.b) * (a.m - b.m);
        return L >= R;
    }

    struct HullMin {               // 维护“最小值”的下凸壳
        std::deque<Line> q;
        void add(long long m, long long b){     // 斜率按一个方向单调加入（增或减都行）
            Line c{m,b};
            if (!q.empty() && q.back().m == m) { // 同斜率：保留截距更小的
                if (b >= q.back().b) return;
                q.pop_back();
            }
            while (q.size() >= 2 && bad_lower(q[q.size()-2], q.back(), c)) q.pop_back();
            q.push_back(c);
        }
        long long query_inc(long long x){       // x 递增
            while (q.size() >= 2 && q[0].f(x) >= q[1].f(x)) q.pop_front();
            return q[0].f(x);
        }
        long long query_dec(long long x){       // x 递减
            while (q.size() >= 2 && q.back().f(x) >= q[q.size()-2].f(x)) q.pop_back();
            return q.back().f(x);
        }
    };


    void sol() {
        int n;
        cin >> n;
        vector<int> w(n + 1), d(n + 1), s(n + 1), c(n + 1), sw(n + 1);
        for (int i = n; i >= 1; i--) cin >> w[i] >> d[i];
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + d[i];
        for (int i = 1; i <= n; i++) sw[i] = sw[i - 1] + w[i];
        for (int i = 1; i <= n; i++) c[i] = c[i - 1] + s[i] * w[i];
        HullMin hull;
        int ans = inf;
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                int tmp = c[i - 1] + c[n] - c[i] - s[i] * (sw[n] - sw[i]);
                tmp += hull.query_inc(sw[i - 1]);
                ans = min(ans, tmp);
            }
            int m = -s[i];
            int b = c[i - 1] - c[i] + s[i] * sw[i];
            hull.add(m, b);
        }
        cout << ans << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}