#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (s[i] == 'o') {
            pre[i]++;
        }
    }

    int r = 1;
    for (int i = 1; i <= n; i++) {
        r = max(i, r);
        int now = pre[i] - (r - i) + (pre[r] - pre[i]);
        while (r + 1 <= n && now > 0) {
            if (s[r + 1] == 'x') now--;
            r++;
        }
        cout << r << "\n";
    }
}