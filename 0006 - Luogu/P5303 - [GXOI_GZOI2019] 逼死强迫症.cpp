#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {
#define int long long
const int mod = 1e9 + 7;
    struct Mat {
        int a[5][5];
        Mat() {
            memset(a, 0, sizeof(a));
        }
        Mat(int x) {
            memset(a, 0, sizeof(a));
            for (int i = 0; i < 5; i++) a[i][i] = 1;
        }
        Mat(int x, int y) {
            int b[5][5] ={{1, 1, 2, 0, 1}, {1, 0, 0, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 1}};
            for (int i = 0; i < 5; i++)
                for (int j = 0; j < 5; j++)
                    a[i][j] = b[i][j];
        }
        friend Mat operator *(const Mat &m1, const Mat &m2) {
            Mat m3;
            for (int k = 0; k < 5; k++) {
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        (m3.a[i][j] += m1.a[i][k] * m2.a[k][j] % mod) %= mod;
                    }
                }
            }
            return m3;
        }
    };

    Mat fap(Mat a, int b) {
        Mat res(1);
        while (b) {
            if (b & 1) res = res * a;
            a = a * a; b >>= 1;
        }
        return res;
    }
    
    int getans(int n) {
        if (n <= 2) return 0;
        if (n == 3) return 2;
        Mat mat;
        mat.a[0][0] = 6;
        mat.a[1][0] = 2;
        mat.a[2][0] = 5;
        mat.a[3][0] = 3;
        mat.a[4][0] = mod - 2;
        Mat tmp(1, 1);
        tmp = fap(tmp, n - 4);
        mat = tmp * mat;
        return mat.a[0][0];
    }

    void sol() {
        int n;
        cin >> n;
        cout << getans(n) << "\n";
    }

    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1; 
        cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}