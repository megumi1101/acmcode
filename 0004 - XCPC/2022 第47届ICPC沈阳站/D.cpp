// QOJ user: lnxbb
// Contest: 2022 ç¬?7å±ŠICPCæ²ˆé˜³ç«?// Problem: #5436. DRX vs. T1 (5436)
// Submission: https://qoj.ac/submission/1652223
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 1e9 + 10000;
    void sol() {
        int x = 0, y = 0;
        string s;
        cin >> s;
        for (auto c : s) {
            if (c == 'D') x++;
            else if (c == 'T') y++;
        }
        if (x >= y) cout << "DRX";
        else cout << "T1";
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