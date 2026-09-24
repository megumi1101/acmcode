#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    void sol() {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int x = b * b - a * a;
        if (x == 3) {cout << "1\n"; return;}
        int ans = (x + 1) / 2 + x / 4 - 2;
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz ::main(), 0;
}