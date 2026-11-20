#include <bits/stdc++.h>

using namespace std;

const int M = 5e5;

#define debug(x) cerr << #x << " == " << x << "\n";

vector<int> f(M + 1, -1);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    f[1] = 1;

    auto get = [&](this auto &&self, int m) -> int {
        if (f[m] != -1) return f[m];
        int res = 1e9;
        for (int i = 1; i * i <= m; i += 2) {
            if (m % i == 0) {
                int x = i;
                int y = m / i;
                if (x > 2) {
                    res = min(res, self(x - 2) + self(y));
                }
                if (y > 2) {
                    res = min(res, self(x) + self(y - 2));
                }
            }
        }
        return f[m] = res;
    };
    
    for (int i = 3; i <= M - 1; i += 2) {
        if (f[i] != -1 || i % 2 == 0) continue;
        get(i);
    }

    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        cout << f[m] << "\n";
    }
}