#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool fg = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] != -1) {
            if (pos[b[i]]) {
                fg = 1;
            }
            pos[b[i]] = i;
        }
    }
    if (fg) {
        cout << "NO\n";
        return;
    }
 
    vector v (n + 1, vector<pair<int, int>>{});
    for (int i = 1; i <= n; i++) {
        int l = min(n + 1, i + k) - k;
        int r = max(0, i - k) + k;
        if (pos[a[i]]) {
            if (pos[a[i]] < l || pos[a[i]] > r) {
                cout << "NO\n";
                return;
            } 
            l = r = pos[a[i]];
        }
        v[l].push_back({r, a[i]});
    }
 
    set<pair<int, int>> s;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto x : v[i]) s.insert(x);
        while (!s.empty()) {
            auto it = s.begin();
            if (it -> first < i) {
                s.erase(it);
            } else {
                break;
            }
        }
        if (s.empty()) {
            cout << "NO\n";
            return;
        }
        auto it = s.begin();
        c[i] = it -> second;
        s.erase(it);
    }
    cout << "YES\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
