#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> x(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        d[i] = x[i] - x[i - 1];
    }

    vector<int> id(n + 1);
    iota(id.begin(), id.end(), 0);
    

    int m, k;
    cin >> m >> k;
    for (int i = 1; i <= m; i++) {
        int tmp;
        cin >> tmp;
        swap(id[tmp], id[tmp + 1]);
    }

    vector<int> vis(n + 1), td(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vector<int> stk;
        while (!vis[i]) {
            stk.push_back(i);
            vis[i] = 1;
            i = id[i];
        }
        int siz = stk.size();
        int tk = k % siz;
        for (int j = 0; j < stk.size(); j++) {
            td[stk[j]] = d[stk[(j + k) % siz]];
        }
    }

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + td[i];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}