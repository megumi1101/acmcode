#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 64;
const int inf = 1e9;
struct Mat {
    array<array<int, 64>, 64> a{}; 

    Mat() = default;

    static Mat identity() {
        Mat res;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                res.a[i][j] = -inf;
        for (int i = 0; i < N; i++) {
            res.a[i][i] = 0;
        }
        return res;
    }

    friend Mat operator*(const Mat& A, const Mat& B) {
        Mat C;
        for (int i = 0; i < 64; i++) {
            for (int k = 0; k < 64; k++) { 
                for (int j = 0; j < 64; j++) {
                    C.a[i][j] = max(C.a[i][j], A.a[i][k] + B.a[k][j]);
                }
            }
        }
        return C;
    }
};

Mat fap(Mat a, int b) {
    Mat res;
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

void sol() {
    int n, m, k, R;
    cin >> n >> m >> k >> R;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
    }
    Mat A;
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            int cost = 0;
            int val = 0;
            for (int bit = 0; bit < n; bit++) {
                if ((i >> bit) & 1) {
                    cost += c[bit];
                    val += a[bit];
                    if ((j >> bit) & 1) {
                        cost += k;
                    }
                }
            }

            if (cost <= m) {
                A.a[i][j] = val;
            } else {
                A.a[i][j] = -inf;
            }
        }
    }

    A = fap(A, R);
    Mat B;
    B = A * B;
    int ans = -inf;
    for (int i = 0; i < N; i++) {
        ans = max(ans, B.a[i][0]);
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}

/*
1
3 7 1 5
59 3
13 2
81 4
*/