// QOJ user: xbbbz
// Contest: 2023 �?8届ICPC济南�?// Problem: #7906. Almost Convex (7906)
// Submission: https://qoj.ac/submission/1455670
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

double Cross(Point a, Point b, Point c) { return (b - a) ^ (c - a); }

// ----------------------
// Andrew 单调链凸包（0-based 输入�?// 输入：p[0..n-1]
// 输出：按逆时针的凸包点（首尾不重复、不闭合�?// ----------------------
vector<Point> Andrew(vector<Point> p) {
    int n = (int)p.size();
    sort(p.begin(), p.end());
    vector<Point> h;
    // 下凸�?    for (int i = 0; i < n; ++i) {
        while ((int)h.size() > 1 && Cross(h[h.size()-2], h.back(), p[i]) <= 0) h.pop_back();
        h.push_back(p[i]);
    }
    int t = (int)h.size();
    // 上凸�?    for (int i = n - 2; i >= 0; --i) {
        while ((int)h.size() > t && Cross(h[h.size()-2], h.back(), p[i]) <= 0) h.pop_back();
        h.push_back(p[i]);
    }
    if (!h.empty()) h.pop_back(); // 去掉与首点重复的末点
    return h;
}

void sol() {
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;

    vector<Point> hull = Andrew(p);
    

    vector<int> vis(n, 0);
    for (int i = 0; i < n; ++i)
        for (const auto &hp : hull)
            if (p[i] == hp) { vis[i] = 1; break; }

    hull.push_back(hull[0]);
    int h = (int)hull.size();
    int ans = 0;
    for (int k = 0; k + 1 < h; ++k) {
        Point x = hull[k];
        Point y = hull[k + 1];
        Vector t = y - x;
        Vector nt = x - y;

        vector<pair<double, Point>> pts;  
        pts.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) pts.emplace_back(Angle(t, p[i] - x), p[i]);
        }
        sort(pts.begin(), pts.end());

        double mn = inf;
        for (auto &[ang1, ve] : pts) {
            double ag = Angle(nt, ve - y);
            if (ag < mn) ++ans;
            if (ag < mn) mn = ag;
        }
    }
    cout << ans + 1 << "\n";
}

void main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) sol();
}

} // namespace Xbbbz

int main() {
    Xbbbz::main();
    return 0;
}

/*
示例输入格式（占位）�?3
1 1
2 2
3 3
*/

</code>