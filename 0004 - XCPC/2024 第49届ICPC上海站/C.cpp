// QOJ user: xbbbz
// Contest: 2024 ç¬?9å±ŠICPCä¸Šæµ·ç«?// Problem: #9039. Conquer the Multiples (9039)
// Submission: https://qoj.ac/submission/1540119
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    void sol() {
        int l, r;
        cin >> l >> r;
        bool vic = 1;
        if (r & 1) {
            int t = (r - l) & 1;
            vic ^= t;
        } else {
            int t = (r - l) & 1;
            t ^= 1;
            vic ^= t;
            if (l & 1);
            else l++;
            if (2 * l <= r);
            else vic ^= 1;
        }
        if (vic) cout << "Alice";
        else cout << "Bob";
        cout << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
/*
1
5 10
*/
</code>