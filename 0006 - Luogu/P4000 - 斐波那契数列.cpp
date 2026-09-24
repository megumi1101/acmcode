#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define ll long long
    mt19937_64 gen((random_device())());
    string s;
    int p;
    map<ll, ll> mp;
    struct Mat {
        unsigned int a[2][2];
        Mat() {
            a[0][0] = a[1][1] = 0;
            a[0][1] = a[1][0] = 0;
        }
        Mat(int a1, int a2, int a3, int a4) {
            a[0][0] = a1;
            a[0][1] = a2;
            a[1][0] = a3;
            a[1][1] = a4;
        }
        friend Mat operator *(const Mat &m1, const Mat &m2) {
            Mat m3;
            for (int k = 0; k < 2; k++) {
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        (m3.a[i][j] += (ll)m1.a[i][k] * m2.a[k][j] % p) %= p;
                    }
                }
            }
            return m3;
        }
    };

    Mat fap(Mat a, ll b) {
        Mat res(1, 0, 0, 1);
        while (b) {
            if (b & 1) res = res * a;
            a = a * a; b >>= 1;
        }
        return res;
    }
    
    ll f(ll n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        Mat m1(1, 1, 1, 0);
        Mat m2(1, 0, 0, 0);
        m1 = fap(m1, n - 1);
        m1 = m1 * m2;
        return (ll)m1.a[0][0];
    }

    void sol() {
        cin >> s >> p;
        uniform_int_distribution<long long> dis(0, (ll)p * 12);
        ll len = 0;
        ll res = 0;
        if (p == 1) {
            cout << "0";
            return;
        }
        while (len == 0) {
            res++;
            ll x = dis(gen);
            ll y = f(x) << 31 | f(x + 1);
            if (mp.find(y) != mp.end()) {
                len = abs(x - mp[y]);
            }
            mp[y] = x;
        }
        // cerr << res;
        ll n = 0;
        for (char c : s) {
            n *= 10;
            n += c - '0';
            n %= len;
        }
        cout << f(n);
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}