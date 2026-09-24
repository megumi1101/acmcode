```cpp
namespace FFT {
    using cd = complex<double>;
    const double PI = acos(-1);

    void fft(vector<cd> &a, int inv) {
        int n = a.size();
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit;
            if (i < j) swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) {
            cd wn(cos(2 * PI / len), sin(2 * PI / len) * inv);
            for (int i = 0; i < n; i += len) {
                cd w(1);
                for (int j = 0; j < len / 2; j++, w *= wn) {
                    cd x = a[i + j], y = a[i + j + len / 2] * w;
                    a[i + j] = x + y, a[i + j + len / 2] = x - y;
                }
            }
        }
        if (inv == -1) for (auto &x : a) x /= n;
    }

    vector<int> mul(vector<int> a, vector<int> b) {
        int need = a.size() + b.size() - 1, n = 1;
        while (n < need) n <<= 1;
        vector<cd> A(a.begin(), a.end()), B(b.begin(), b.end());
        A.resize(n), B.resize(n);
        fft(A, 1), fft(B, 1);
        for (int i = 0; i < n; i++) A[i] *= B[i];
        fft(A, -1);
        vector<int> c(need);
        for (int i = 0; i < need; i++) c[i] = llround(A[i].real());
        return c;
    }
}
```