#include <bits/stdc++.h>

using namespace std;

void sol() {
    string s;
    int k;
    cin >> s >> k;

    string t = "Rounddo";
    for (int i = 0; i < k; i++) t.push_back('g');

    int n = s.size();
    s = s + s;
    for (int i = 0; i + t.size() < s.size(); i++) {
        if (s.substr(i, t.size()) == t) {
            s = s.substr(i, n);
            break;
        }
    }

    if (s.size() == 2 * n) {
        cout << "0\n";
        return;
    }

    int cnt = 0;
    for (int i = 0; i + t.size() - 1 < s.size(); i++) {
        if (s.substr(i, t.size()) == t) {
            cnt++;
        }
    }

    int m = t.size();
    if (cnt == 1) {
        cout << n - m + 1 << "\n";
    } else {
        cout << n << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}