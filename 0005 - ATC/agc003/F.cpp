// AtCoder user: lnxbb
// Contest: agc003
// Problem: agc003_f
// Submission: https://atcoder.jp/contests/agc003/submissions/75466433
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1; a = a * a % mod;
    }
    return res;
}

template <int N>
struct Mat {
    array<array<int, N>, N> a{}; 

    Mat() = default;

    Mat(initializer_list<initializer_list<int>> lst) {
        int r = 0;
        for (const auto& row : lst) {
            if (r >= N) break;
            int c = 0;
            for (const auto& val : row) {
                if (c >= N) break;
                a[r][c] = val;
                c++;
            }
            r++;
        }
    }

    static Mat identity() {
        Mat res;
        for (int i = 0; i < N; i++) {
            res.a[i][i] = 1;
        }
        return res;
    }

    friend Mat operator*(const Mat& A, const Mat& B) {
        Mat C;
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                if (!A.a[i][k]) continue; 
                for (int j = 0; j < N; j++) {
                    C.a[i][j] = (C.a[i][j] + 1LL * A.a[i][k] * B.a[k][j]) % mod;
                }
            }
        }
        return C;
    }

    Mat pow(long long b) const {
        Mat res = Mat::identity();
        Mat a = *this; 
        while (b) {
            if (b & 1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
};


signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    for (auto &ss : s) cin >> ss;
    int t0 = 0, t1 = 0;

    int sum = 0;
    for (auto ss : s) for (auto c : ss) if (c == '#') sum++;
    for (int i = 0; i < n; i++) {
        if (s[i][0] == '#' && s[i][m - 1] == '#') t0++; 
    }

    for (int j = 0; j < m; j++) {
        if (s[0][j] == '#' && s[n - 1][j] == '#') t1++;
    }

    if ((t0 && t1) || (k == 0) || (k == 1)) {
        cout << "1\n";
    } else if (!t0 && !t1) {
        cout << fap(sum, k - 1) << "\n";
    } else {

        k--;
        int y = max(t0, t1);
        int x = 0;

        int ans = fap(sum, k);
        if (t0) {
            for (int i = 0; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (s[i][j] == s[i][j - 1] && s[i][j] == '#') {
                        x++;
                    }
                }
            }
        } else {
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (s[i][j] == s[i - 1][j] && s[i][j] == '#') {
                        x++;
                    }
                }
            }
        }

        Mat<2> A{{sum, 1}, {0, y}};
        A = A.pow(k - 1);
        Mat<2> B{{1}, {y}};
        A = A * B;
        int t = A.a[0][0] * x % mod;
        ans = ans + mod - t;
        ans %= mod;
        cout << ans << "\n";
    }
}