#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
 
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> all;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all.push_back(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        all.push_back(b[i]);
    }
    sort(all.begin(), all.end());
 
    int ans = -1;
    int l = 0, r = 2 * n - 1;
 
    auto check = [&](int x) -> bool {
        vector<int> c(n + 1);
        for (int i = 1; i <= n; i++) {
            if (a[i] >= x) c[i]++;
            if (b[i] >= x) c[i]++;
        }
        vector<int> v;
        int c0 = 0, c2 = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i] == 0) {
                if (v.empty() || (!v.empty() && v.back() != 0)) {
                    v.push_back(0);
                    c0++;
                }
            } else if (c[i] == 2) {
                v.push_back(2);
                c2++;
            }
        }
        return c2 > c0;
    };
 
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(all[mid])) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << all[ans] << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
