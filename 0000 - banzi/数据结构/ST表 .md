```cpp
template <typename T, auto op = [](T a, T b) { return min(a, b); }>
struct ST {
    vector<vector<T>> t;

    ST() {}
    ST(const vector<T>& a) { build(a); }

    void build(const vector<T>& a) {
        int n = a.size() - 1;
        int K = __lg(n) + 1;
        t.assign(n + 1, vector<T>(K));

        for (int i = 1; i <= n; i++)
            t[i][0] = a[i];

        for (int j = 1; j < K; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                t[i][j] = op(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
    }

    T query(int l, int r) {
        int k = __lg(r - l + 1);
        return op(t[l][k], t[r - (1 << k) + 1][k]);
    }
};
```