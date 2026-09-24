// QOJ user: xbbbz
// Contest: 2024 �?9届ICPC昆明�?// Problem: #9869. Horizon Scanning (9869)
// Submission: https://qoj.ac/submission/1498064
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
const double eps = 1e-8;        // 精度要求
const double PI  = acos(-1.0);  // 圆周�?const double inf = 1e18;        // 无穷�?
int sgn(double x) { return x < -eps ? -1 : (x > eps ? 1 : 0); }

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // 向量运算
    Point operator-(const Point &B) const { return Point(x - B.x, y - B.y); }
    Point operator+(const Point &B) const { return Point(x + B.x, y + B.y); }
    double operator^(const Point &B) const { return x * B.y - y * B.x; } // 叉积
    double operator*(const Point &B) const { return x * B.x + y * B.y; } // 点积
    Point operator*(const double &B) const { return Point(x * B, y * B); }
    Point operator/(const double &B) const { return Point(x / B, y / B); }

    // 排序比较
    bool operator<(const Point &B) const { return x < B.x || (x == B.x && y < B.y); }
    bool operator==(const Point &B) const { return sgn(x - B.x) == 0 && sgn(y - B.y) == 0; }
    bool operator!=(const Point &B) const { return sgn(x - B.x) || sgn(y - B.y); }
};

using Vector = Point;

double len(Vector A) { return sqrt(A * A); }

double Angle(Vector A, Vector B) {
    double t = (A * B) / len(A) / len(B);
    // 数值安�?    if (t < -1) t = -1;
    if (t >  1) t =  1;
    return acos(t); // 弧度 [0, π]
}

double Anglep(Point p) {
    if (sgn(p.x) == 0) {
        if (sgn(p.y) >= 0) return 0;
        else return PI;
    } else if (sgn(p.x) > 0) {
        return Angle({0.0, 1.0}, p);
    } else {
        return 2 * PI - Angle({0.0, 1.0}, p);
    }
}

struct Node {
    double x, y, ag;
};


    void sol() {
        int n, k;
        cin >> n >> k;
        vector<Node> pts(n);
        for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
        for (int i = 0; i < n; i++) pts[i].ag = Anglep({pts[i].x, pts[i].y});
        // pts[0].ag = Anglep({pts[0].x, pts[0].y});
        sort(pts.begin(), pts.end(), [&](const Node &n1, const Node &n2) {return n1.ag < n2.ag;});
        // for (int i = 0; i < n; i++) cerr << pts[i].ag << "\n";
        vector<double> Lines(n);
        vector<int> sum(n);
        int cnt = 0;
        Lines[cnt++] = {pts[0].ag};
        sum[0] = 1;
        for (int i = 1; i < n; i++) {
            if (sgn(pts[i].ag - pts[i - 1].ag) == 0) {
                sum[cnt - 1]++;
            } else {
                Lines[cnt++] = {pts[i].ag};
                sum[cnt - 1] = 1;
            }
        }
        Lines.resize(2 * cnt);
        sum.resize(2 * cnt);
        for (int i = cnt; i < 2 * cnt; i++) {
            Lines[i] = Lines[i - cnt];
            sum[i] = sum[i - cnt];
            Lines[i] = Lines[i - cnt] + 2 * PI;
        }
        for (int i = 1; i < 2 * cnt; i++) {
            sum[i] += sum[i - 1];
        }

        auto isok = [&](double mid) -> bool {
            for (int i = 0; i < cnt; i++) {
                auto it = lower_bound(Lines.begin(), Lines.end(), Lines[i] + mid);
                if (it == Lines.end()) {
                    int tsum = sum[cnt * 2 - 1] - sum[i];
                // cerr << tsum << "\n";

                    if (tsum < k) return 0;
                }
                int x = it - Lines.begin();
                int tsum = sum[x - 1] - sum[i];
                // cerr << tsum << "\n";
                if (tsum < k) return 0;
            }
            return 1;
        };

        double l = 0.0, r = 2 * PI, ans = r;
        while (l + eps < r) {
            double mid = (l + r) / 2;
            isok(mid);
            if (isok(mid)) r = mid, ans = mid;
            else l = mid;
        }
        cout << fixed << setprecision(12) << ans << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
}
</code>