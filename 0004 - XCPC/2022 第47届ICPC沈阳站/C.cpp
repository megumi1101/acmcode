// QOJ user: lnxbb
// Contest: 2022 ç¬?7å±ŠICPCæ²ˆé˜³ç«?// Problem: #5435. Clamped Sequence (5435)
// Submission: https://qoj.ac/submission/1652315
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 1e9 + 10000;
    void sol() {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        int ans = 0;
        for (auto &i : a) cin >> i;
        for (auto x : a) {
            int l = x;
            int r = x + d;
            auto b = a;
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (b[i] < l) b[i] = l;
                if (b[i] > r) b[i] = r;
                if (i) res += abs(b[i] - b[i - 1]);
                 
            }
            ans = max(ans, res);
        } 
        for (auto x : a) {
            int r = x;
            int l = x - d;
            auto b = a;
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (b[i] < l) b[i] = l;
                if (b[i] > r) b[i] = r;
                if (i) res += abs(b[i] - b[i - 1]);
                 
            }
            ans = max(ans, res);
        } 
        cout << ans << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
</code>