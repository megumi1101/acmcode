#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {
#define int long long
const int mod = 1e9 + 7;
    struct Mat {
        int a[26][26];
        Mat() {
            memset(a, 0, sizeof(a));
        }
        Mat(int x) {
            memset(a, 0, sizeof(a));
            for (int i = 0; i < 26; i++) a[i][i] = 1;
        }
        Mat(const vector<vector<int>> &b) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    a[i][j] = b[i][j] ^ 1;
                }
            }
        }
        friend Mat operator *(const Mat &m1, const Mat &m2) {
            Mat m3;
            for (int k = 0; k < 26; k++) {
                for (int i = 0; i < 26; i++) {
                    for (int j = 0; j < 26; j++) {
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
    
    int getans(int n, const vector<vector<int>> &b) {
        Mat mat;
        for (int i = 0; i < 26; i++) mat.a[i][0] = 1;
        Mat tmp(b);
        tmp = fap(tmp, n);
        mat = tmp * mat;
        int ans = 0;
        for (int i = 0; i < 26; i++) (ans += mat.a[i][0]) %= mod;
        return ans;
    }

    void sol() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<int>> vis(26, vector<int>(26));
        for (int i = 1; i < s.size(); i++) {
           vis[s[i] - 'a'][s[i - 1] - 'a'] = 1; 
        }
        cout << getans(n - 1, vis);
    }

    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1; 
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}