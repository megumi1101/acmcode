// QOJ user: lnxbb
// Contest: 2021 ç¬?6å±ŠICPCä¸Šæµ·ç«?// Problem: #10904. Strange Integers (10904)
// Submission: https://qoj.ac/submission/1698266
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    void sol() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a) cin >> i;
        sort(a.begin(), a.end());
        int lst = 0;
        int ans = 0;
        for (auto x : a) {
            if (lst == 0) lst = x;
            else {
                if (x >= lst + k) {
                    lst = x;
                    ans++;
                }
            }
        }
        cout << ans + 1 << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
#undef int
int main() {
    return Xbbbz::main(),0;
}
</code>