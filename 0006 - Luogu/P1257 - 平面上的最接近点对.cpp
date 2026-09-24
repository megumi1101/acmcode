#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// ==========================================
// 💡 开关在这里：
// 本地做实验时保留下面这行；线上提交到 OJ 时，请将下面这行注释掉！
// #define LOCAL_EXPERIMENT 
// ==========================================

struct Point {
    long long x, y;
};

inline long long getDistanceSq(const Point& a, const Point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

#ifdef LOCAL_EXPERIMENT
// ----------------- 本地实验模式 -----------------
void runBruteForceExperiment() {
    // 测试从 10万 到 100万 的规模
    vector<int> scales = {100000, 300000, 500000, 700000, 1000000};
    
    ofstream csv("brute_force_results.csv");
    if (!csv) {
        cerr << "无法创建 CSV 文件！\n";
        return;
    }
    csv << "Data_Size,Average_Time_ms\n";

    for (int n : scales) {
        double totalTimeMs = 0;
        string folderName = "test" + to_string(n);
        cout << "开始测试规模: n = " << n << " ..." << endl;

        // 【修改点】只测 2 组
        for (int i = 1; i <= 2; i++) {
            string fileName = folderName + "/in_" + to_string(i) + ".txt";
            ifstream fin(fileName);
            
            if (!fin) {
                cerr << "  找不到文件: " << fileName << "\n";
                continue;
            }

            int pointsCount;
            fin >> pointsCount;
            vector<Point> points(pointsCount);
            for (int j = 0; j < pointsCount; j++) {
                fin >> points[j].x >> points[j].y;
            }
            fin.close();

            auto start = chrono::high_resolution_clock::now();

            long long minDisSq = 9e18; 
            int best_i = -1, best_j = -1;

            for (int u = 0; u < pointsCount; u++) {
                for (int v = u + 1; v < pointsCount; v++) {
                    long long disSq = getDistanceSq(points[u], points[v]);
                    if (disSq < minDisSq) {
                        minDisSq = disSq;
                        best_i = u;
                        best_j = v;
                    }
                }
            }

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;

            totalTimeMs += duration.count();
            double actualMinDis = sqrt(minDisSq);
            
            cout << "  文件 " << i << " 耗时: " << fixed << setprecision(2) << duration.count() 
                 << " ms | 最短距离: " << actualMinDis << endl;
        }

        // 【修改点】除以 2.0 算平均时间
        double avgTimeMs = totalTimeMs / 2.0;
        csv << n << "," << fixed << setprecision(2) << avgTimeMs << "\n";
        cout << "=> 规模 n = " << n << " 的 2 组平均耗时: " << avgTimeMs << " ms\n";
        cout << "---------------------------------------------------\n";
    }

    csv.close();
    cout << "所有测试完成，结果已保存至 brute_force_results.csv\n";
}

#else
// ----------------- 线上评测 (OJ) 模式 -----------------
void solveOnline() {
    int n;
    // 线上单组数据读取
    if (!(cin >> n)) return; 
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    long long minDisSq = 9e18; 
    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) {
            long long disSq = getDistanceSq(points[u], points[v]);
            if (disSq < minDisSq) {
                minDisSq = disSq;
            }
        }
    }
    
    // 线上通常只需要输出最终距离。保留 4 位小数，具体保留几位请根据题目要求修改
    cout << fixed << setprecision(4) << sqrt(minDisSq) << "\n";
}
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL_EXPERIMENT
    // 执行本地实验
    runBruteForceExperiment();
#else
    // 执行线上单组评测
    solveOnline();
#endif

    return 0;
}