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
        void clear() {
            while (q.size()) q.pop_back();
        }
    };


    void sol() {
        int n, m, p;
        cin >> n >> m >> p;
        vector<int> d(n + 1), t(m + 1), s(m + 1);
        vector<vector<int>> f(m + 1, vector<int>(p + 1));
        for (int i = 2; i <= n; i++) {cin >> d[i]; d[i] += d[i - 1];}
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x >> t[i];
            t[i] = t[i] - d[x];
        }
        sort(t.begin() + 1, t.end());
        for (int i = 1; i <= m; i++) s[i] = s[i - 1] + t[i]; 
        for(int i = 1; i <= m; i++) {
            f[i][1] = t[i] * i - s[i];
        }
        vector<HullMin> hull(p + 1);
        for (int i = 1; i <= m; i++) {
            if (i > 1) {
                for (int k = 2; k <= p; k++) {
                    int x = hull[k].query_inc(t[i]);
                    f[i][k] = t[i] * i - s[i] + x;
                    
                }
            }
            if (i == 1) 
                for (int k = 2; k <= p; k++) f[1][k] = f[1][1];
            for (int k = 1; k < p; k++) {
                int x = -i;
                int y = s[i] + f[i][k];
                hull[k + 1].add(x, y);
            }
        }
        cout << f[m][p];
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
