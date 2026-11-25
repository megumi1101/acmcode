#include <bits/stdc++.h>

using namespace std;

#define int long long
const int inf = 1e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> c(n + 1), v(n + 1);
    // cost vaule 
    vector<vector<int>> p(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> v[i];
        p[c[i]].push_back(i);
        sum += v[i];
    }

    vector<int> ans(m + 1);
    vector dp(n + 1, vector(m + 1, sum));
    for (int i = m; i >= 0; i--) {
        int t = p[i].size();
        
        for (auto x : p[i]) {

        }
    }
}

/*
3 4
1 3
2 5
4 8


*/