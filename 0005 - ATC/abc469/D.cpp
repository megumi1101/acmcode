#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vis(n + 1);
    vector<int> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        vis[a[i]]++;
        vis[b[i]]++;
    }

    set<pair<int, int>> ans;
    auto get = [&](int x) -> void {
        vector<int> has(n + 1);
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            if (a[i] == x || b[i] == x) continue;
            has[a[i]]++;
            has[b[i]]++;
            cnt++;
        }
        for (int i = 1; i <= n; i++) {
            if (has[i] == cnt && i != x) {
                if (i < x) ans.insert({i, x});
                else ans.insert({x, i});
            }
        }
    };

    int lim = (m + 1) / 2;
    for (int i = 1; i <= n; i++) {
        if (vis[i] >= lim) {
            get(i);
        }
    }
    
    cout << ans.size() << "\n";
}