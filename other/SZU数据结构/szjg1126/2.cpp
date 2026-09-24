#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int m, n;
        cin >> m >> n;

        vector<int> table(m);
        vector<bool> used(m, false);

        for (int i = 0; i < n; ++i) {
            int key;
            cin >> key;
            int h = key % 11;
            if (h < 0) h += 11; // 保险

            if (!used[h]) {
                table[h] = key;
                used[h] = true;
                continue;
            }

            bool placed = false;
            for (int k = 1; k < m && !placed; ++k) {
                int pos = (h + 1LL * k * k) % m;
                if (!used[pos]) {
                    table[pos] = key;
                    used[pos] = true;
                    placed = true;
                    break;
                }
                pos = (h - 1LL * k * k) % m;
                if (pos < 0) pos += m;
                if (!used[pos]) {
                    table[pos] = key;
                    used[pos] = true;
                    placed = true;
                    break;
                }
            }
        }

        int k;
        cin >> k;

        for (int i = 0; i < m; ++i) {
            if (i) cout << ' ';
            if (!used[i]) cout << "NULL";
            else cout << table[i];
        }
        cout << '\n';

        while (k--) {
            int key;
            cin >> key;
            int h = key % 11;
            if (h < 0) h += 11;

            int cmp = 0;
            int found_pos = -1;

            auto check = [&](int pos) -> bool {
                ++cmp;              
                if (!used[pos]) {   
                    return false;
                }
                if (table[pos] == key) { 
                    found_pos = pos;
                    return false;
                }
                return true;        
            };

            if (check(h)) {
                for (int t = 1; t < m; ++t) {
                    int pos = (h + 1LL * t * t) % m;
                    if (!check(pos)) break;
                    pos = (h - 1LL * t * t) % m;
                    if (pos < 0) pos += m;
                    if (!check(pos)) break;
                }
            }

            if (found_pos == -1) {
                cout << 0 << ' ' << cmp << '\n';
            } else {
                cout << 1 << ' ' << cmp << ' ' << (found_pos + 1) << '\n';
            }
        }
    }

    return 0;
}
