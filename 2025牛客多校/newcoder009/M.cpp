#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    void sol() {
        int x;
        cin >> x;
        if (x < 10) cout << 1 << "\n";
        else cout << "-1\n";
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