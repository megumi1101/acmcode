// QOJ user: lnxbb
// Contest: 2022 ç¬?7å±ŠICPCè¥¿å®‰ç«?// Problem: #5122. Strange Sum (5122)
// Submission: https://qoj.ac/submission/1659571
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
const int inf = 1e9;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        sort(a.rbegin(), a.rend());
        int ans = max({0, a[0], a[0] + a[1]});
        cout << ans;
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}
</code>