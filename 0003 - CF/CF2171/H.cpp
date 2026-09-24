#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
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
            a[i] = max(a[i], v);
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i; i -= i & -i) {
            ans = max(ans, a[i]);
        }
        return ans;
    }
};
 
 
void sol() {
    int n, m;
    cin >> n >> m;
    Fenwick<int> fen(m + 1);
    for (int i = 2; i <= n; i++) {
        vector<pair<int, int>> p;
        for (int j = 0; j <= m - n; j += i) {
            int cnt = 0, x = j + i;
            while (x % i == 0) x /= i, cnt++;
            p.push_back({j, fen.sum(j + 1) + cnt});
        }
        for (auto &[x, y]: p) {
            fen.add(x + 1, y);
        }
    }
    cout << fen.sum(m + 1) << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
    
}
 
/*
aaaaa
bbbb
ccc
 
2 2
2 3
3 3
2 4
3 4
4 4
2 5
3 5
4 5
5 5
2 6
3 6
4 6
5 6
6 6
2 7
3 7
4 7
5 7
6 7
7 7
2 8
3 8
4 8
5 8
6 8
7 8
8 8
2 9
3 9
4 9
5 9
6 9
7 9
8 9
9 9
2 10
3 10
4 10
5 10
6 10
7 10
8 10
9 10
10 10
2 11
3 11
4 11
5 11
6 11
7 11
8 11
9 11
10 11
11 11
2 12
3 12
4 12
5 12
6 12
7 12
8 12
9 12
10 12
11 12
12 12
2 13
3 13
4 13
5 13
6 13
7 13
8 13
9 13
10 13
11 13
12 13
13 13
2 14
3 14
4 14
5 14
6 14
7 14
8 14
9 14
10 14
11 14
cacababababc
*/
