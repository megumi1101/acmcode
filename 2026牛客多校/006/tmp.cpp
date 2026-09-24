#include <bits/stdc++.h>

using namespace std;

#define int long long

using u32 = unsigned int;

vector<pair<int, int>> dp(64, {-1, -1});
int x;

pair<int, int> dfs(int bit, bool lim) {
    if (bit < 0) {
        return {1, 0};
    }

    if (!lim && dp[bit] != pair<int, int>{-1, -1}) {
        return dp[bit];
    }

    int up = 1;
    if (lim) {
        up = (x >> bit) & 1;
    }


    int res0 = 0;
    int res1 = 0;
    for (int i = 0; i <= up; i++) {
        auto[ct, sum] = dfs(bit - 1, lim && i == up);
        res0 += ct;
        res1 += ct * i + sum;
    }

    if (lim) {
        return {res0, res1};
    } else {
        return dp[bit] = {res0, res1};
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> x;
    auto [ct, sum] = dfs(61, 1);
    cout << ct << " " << sum << "\n";
}

/*
3
5
bca a zz ab c
4
ba b aa aba
3
az za m
*/