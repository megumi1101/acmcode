#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 5, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }
    
    T getsum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    //查找满足前缀和 <= k 的最大位置
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i] <= k) {
                x += i;
                cur = cur + a[x];
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> op(n + 1);
    vector a(3, vector(n + 1, 0));
    vector<int> b(n + 1);
    for (int op = 0; op < 3; op++) {
        for (int i = 1; i <= n; i++) {
            cin >> a[op][i];
        }
    }

    auto geti = [n](vector<int> v) {
        Fenwick<int> fen(n + 1);
        int res = 0;
        for (auto i : v) {
            res += fen.getsum(i + 1, n);
            fen.add(i, 1);
        }
        return (res & 1);
    };

    vector<int> v0, v1;
    for (int i = 1; i <= n; i++) {
        if (a[0][i] > a[2][i]) {
            swap(a[0][i], a[2][i]);
            op[i] = 1;
        }
        if (a[0][i] + 1 != a[1][i] || a[1][i] + 1 != a[2][i] || a[2][i] % 3 != 0) {
            cout << "No\n";
            return 0;
        }
        b[i] = a[2][i] / 3;
        if (i & 1) v1.push_back(b[i]);
        else v0.push_back(b[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        if ((b[i] & 1) != (i & 1)) {
            cout << "No\n";
            return 0;
        }
    }

    
    
    int cnt0 = geti(v1), cnt1 = geti(v0);
    for (int i = 1; i <= n; i++) {
        if (op[i] == 1) {
            if (i & 1) cnt1 ^= 1;
            else cnt0 ^= 1;
        }
    }
    if (cnt0 || cnt1) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
}