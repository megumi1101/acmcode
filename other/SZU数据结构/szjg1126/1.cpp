#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int m, n;
        cin >> m >> n;

        vector<int> table(m);
        vector<bool> used(m, 0); 

        for (int i = 0; i < n; ++i) {
            int key;
            cin >> key;
            int h = key % 11;
            if (h < 0) h += 11; 
            int pos = h;
            for (int step = 0; step < m; ++step) {
                if (!used[pos]) {
                    table[pos] = key;
                    used[pos] = true;
                    break;
                }
                pos = (pos + 1) % m;
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

            int pos = h;
            int cmp = 0;         
            int found_pos = -1;  

            for (int step = 0; step < m; ++step) {
                ++cmp;  
                if (used[pos] && table[pos] == key) {
                    found_pos = pos;
                    break;
                }
                if (!used[pos]) {
                    break;
                }
                pos = (pos + 1) % m;
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
