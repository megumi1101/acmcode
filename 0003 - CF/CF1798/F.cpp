#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<pair<int, int>> s(k);
    for (int i = 0; i < k; ++i) {
        cin >> s[i].first;
        s[i].second = i;
    }
    sort(s.rbegin(), s.rend());

    vector<bool> vis(n);
    vector<vector<int>> ans(k);

    auto get = [&](int m, int id) {
        constexpr int B = 201;  // 本题 n <= 200。
        vector<bitset<B>> dp(m + 1);
        vector pre(m + 1, vector<int>(m, -1));
        bitset<B> mask;
        for (int r = 0; r < m; ++r) mask.set(r);
        dp[0].set(0);

        int seen = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            int x = a[i] % m;
            ++seen;
            for (int cnt = min(m, seen); cnt >= 1; --cnt) {
                // 将余数统一加 x，即在低 m 位内循环左移 x 位。
                auto shifted = ((dp[cnt - 1] << x)
                              | (dp[cnt - 1] >> (m - x))) & mask;
                auto fresh = shifted & ~dp[cnt];
                dp[cnt] |= shifted;

                // 只枚举新状态，每个 (cnt, r) 最多记录一次。
                for (size_t r = fresh._Find_first(); r < size_t(m);
                     r = fresh._Find_next(r))
                    pre[cnt][r] = i;
            }
            if (dp[m][0]) break;
        }

        // 从目标状态倒推，每次删去最后选的一袋。
        int r = 0;
        for (int cnt = m; cnt >= 1; --cnt) {
            int i = pre[cnt][r];
            vis[i] = true;
            ans[id].push_back(a[i]);
            r = (r - a[i] % m + m) % m;
        }
    };

    // 最大班级留到最后，其余班级依次分配。
    for (int i = 1; i < k; ++i)
        get(s[i].first, s[i].second);

    auto [m, id] = s[0];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        ans[id].push_back(a[i]);
        sum = (sum + a[i]) % m;
    }
    int extra = m - sum;
    ans[id].push_back(extra);

    cout << extra << '\n';
    for (const auto& v : ans) {
        for (int x : v) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
