#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    
    vector<pair<int, int>> stk;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];

        int lst = 0;
        while (!stk.empty()) {
            auto[x, y] = stk.back();
            if (y == b[i]) {
                a[i] -= lst;
                a[i] += x;
                stk.pop_back();
                continue;
            }

            if (a[i] > x) {
                stk.pop_back();
                lst = x;
            } else {
                break;
            }
        }

        stk.push_back({a[i], b[i]});
        cout << stk[0].first << " ";
    }
    cout << "\n";
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
1
6
4 6
1 3
4 6
4 0
7 6
6 3
*/