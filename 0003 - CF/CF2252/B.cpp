#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    string s;
    cin >> n >> s;

    s = " " + s;
    vector<int> a(n + 1);
    vector<int> cnt(2);
    for (int i = 1; i <= n; i++) {
        a[i] = s[i] - '0';
        cnt[a[i]]++;
    }
    if (cnt[0] > cnt[1]) {
        for (int i = 1; i <= n; i++) {
            a[i] ^= 1;
        }
        swap(cnt[0], cnt[1]);
    }

    if (cnt[0] == cnt[1]) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] != a[i - 1]) {
                ans++;
            }
        }
        cout << n - ans << "\n";
    } else if (cnt[0] + 1 == cnt[1]) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] != a[i - 1]) ans++;
        }
        if (a[1] == 0 && a[n] == 0) ans--;
        cout << n - ans << "\n";
    } else if (cnt[0] + 2 == cnt[1]) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != a[i - 1] && a[i] == 1) {
                ans++;
            }
        }
        ans = ans * 2 - 1;
        cout << n - ans << "\n";
    } else {
        cout << "-1\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
} 

/*
5
4
0101
3
111
6
100110
6
100010
6
011110
*/