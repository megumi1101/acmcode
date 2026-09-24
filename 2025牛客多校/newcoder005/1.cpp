#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
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
    vector<vector<int>> dis(n, vector<int>(m, inf));
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
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dis[nx][ny] == inf) {
                dis[nx][ny] = dis[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }

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
        if (mid == 2) cerr << se.size() << "\n";
        vector<int> a, b , da(n + m + 5), db(n * 2 + m * 2 + 5);
        int tmp = n + m;
        for (auto [x, y] : se) {
            a.push_back(x + y);
            b.push_back(x - y);
        }
        int siz = a.size();
        for (int x : a) {
            // if(mid == 2) cerr << x << "\n";
            da[max(x - mid, 0)] += 1;
            da[min(x + mid + 1, n + m - 1)] -= 1;
        }

        for (int x : b) {
            // if(mid == 2) cerr << x << "\n";
            db[max(x - mid + tmp, 0)] += 1;
            db[min(x + mid + 1 + tmp, n + tmp)] -= 1;
        }
        for (int i = 1; i < da.size(); i++) {
            da[i] += da[i - 1];
        }
        // for (int x : da[i])
        for (int i = 1; i < db.size(); i++) {
            db[i] += db[i - 1];
        }
        
        bool fg = 0;
        for (auto [x, y] : zeros) {
            int tx = x + y;
            int ty = x - y;
            if (da[tx] == siz && db[ty + tmp] == siz) {
                fg = 1;
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