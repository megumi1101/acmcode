#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    // 1. 优化 I/O 常数
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k;
    if (!(cin >> n >> k)) return 0;
 
    // 2. 预处理浮点除法：将除法转化为乘法
    vector<double> p_win(n + 1);
    vector<double> p_lose(n + 1);
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        p_win[i] = val / 100.0;
        p_lose[i] = 1.0 - p_win[i];
    }
 
    // 3. 核心优化：交换维度 g[win][i]，使内层循环对 i 的访问在内存上连续（缓存友好）
    vector<vector<double>> g(k + 1, vector<double>(n + 1, 0.0));
    for (int i = 1; i <= n; i++) g[0][i] = 1.0;
 
    double up[35][35] = {0};
    
    for (int turn = 0; turn < k; turn++) {
        for (int win = 0; win <= turn; win++) {
            double sum = 0.0;
            double cur_up = 0.0;
            
            // 这里的内层循环经过维度交换后，可以被编译器自动向量化 (SIMD)
            for (int i = 1; i <= n; i++) {
                sum += g[win][i];
                cur_up += g[win][i] * p_win[i];
            }
            if (sum > 1e-8) {
                up[turn][win] = cur_up / sum;
            }
        }
 
        // 4. 原地滚动更新：干掉每次 turn 循环内部的 vector ng 分配
        // 倒序遍历 win 即可实现原地更新 g 数组，省去大量 new/delete 开销
        for (int win = turn; win >= 0; win--) {
            for (int i = 1; i <= n; i++) {
                g[win + 1][i] += g[win][i] * p_win[i];
                g[win][i] *= p_lose[i]; // 注意：这一步必须在更新完 win + 1 后进行
            }
        }
    }
 
    // k 最大只有 30 左右，这一段 DP 常数极小，用普通多维数组即可
    double f[35][35] = {0};
    for (int i = 0; i <= k; i++) f[k][i] = 1000.0;
    
    for (int turn = k; turn > 0; turn--) {
        for (int win = 0; win < turn; win++) {
            double t = up[turn - 1][win];
            f[turn - 1][win] = max(2 * t * f[turn][win + 1], 
                                   t * f[turn][win + 1] + (1.0 - t) * f[turn][win]);
        }
    }
 
    cout << fixed << setprecision(8) << f[0][0] - 1000.0 << "\n";
    return 0;
}
