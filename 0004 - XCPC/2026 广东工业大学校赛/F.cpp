#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
void sol() {
    int n, X;
    cin >> n >> X;
    vector<int> k(n + 1), h(n + 1);
    int sum = 0;
    int sumh = 0;
    for (int i = 1; i <= n; i++) {
        cin >> k[i] >> h[i];
        sum += k[i] * h[i] * h[i];
        sumh += h[i];
    }
    if (sum <= X) {
        cout << "0\n";
        return;
    }
 
    int l = 1, r = 1e18;
    auto get = [&] (int x) -> pair<int, int> {
        // cerr << x << "\n";
        int res = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int up = min((x / k[i] + 1) / 2, h[i]);
            res += k[i] * up * up;
            cnt += up;
        }
        return {res, cnt};
    };
 
    int ans = 0;
    while (l <= r) {
        int mid = (l +  r) >> 1;
        if (get(mid).first >= X) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
 
    auto[t1, t2] = get(ans - 1);
    // cerr << t1 << " " << t2 << "\n";
    t2 += (X - t1) / ans;
    cout << sumh - t2 << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
1
4 50
3 3
1 4
2 2
5 1
*/
