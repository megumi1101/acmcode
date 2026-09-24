#include <bits/stdc++.h>
using namespace std;

struct Line {
    long long m, b;
    long long f(long long x) const {
        __int128 v = (__int128)m * x + b;
        return (long long)v;
    }
};

static inline bool bad_lower(const Line& a, const Line& b, const Line& c){
    // 下凸壳（求最小值）判 b 冗余：
    // (b_b - a.b)*(b.m - c.m) >= (c.b - b.b)*(a.m - b.m)
    __int128 L = (__int128)(b.b - a.b) * (b.m - c.m);
    __int128 R = (__int128)(c.b - b.b) * (a.m - b.m);
    return L >= R;
}

struct HullMin {
    deque<Line> q; // 斜率按一个方向单调加入（增或减均可）
    void add(long long m, long long b){
        Line c{m,b};
        if (!q.empty() && q.back().m == m) { // 同斜率：保留截距更小的
            if (b >= q.back().b) return;
            q.pop_back();
        }
        while (q.size() >= 2 && bad_lower(q[q.size()-2], q.back(), c)) q.pop_back();
        q.push_back(c);
    }
    long long query_inc(long long x){ // x 递增
        while (q.size() >= 2 && q[0].f(x) >= q[1].f(x)) q.pop_front();
        return q[0].f(x);
    }
    long long query_dec(long long x){ // x 递减（这题用不到，留接口）
        while (q.size() >= 2 && q.back().f(x) >= q[q.size()-2].f(x)) q.pop_back();
        return q.back().f(x);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long L;
    if(!(cin >> n >> L)) return 0;
    vector<long long> C(n+1), S(n+1,0), A(n+1,0), dp(n+1,0);
    for (int i = 1; i <= n; ++i) cin >> C[i];

    for (int i = 1; i <= n; ++i){
        S[i] = S[i-1] + C[i];
        A[i] = S[i] + i;
    }
    long long B = L + 1;

    auto make_line = [&](int j){ // 段起点 j，对应用到 dp[j-1], A[j-1]
        long long t = A[j-1] + B;
        long long m = -2 * t;
        long long b = dp[j-1] + t * t;
        return Line{m, b};
    };

    HullMin hull;
    hull.add(make_line(1).m, make_line(1).b); // 初始：j=1

    for (int i = 1; i <= n; ++i){
        long long x = A[i];                        // 查询自变量递增
        dp[i] = x * x + hull.query_inc(x);         // 最小值 + x 递增
        if (i < n){                                 // 预备下一段起点 j=i+1 的直线
            Line ln = make_line(i+1);
            hull.add(ln.m, ln.b);
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
