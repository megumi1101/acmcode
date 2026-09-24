#include <bits/stdc++.h>
using namespace std;

int n;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void print_board(const vector<vector<int>>& a) {
    cout << "    ";
    for (int j = 1; j <= n; j++) {
        cout << j << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int j = 1; j <= n; j++) {
            cout << (a[i][j] ? '#' : '.') << ' ';
        }
        cout << '\n';
    }
}

int solve(const vector<int>& p) {
    vector<vector<int>> a(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        a[i][p[i]] = 1;
    }

    int t = 0;

    cout << "time = 0\n";
    print_board(a);
    cout << '\n';

    while (true) {
        vector<pair<int, int>> add;

        // 注意必须先把这一秒所有要亮的格子找出来，
        // 然后统一点亮，不能边找边亮
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j]) continue;

                int cnt = 0;

                for (int d = 0; d < 4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];

                    if (x >= 1 && x <= n &&
                        y >= 1 && y <= n) {
                        cnt += a[x][y];
                    }
                }

                if (cnt >= 2) {
                    add.push_back({i, j});
                }
            }
        }

        if (add.empty()) break;

        ++t;

        cout << "time = " << t << '\n';
        cout << "new : ";

        for (auto [x, y] : add) {
            cout << "(" << x << "," << y << ") ";
        }
        cout << '\n';

        for (auto [x, y] : add) {
            a[x][y] = 1;
        }

        print_board(a);
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!a[i][j]) {
                return -1;
            }
        }
    }

    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("out1.txt", "w", stdout);

    cin >> n;

    vector<int> p(n + 1);
    iota(p.begin() + 1, p.end(), 1);

    int id = 0;

    do {
        ++id;

        cout << "========================================\n";
        cout << "Permutation #" << id << " : ";

        for (int i = 1; i <= n; i++) {
            cout << p[i] << ' ';
        }

        cout << "\n========================================\n\n";

        int ans = solve(p);

        cout << "ANSWER = " << ans << "\n\n\n";

    } while (next_permutation(p.begin() + 1, p.end()));

    return 0;
}