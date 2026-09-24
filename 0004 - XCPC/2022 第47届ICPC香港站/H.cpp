// QOJ user: lnxbb
// Contest: 2022 ç¬?7å±ŠICPCé¦™æ¸¯ç«?// Problem: #5462. Another Goose Goose Duck Problem (5462)
// Submission: https://qoj.ac/submission/1548755
// Language: #5462. Another Goose Goose Duck Problem

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    void sol() {
        int l, r, b, k;
        cin >> l >> r >> b >> k;
        int tim;
        if (b >= l) {
            tim = b;
        } else {
            tim = (l - 1) / b + 1;
            tim *= b;
        }
        cout << tim * k << "\n";
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