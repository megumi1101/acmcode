#include <bits/stdc++.h>

using namespace std;

#define int long long

using H = array<int, 3>;

const int N = 1000;

vector<H> hands;
int id[4][4][4];
long double f[N + 1][10][10];
int to[10][3][3];

H get(string s) {
    static const string t = "RSP";

    H c{};
    for (char x : s) {
        c[t.find(x)]++;
    }
    return c;
}

int getid(H a) {
    return id[a[0]][a[1]][a[2]];
}

int score(int a, int b) {
    if (a == b) return 1;
    if ((a + 1) % 3 == b) return 3;
    return 0;
}

void init() {
    for (int r = 0; r <= 3; r++) {
        for (int s = 0; s <= 3; s++) {
            for (int p = 0; p <= 3; p++) {
                if (r + s + p == 3) {
                    id[r][s][p] = hands.size();
                    hands.push_back({r, s, p});
                }
            }
        }
    }

    for (int x = 0; x < 10; x++) {
        for (int a = 0; a < 3; a++) {
            if (hands[x][a] == 0) continue;
            for (int c = 0; c < 3; c++) {
                H h = hands[x];
                h[a]--;
                h[c]++;
                to[x][a][c] = getid(h);
            }
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                long double mx = -1e100L;
                for (int a = 0; a < 3; a++) {
                    if (hands[x][a] == 0) continue;

                    long double mn = 1e100L;
                    for (int b = 0; b < 3; b++) {
                        if (hands[y][b] == 0) continue;

                        long double val = score(a, b);
                        for (int c = 0; c < 3; c++) {
                            for (int d = 0; d < 3; d++) {
                                int nx = to[x][a][c];
                                int ny = to[y][b][d];

                                val += f[k - 1][nx][ny] / 9;
                            }
                        }
                        mn = min(mn, val);
                    }
                    mx = max(mx, mn);
                }
                f[k][x][y] = mx;
            }
        }
    }
}

void sol() {
    int k;
    string a, b;

    cin >> k >> a >> b;

    int x = getid(get(a));
    int y = getid(get(b));

    long double ans;

    if (k <= N) {
        ans = f[k][x][y];
    } else {
        long double d = f[1000][x][y] - f[999][x][y];
        ans = f[1000][x][y] + (k - 1000) * d;
    }

    cout << fixed << setprecision(15) << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}