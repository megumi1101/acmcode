#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    int fujia = 0;
    int lst = 0;
    
    vector<pair<int, int>> p;
    int ct = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) continue;
        fujia -= (a[i] - lst);
        fujia = max(0LL, fujia);
        lst = a[i];
        if (fujia < b[i]) {
            p.push_back({fujia, 1});
            p.push_back({b[i], -1});
            ct += b[i] - fujia;
            fujia = b[i];
            
        }
    }
    

    int now = 0;
    int tim = 0;
    int ans = 2e18;
    sort(p.begin(), p.end());
    for (auto [t, op] : p) {
        ct -= now * (t - tim);
        tim = t;
        now += op;
        ans = min(ans, t * x + ct * y);
    }
    cout << ans << "\n";
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
3 8 4
10 10
14 8
20 10


2
3 5 2
1 3
10 5
20 2
3 100 1
1 5
2 5
3 5


1
3 5 2
1 3
10 5
20 2
*/