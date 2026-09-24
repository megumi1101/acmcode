#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>
#include <string>
#include <iomanip>
#include <random>
#include <numeric>
// 💡 引入 GCC 内置的 PBDS 扩展库
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// ==========================================
// 💡 评测模式开关
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(pair<long long, long long> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

long long solveClosestPairRandomSieve(const vector<Point>& points) {
    int n = points.size();
    if (n < 2) return 0;

    vector<int> S(n);
    iota(S.begin(), S.end(), 0);

    double last_d = 2e9; 
    mt19937 rnd(random_device{}());

    // 🛡️ 核心优化：预分配静态链表数组，大小固定为 n
    vector<int> nxt(n, -1);
    
    // 🛡️ 核心优化：使用 PBDS 开放寻址哈希表，值只存头节点索引
    gp_hash_table<pair<long long, long long>, int, custom_hash> grid_head;

    while (S.size() > 1) {
        int r = rnd() % S.size();
        int p = S[r];

        long long min_d_sq = -1;
        for (int idx : S) {
            if (idx == p) continue;
            long long d_sq = getDistanceSq(points[p], points[idx]);
            if (min_d_sq == -1 || d_sq < min_d_sq) {
                min_d_sq = d_sq;
            }
        }

        if (min_d_sq == 0) return 0;

        double d = sqrt(min_d_sq);
        last_d = d;
        double l = d / 3.0;

        // 清空哈希表，PBDS 的 clear 只重置状态位，极快
        grid_head.clear();
        
        // 建立静态链表
        for (int idx : S) {
            long long gx = floor(points[idx].x / l);
            long long gy = floor(points[idx].y / l);
            pair<long long, long long> key = {gx, gy};
            
            auto it = grid_head.find(key);
            if (it == grid_head.end()) {
                grid_head[key] = idx;
                nxt[idx] = -1; // 链表尾部
            } else {
                nxt[idx] = it->second; // 头插法
                grid_head[key] = idx;
            }
        }

        vector<int> next_S;
        // 预分配容量，避免 push_back 扩容开销
        next_S.reserve(S.size()); 

        for (int idx : S) {
            long long gx = floor(points[idx].x / l);
            long long gy = floor(points[idx].y / l);
            
            int count = 0;
            for (long long dx = -1; dx <= 1; ++dx) {
                for (long long dy = -1; dy <= 1; ++dy) {
                    auto it = grid_head.find({gx + dx, gy + dy});
                    if (it != grid_head.end()) {
                        // 遍历静态链表
                        int curr = it->second;
                        while (curr != -1) {
                            count++;
                            curr = nxt[curr];
                        }
                    }
                }
            }
            
            if (count > 1) {
                next_S.push_back(idx);
            }
        }

        if (next_S.size() == S.size()) break; 
        S = next_S;
    }

    // ================= 第二阶段：终局之战 =================
    double L = last_d; 
    grid_head.clear();
    
    // 把所有初始点重新放入网格，复用静态链表
    for (int i = 0; i < n; ++i) {
        long long gx = floor(points[i].x / L);
        long long gy = floor(points[i].y / L);
        pair<long long, long long> key = {gx, gy};
        
        auto it = grid_head.find(key);
        if (it == grid_head.end()) {
            grid_head[key] = i;
            nxt[i] = -1;
        } else {
            nxt[i] = it->second;
            grid_head[key] = i;
        }
    }

    long long global_min_sq = -1;
    for (int i = 0; i < n; ++i) {
        long long gx = floor(points[i].x / L);
        long long gy = floor(points[i].y / L);

        for (long long dx = -1; dx <= 1; ++dx) {
            for (long long dy = -1; dy <= 1; ++dy) {
                auto it = grid_head.find({gx + dx, gy + dy});
                if (it != grid_head.end()) {
                    int j = it->second;
                    while (j != -1) {
                        if (i < j) {
                            long long d_sq = getDistanceSq(points[i], points[j]);
                            if (global_min_sq == -1 || d_sq < global_min_sq) {
                                global_min_sq = d_sq;
                            }
                        }
                        j = nxt[j];
                    }
                }
            }
        }
    }

    return global_min_sq;
}

#ifdef LOCAL_EXPERIMENT
void runRandomSieveExperiment() {
    vector<int> scales = {100000, 300000, 500000, 700000, 1000000};
    
    ofstream csv("random_sieve_results.csv");
    if (!csv) return;
    csv << "Data_Size,Average_Time_ms\n";

    for (int n : scales) {
        double totalTimeMs = 0;
        string folderName = "test" + to_string(n);
        cout << "开始测试随机筛法 O(n): n = " << n << " ..." << endl;

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
            
            long long minDisSq = solveClosestPairRandomSieve(points);

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

    long long minDisSq = solveClosestPairRandomSieve(points);
    cout << fixed << setprecision(4) << sqrt(minDisSq) << "\n";
}
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL_EXPERIMENT
    runRandomSieveExperiment();
#else
    solveOnline();
#endif

    return 0;
}