#include <bits/stdc++.h>

using namespace std;

#define int long long

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int inv(int a, int mod) {
    int x, y;
    exgcd(a, mod, x, y);
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

int norm(int x, int n) {
    x %= n;
    if (x < 0) x += n;
    return x;
}

void sol1() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (auto &s : a) cin >> s;

    int xr, xc;
    cin >> xr >> xc;
    --xr, --xc;

    int w = 0;
    int sr = 0, sc = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#') {
                w++;
                sr = (sr + i) % n;
                sc = (sc + j) % n;
            }
        }
    }

    int dr = norm((w % n) * xr - sr, n);
    int dc = norm((w % n) * xc - sc, n);

    if (dr == 0 && dc == 0) {
        cout << "1 1 1 1\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != '#') continue;
            int ni = (i + dr) % n;
            int nj = (j + dc) % n;

            if (a[ni][nj] == '.') {
                cout << i + 1 << " " << j + 1 << " " << ni + 1 << " " << nj + 1 << "\n";
                return;
            }
        }
    }
}

void sol2() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (auto &s : a) cin >> s;

    int w = 0;
    int sr = 0, sc = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#') {
                w++;
                sr = (sr + i) % n;
                sc = (sc + j) % n;
            }
        }
    }

    int iw = inv(w % n, n);
    int r = sr * iw % n;
    int c = sc * iw % n;
    cout << r + 1 << " " << c + 1 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string type;
    cin >> type;
    int t;
    cin >> t;
    while (t--) {
        if (type == "first") sol1();
        else sol2();
    }
}