#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const vector<pair<int, int>> dd = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    // 多源BFS计算距离
    vector<vector<int>> dis(n, vector<int>(m, INF));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                dis[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : dd) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dis[nx][ny] == INF) {
                dis[nx][ny] = dis[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    
    // 收集所有0点
    vector<pair<int, int>> zeros;
    int mxd = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                zeros.emplace_back(i, j);
                if (dis[i][j] > mxd) {
                    mxd = dis[i][j];
                }
            }
        }
    }
    
    if (zeros.empty()) {
        cout << 0 << endl;
        return 0;
    }
    
    // 二分查找
    int l = 0, r = mxd;
    int ans = mxd;
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<pair<int, int>> se;
        for (auto [x, y] : zeros) {
            if (dis[x][y] > mid) {
                se.push_back({x, y});
            }
        }
        if (se.empty()) {
            ans = mid;
            r = mid - 1;
            continue;
        }
        
        // 计算a和b的范围
        vector<int> a, b;
        for (auto [x, y] : se) {
            a.push_back(x + y);
            b.push_back(x - y);
        }
        int siz = a.size();
        
        // 确定合理的数组大小和偏移量
        int max_a = 2 * (n + m);  // a的最大可能值
        int max_b = 2 * (n + m);  // b的最大可能值
        vector<int> da(max_a + 5, 0), db(max_b + 5, 0);
        
        // 更新差分数组
        for (int x : a) {
            int low = max(x - mid, 0);
            int high = min(x + mid, max_a);
            da[low] += 1;
            if (high + 1 <= max_a) da[high + 1] -= 1;
        }
        for (int x : b) {
            int low = max(x - mid, 0);
            int high = min(x + mid, max_b);
            db[low] += 1;
            if (high + 1 <= max_b) db[high + 1] -= 1;
        }
        
        // 还原前缀和
        for (int i = 1; i <= max_a; i++) {
            da[i] += da[i - 1];
        }
        for (int i = 1; i <= max_b; i++) {
            db[i] += db[i - 1];
        }
        
        // 检查是否存在合法点
        bool fg = false;
        for (auto [x, y] : zeros) {
            int tx = x + y;
            int ty = x - y;
            if (tx >= 0 && tx <= max_a && ty >= 0 && ty <= max_b && 
                da[tx] == siz && db[ty] == siz) {
                fg = true;
                break;
            }
        }
        
        if (fg) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}