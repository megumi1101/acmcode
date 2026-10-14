#include <bits/stdc++.h>

using namespace std;

#define int long long

namespace NTT {
    const int P = 985661441, G = 3;
    int power(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = 1LL * res * a % P;
            a = 1LL * a * a % P, b >>= 1;
        }
        return res;
    }
    void ntt(vector<int> &a, int inv) {
        int n = a.size();
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit;
            if (i < j) swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) {
            int wn = power(G, (P - 1) / len);
            if (inv == -1) wn = power(wn, P - 2);
            for (int i = 0; i < n; i += len) {
                int w = 1;
                for (int j = 0; j < len / 2; j++) {
                    int x = a[i + j], y = 1LL * a[i + j + len / 2] * w % P;
                    a[i + j] = x + y;
                    if (a[i + j] >= P) a[i + j] -= P;
                    a[i + j + len / 2] = x - y;
                    if (a[i + j + len / 2] < 0) a[i + j + len / 2] += P;
                    w = 1LL * w * wn % P;
                }
            }
        }
        if (inv == -1) {
            int in = power(n, P - 2);
            for (int &x : a) x = 1LL * x * in % P;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> f(1 << 20);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }
    NTT::ntt(f, 1);
    for (int &x : f) x = NTT::power(x, k);
    NTT::ntt(f, -1);
    for (int i = 0; i < (int)f.size(); i++) {
        if (f[i]) cout << i << " ";
    }
    cout << "\n";
}