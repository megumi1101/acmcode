#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    array<int, 2> a{};
    for (int i = 0; i < 2 * n; i++) {
        int op = 0;
        if (i & 1) op ^= 1;
        if (s[i] == '1' && s[(i + 1) % (2 * n)] == '1') op ^= 1;
        if (s[i] == '1') a[op]++;
    }
    cout << a[0] << " " << a[1] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
}