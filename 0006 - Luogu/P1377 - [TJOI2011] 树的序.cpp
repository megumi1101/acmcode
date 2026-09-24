#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> p(n + 1);
    vector<int> L(n + 1), R(n + 1);
    vector<int> stk;
    stk.reserve(n);

    for (int i = 1; i <= n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end());
    for (int i = 1; i <= n; i++) {
        int lst = 0;
        while (!stk.empty() && p[stk.back()].second > p[i].second) {
            lst = stk.back();
            stk.pop_back();
        }
        
        if (!stk.empty()) {
            R[stk.back()] = i; 
        }
        L[i] = lst;   
        stk.push_back(i);
    }
    vector<int> vis(n + 1);
    auto dfs = [&](auto &&dfs, int u) -> void {
        cout << u << ' ';
        if (L[u]) dfs(dfs, L[u]);
        if (R[u]) dfs(dfs, R[u]);
    };
    dfs(dfs, stk[0]);
}