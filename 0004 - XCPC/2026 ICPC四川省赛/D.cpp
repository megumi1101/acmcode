#include <bits/stdc++.h>

using namespace std;

void sol() {
    string s;
    cin >> s;
    int n = s.size();
    if (n & 1) {
        array<array<int, 26>, 2> a{};
        int op = 0;
        for (char c : s) {
            op ^= 1;
            a[op][c - 'a'] ^= 1;
        }
        for (int i = 0; i < 2; i++) {
            int cnt = 0;
            for (int x : a[i]) {
                if (x == 1) cnt++;
            }
            if (cnt >= 2) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    } else {
        array<string, 2> t;
        int op = 0;
        for (char c : s) {
            op ^= 1;
            t[op].push_back(c);
        }
        for (auto &s : t) ranges::sort(s);
        if (t[0] == t[1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}