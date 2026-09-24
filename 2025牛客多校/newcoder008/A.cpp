#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    void sol() {
        int x;
        cin >> x;
        vector<int> a;
        if (x >= 0) {
            if (x == 0) a.push_back(0);
            while (x) {
                a.push_back(x % 10);
                x /= 10;
            }
            reverse(a.begin(), a.end());
            bool fg = 0;
            for (auto t : a) {
                if (!fg && t == 0) {
                    cout << 1;
                    fg = 1;
                }
                cout << t;
            }
            if (!fg) cout << 1;
        }
        if (x < 0) {
            __int128 y = -x;
            cout << "-";
            if (y == 0) a.push_back(0);
            while (y) {
                a.push_back(y % 10);
                y /= 10;
            }
            reverse(a.begin(), a.end());
            bool fg = 0;
            for (auto t : a) {
                if (!fg && t > 1) {
                    cout << 1;
                    fg = 1;
                }
                cout << t;
            }
            if (!fg) cout << 1;
        }
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