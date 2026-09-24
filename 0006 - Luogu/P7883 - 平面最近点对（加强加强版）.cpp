#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

// #define LOCAL_EXPERIMENT 

const long long INF = 9e18;

struct Point {
    long long x, y;
};

// 全程比较核心：整数距离的平方
inline long long getDistanceSq(const Point& a, const Point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// 供全局排序使用：按 X 坐标从小到大
bool cmpX(const Point& a, const Point& b) {
    return a.x < b.x;
}

// 供 Multiset 使用的比较器：严格按 Y 坐标从小到大
// 注意：如果 Y 相同，必须按 X 比较，否则会被 set 认为是同一个点而被覆盖/忽略
struct cmpY {
    bool operator()(const Point& a, const Point& b) const {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    }
};

long long solveClosestPairSweepLine(vector<Point>& points) {
    int n = points.size();
    if (n < 2) return 0;

    // 1. 按 X 坐标排序，准备从左向右扫描
    sort(points.begin(), points.end(), cmpX);

    // 维护一个按 Y 坐标排序的活动窗口
    multiset<Point, cmpY> window;
    
    long long minDisSq = INF; 
    double minDis = 3e9; // 动态维护的最短距离 d（用于划定边界）
    
    int left = 0; // 滑动窗口的左边界指针

    // 2. 扫描线开始推进
    for (int i = 0; i < n; i++) {
        // 淘汰：把左边离当前点超过 minDis 的点从窗口中永久踢出
        while (left < i && points[i].x - points[left].x >= minDis) {
            // 注意 multiset 删除元素的坑：只传迭代器，一次只删一个！
            window.erase(window.find(points[left]));
            left++;
        }

        // 检索：在 Y 轴寻找范围 [y_p - d, y_p + d] 
        // 构造一个虚拟点作为 lower_bound 的搜索下界
        long long search_y_lower = points[i].y - (long long)ceil(minDis);
        long long search_y_upper = points[i].y + (long long)ceil(minDis);

        // O(log n) 定位到起始点 (利用 -INF 确保同 Y 时排在最前)
        auto it = window.lower_bound({-INF, search_y_lower});

        // 遍历这最多 6 个点，计算真实距离平方
        while (it != window.end() && it->y <= search_y_upper) {
            long long d_sq = getDistanceSq(points[i], *it);
            if (d_sq < minDisSq) {
                // 发现更短距离，立刻更新平方值和实际距离
                minDisSq = d_sq;
                minDis = sqrt(minDisSq); 
            }
            it++;
        }

        // 把当前点加入活动窗口
        window.insert(points[i]);
    }

    return minDisSq;
}

#ifdef LOCAL_EXPERIMENT
void runSweepLineExperiment() {
    vector<int> scales = {100000, 200000, 500000, 1000000};
    
    ofstream csv("sweep_line_results.csv");
    if (!csv) return;
    csv << "Data_Size,Average_Time_ms\n";

    for (int n : scales) {
        double totalTimeMs = 0;
        string folderName = "test" + to_string(n);
        cout << "开始测试扫描线(Multiset)法: n = " << n << " ..." << endl;

        for (int i = 1; i <= 10; i++) {
            string fileName = folderName + "/in_" + to_string(i) + ".txt";
            ifstream fin(fileName);
            if (!fin) continue;

            int pointsCount;
            fin >> pointsCount;
            vector<Point> points(pointsCount);
            for (int j = 0; j < pointsCount; j++) fin >> points[j].x >> points[j].y;
            fin.close();

            auto start = chrono::high_resolution_clock::now();
            
            long long minDisSq = solveClosestPairSweepLine(points);

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;

            totalTimeMs += duration.count();
            double actualMinDis = sqrt(minDisSq); 
            
            cout << "  文件 " << i << " 耗时: " << fixed << setprecision(2) << duration.count() 
                 << " ms | 最短距离: " << actualMinDis << endl;
        }

        double avgTimeMs = totalTimeMs / 10.0;
        csv << n << "," << fixed << setprecision(2) << avgTimeMs << "\n";
        cout << "=> 规模 n = " << n << " 平均耗时: " << avgTimeMs << " ms\n";
        cout << "---------------------------------------------------\n";
    }
    csv.close();
}
#else
void solveOnline() {
    int n;
    if (!(cin >> n)) return; 
    vector<Point> points(n);
    for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;

    long long minDisSq = solveClosestPairSweepLine(points);
    cout << minDisSq << "\n";
}
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL_EXPERIMENT
    runSweepLineExperiment();
#else
    solveOnline();
#endif

    return 0;
}