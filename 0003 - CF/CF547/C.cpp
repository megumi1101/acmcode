#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> pr, mu, minp;
void init(int n) {
    minp.assign(n + 1, 0);
    mu.assign(n + 1, 0);
    mu[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            pr.push_back(i);
            minp[i] = i;
            mu[i] = -1;
        }
        
        for (auto j : pr) {
            if (j > n / i) break;
            int m = i * j;
            minp[m] = j;
            if (minp[i] == j) {
                mu[m] = 0;
                break;
            } else {
                mu[m] = -mu[i];
            }
        }
    }
}

const int V = 5e5;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    init(V);
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> f(V + 1), muf2(V + 1), op(n + 1, -1);
    
    int ans = 0;
    int c1 = 0;
    while (q--) {
        int x;
        cin >> x;
        int t = op[x] = -op[x];
        x = a[x];
        if (x == 1) c1 += t;

        auto upd = [&](int pre, int &now, int d) {
            ans -= pre * pre * mu[d];
            now = pre + t;
            ans += now * now * mu[d];
        };
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                upd(f[i], f[i], i);
                if (i * i != x) {
                    upd(f[x / i], f[x / i], x / i);
                }
            }
        }

        cout << (ans - c1) / 2 << "\n";
    }   
}

/*
5 6
1 2 3 4 6
1
2
3
4
5
1

*/