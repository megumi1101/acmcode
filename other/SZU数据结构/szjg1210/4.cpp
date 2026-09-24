#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        int ans = 0, cnt = 1;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        vector ch(n * 33, vector(2, 0));
        vector siz(n * 33, vector(2, 0));

        auto add = [&](int x) {
            int u = 1;
            for (int j = 30; j >= 0; j--) {
                int y = (x >> j) & 1;
                if (!ch[u][y]) ch[u][y] = ++cnt;
                siz[u][y]++;
                if (y == 0) ans += siz[u][1];
                u = ch[u][y];
            }
        };

        for (auto v : a) add(v);
        cout << ans;    
    }
    return 0;
}
