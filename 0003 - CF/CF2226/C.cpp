#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int mx = 0;
 
    multiset<int> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        s.insert(a[i]);
    }
    vector<priority_queue<int, vector<int>, greater<int>>> used(mx + 5);
 
    int ans = 0;
    for (int now = 0; now <= n; now++) {
        if (auto it = s.find(now); it != s.end()) {
            s.extract(it);
            ans++;
            continue;
        }
 
        if (!used[now].empty()) {
            int u = used[now].top();
            auto it = s.lower_bound(2 * u + 1);
            if (it != s.end()) {
                used[*it].push(u);
                used[now].pop();
                ans++;
                s.extract(it);
                continue;
            }
        }
 
        if (auto it = s.lower_bound(2 * now + 1); it != s.end()) {
            used[*it].push(now);
            s.extract(it);
            ans++;
            continue;
        }
        break;
    }
 
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
