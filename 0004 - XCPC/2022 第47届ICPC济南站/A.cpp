// QOJ user: lnxbb
// Contest: 2022 Á¨?7Â±äICPCÊµéÂçóÁ´?// Problem: #5137. Tower (5137)
// Submission: https://qoj.ac/submission/1605468
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
const int inf = 1e9 + 10000;
    void sol() {
        auto tun = [&] (int a, int x) -> int {
            int ans = abs(x - a);
            int cnt = 0;
            while (a) {
                ans = min(ans, cnt + abs(x - a));
                if (a < x) break;
                a /= 2;
                cnt++; 
            }
            return ans;
        };

        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        vector<int> que;
        que.reserve(n * 160);
        for (auto &x : a) {
            for (int i = 0; i <= 31; i++) if (x >> i) que.push_back(x >> i);
            // for (int i = x - 30; i <= x + 30; i++) if(i > 0) {
            //     que.push_back(i);
            // }
        }
        // for (int i = 1; i <= 1000; i++) que.push_back(i);
        sort(que.begin(), que.end());
        que.erase(unique(que.begin(), que.end()), que.end());

        int ans = inf;
        for (auto &x : que) {
            vector<int> b(n);
            int sum = 0;
            for (int i = 0; i < n; i++) {
                int y = a[i];
                b[i] = tun(y, x);
            }
            sort(b.begin(), b.end());
            for (int i = 0; i < n - m; i++) {
                sum += b[i];
                if (sum > inf) break;
            }
            ans = min (ans, sum);
        }
        cout << ans << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
}
</code>