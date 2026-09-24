// QOJ user: lnxbb
// Contest: 2022 ç¬?7å±ŠICPCé¦™æ¸¯ç«?// Problem: #5465. Maximum GCD (5465)
// Submission: https://qoj.ac/submission/1548872
// Language: C++26

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        if (a.size() == 1) {
            cout << a[0];
            return;
        } else if (a[1] >= 2 * a[0]) {
            cout << a[0];
            return;
        } else {
            cout << a[0] / 2;
            return;
        }
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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