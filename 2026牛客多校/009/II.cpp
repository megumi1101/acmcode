#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));

    // 第 i 行第 p[i] 列初始亮
    for (int i = 1; i <= n; i++) {
        a[i][p[i]] = 1;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    auto print = [&](int t) {
        cout << "time = " << t << '\n';

        // 输出列号
        cout << "    ";
        for (int j = 1; j <= n; j++) {
            cout << setw(2) << j << ' ';
        }
        cout << '\n';

        for (int i = 1; i <= n; i++) {
            cout << setw(2) << i << ": ";
            for (int j = 1; j <= n; j++) {
                cout << ' ' << (a[i][j] ? '#' : '.') << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    };

    int t = 0;
    print(t);

    while (true) {
        vector<pair<int, int>> add;

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (a[x][y]) continue;

                int cnt = 0;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 1 || nx > n || ny < 1 || ny > n)
                        continue;

                    cnt += a[nx][ny];
                }

                if (cnt >= 2) {
                    add.push_back({x, y});
                }
            }
        }

        // 没有新的灯亮了
        if (add.empty()) break;

        ++t;

        cout << "new at time " << t << ": ";
        for (auto [x, y] : add) {
            cout << "(" << x << "," << y << ") ";
            a[x][y] = 1;
        }
        cout << "\n\n";

        print(t);
    }

    bool all = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!a[i][j]) all = false;
        }
    }

    if (all) {
        cout << "ANSWER = " << t << '\n';
    } else {
        cout << "ANSWER = -1\n";

        cout << "unlit:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!a[i][j]) {
                    cout << "(" << i << "," << j << ") ";
                }
            }
        }
        cout << '\n';
    }

    return 0;
}