#include <bits/stdc++.h>

using namespace std;


#define int long long

void sol() {
    int n, m;
    cin >> n >> m;

    int sum = 0;
    vector a(n, vector(m, 0LL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }

    if (n > m) {
        vector b(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j][i] = a[i][j];
            }
        }
        a.swap(b);
        swap(n, m);
    }

    if (n == 1) {
        bool same = true;
        for (int j = 1; j < m; j++) {
            if (a[0][j] != a[0][0]) same = false;
        }
        cout << (same ? 0 : -1) << "\n";
        return;
    }


    if (a[0][0] != a[n - 1][m - 1]) {
        cout << "-1\n";
        return;
    }

    int den = (n - 1) * (m - 1);
    int num = sum - n * m * a[0][0];
    if (num < 0 || num % den != 0) {
        cout << "-1\n";
        return;
    }

    int y = num / den;
    int x = a[0][0] + y;
    //sum + (n + m - 1) y = n * m * x
    // x = a + y
    // sum + (n + m - 1) y = nma + nmy
    // sum + (n + m - 1 - nm) y = nma
    // (n + m - 1 - nm) y = nma - sum
    //  y = (nma - sum) / (n + m - 1 - nm)


    auto check = [&]() -> bool {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = x - a[i][j];
                if (a[i][j] < 0) return false;
            }
        }
        
        int sum = 0;
        auto get = [&](int s) -> vector<int> {
            vector<int> t;
            for (int i = 0; i < n; i++) {
                int j = s - i;
                if (j >= 0 && j < m) {
                    t.push_back(a[i][j]);
                }
            }
            return t;
        };
        for (int sum = 0; sum + 1 <= n + m - 2; sum++) {
            vector<int> b, c;
            b = get(sum);
            c = get(sum + 1);
            int sumb = accumulate(b.begin(), b.end(), 0LL);
            int sumc = accumulate(c.begin(), c.end(), 0LL);
            if (sumb != sumc) {
                return false;
            }

            // cout << sum << "\n";
            // cout << "b == ";
            // for (int i = 0; i < b.size(); i++) {
            //     cout << b[i] << " ";
            // }
            // cout << "\n";

            // cout << "c == ";
            // for (int i = 0; i < c.size(); i++) {
            //     cout << c[i] << " ";
            // }
            // cout << "\n";

            if (b.size() != c.size()) {
                if (b.size() > c.size()) swap(b, c);
                for (int i = 0; i < (int)b.size(); i++) {
                    if (b[i] < c[i]) return false;
                    b[i] -= c[i];

                    if (c[i + 1] < b[i]) return false;
                    c[i + 1] -= b[i];
                }
            } else {
                for (int i = 0; i < (int)b.size(); i++) {
                    if (b[i] < c[i]) return false;
                    b[i] -= c[i];
                    if (i + 1 < (int)b.size()) {
                        if (c[i + 1] < b[i]) return false;
                        c[i + 1] -= b[i];
                    } else {
                        if (b[i] != 0) return false;
                    }
                }
            }
        }
        return true;
    };

   cout << (check() ? y : -1) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

/*
2
2 3
1 1 1
2 2 1
3 2
1 2
2 2
2 1
*/