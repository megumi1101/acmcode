my计算几何
```cpp
using Point = complex<double>;
using Vector = Point;

const double eps = 1e-8;
const double PI = acos(-1.0);
const double inf = 1e18;

// abs(a)                  // |a|
// norm(a)                 // |a|^2
// arg(a)                  // 极角
// conj(a)                 // 关于 x 轴对称
// real(conj(a) * b)       // dot(a,b)
// imag(conj(a) * b)       // cross(a,b)
// a * polar(1.0, theta)   // 逆时针旋转 theta
// arg(b / a)              // a -> b 的有向角
double angle(Vector a, Vector b) {
    return atan2((double)cross(a, b), (double)dot(a, b));
} // 坐标是整数时用这个
int sgn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0; }
double dot(Vector a, Vector b) { return real(conj(a) * b); }
double cross(Vector a, Vector b) { return imag(conj(a) * b); }
double Cross(Point a, Point b, Point c) { return cross(b - a, c - a); }
bool cmp (Point a, Point b) {
    if (real(a) != real(b)) return real(a) < real(b);
    return imag(a) < imag(b);
}
double turn(double t) {
    return t >= 0.0 ? t : t + PI * 2.0;
} // (-PI, PI] -> [0, 2 * PI)
 
vector<Point> Andrew(vector<Point> p) {
    sort(p.begin(), p.end(), cmp);

    vector<Point> h;

    // 下凸包
    for (auto x : p) {
        while (h.size() > 1 && Cross(h[h.size() - 2], h.back(), x) <= 0)
            h.pop_back();
        h.push_back(x);
    }

    int t = h.size();
    
    // 上凸包
    for (int i = (int)p.size() - 2; i >= 0; i--) {
        while ((int)h.size() > t && Cross(h[h.size() - 2], h.back(), p[i]) <= 0)
            h.pop_back();
        h.push_back(p[i]);
    }

    if (!h.empty()) h.pop_back();
    return h;
}
```