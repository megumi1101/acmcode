// QOJ user: lnxbb
// Contest: 2021 ç¬?6å±ŠICPCæ²ˆé˜³ç«?// Problem: #6616. Edward Gaming, the Champion (6616)
// Submission: https://qoj.ac/submission/1710529
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    void sol() {
        string s;
        cin >> s;
        string t = "edgnb";
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s.substr(i, 5) == t) ans++;
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
}
</code>