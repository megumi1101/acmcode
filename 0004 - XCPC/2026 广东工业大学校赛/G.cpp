#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
 
void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    // if (m == 0) {
    //     cout << "0\n";
    //     return;
    // }
    for (int i = n - 1; i >= 1; i--) a[i] = min(a[i], a[i + 1]);
    int sum = 0;
    int cnt = 0;
    vector<int> p2;
    for (int i = 1; i <= n; i++) {
        if (sum > m) break;
        if (a[i] > cnt) {
            cnt++;
            sum += i;
            p2.push_back(i);
            
            int x = cnt * (2 * n - cnt + 1) / 2;
            if (x >= m && sum <= m) {
                auto p = p2;
                int now = m - sum;
                for (int t = 0; t < p.size(); t++) {
                    int idx = p.size() - t - 1;
                    int iup = n - t;
                    if (iup - p[idx] < now) {
                        now -= iup - p[idx];
                        p[idx] = iup;
                    } else {
                        p[idx] += now;
                        cout << p.size() << "\n";
                        for (auto x : p) cout << x << " ";
                        cout << "\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "-1\n";
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
4 0
4 4 4 4
*/
