#include <bits/stdc++.h>

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    auto getnxt = [&](int lst, int a, int msk) -> int {
        int lstb = -1;
        for (int bit = 29; bit >= 0; bit--) {
            int x = (a >> bit) & 1;
            int y = (lst >> bit) & 1;

            if ((msk >> bit) & 1) {
                if (y == 0) lstb = bit;
            } else {
                if (x == y) continue;
                if (x == 1 && y == 0) {
                    int res = 0;
                    for (int j = 29; j > bit; j--) {
                        if ((lst >> j) & 1)
                            res |= (1 << j);
                    }

                    res |= (1 << bit);
                    for (int j = bit - 1; j >= 0; j--) {
                        if (!((msk >> j) & 1) && ((a >> j) & 1))
                            res |= (1 << j);
                    }
                    return res;
                } else if (x == 0 && y == 1) {
                    if (lstb == -1)
                        return -1;
                    int res = 0;
                    for (int j = 29; j > lstb; j--) {
                        if ((lst >> j) & 1)
                            res |= (1 << j);
                    }

                    res |= (1 << lstb);
                    for (int j = lstb - 1; j >= 0; j--) {
                        if (!((msk >> j) & 1) && ((a >> j) & 1))
                            res |= (1 << j);
                    }
                    return res;
                }
            }
        }
        return lst;
    };

    auto check = [&](int t) -> bool {
        auto b = a;
        for (int i = 1; i <= n; i++) {
            b[i] = getnxt(b[i - 1], b[i], t);
            if (b[i] == -1) return 0;
        }
        return 1;
    };

    int ans = 0;

    for (int bit = 29; bit >= 0; bit--) {
        int t = ans | ((1 << bit) - 1);
        if (!check(t)) {
            ans |= (1 << bit);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}

/*
6
2
3 0
2
7 4
2
6 1
3
4 6 3
3
1 2 3
4
1 0 6 5
*/