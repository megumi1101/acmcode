// AtCoder user: lnxbb
// Contest: agc003
// Problem: agc003_d
// Submission: https://atcoder.jp/contests/agc003/submissions/75402407
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);

    int mx = -1;
    int ans = 0;

    map<int, int> cnt;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int p = 2; p * p * p <= a[i]; p++) {
            int t = p * p * p;
            while (a[i] % t == 0) a[i] /= t;
        }
        // cerr << a[i] << "\n";
        mx = max(mx, a[i]);
        if (cnt.find(a[i]) == cnt.end()) {
            if (a[i] == 1) ans++;
            else v.push_back(a[i]);
        }
        cnt[a[i]]++;
    }

    mx = 2155;
    
    
    int ans2 = 0;
    // cerr << ans << "\n";
    // cerr << v.size() << "\n";
    // for (auto x : v) cerr << x << " ";
    // cerr << "\n\n";
    for (int i = 0; i < v.size(); i++) {
        int x = v[i];
        int tmp = 1;
        for (int p = 2; p <= v[i] && p <= mx; p++) {
            int res = 0;
            while (x % p == 0) {
                res++;
                x /= p;
            }

            if (res) {
                for (int j = 0; j < 3 - res; j++) {
                    tmp *= p;
                }
            }
        }

        if (x != 1) {
            int y = sqrt(x);
            if (y * y == x) {
                tmp *= y;
            } else {
                if (x <= sqrt(1e10 / tmp) + 10) {
                    tmp *= x * x;
                } else {
                    tmp = -1;
                }
            }
        } 

        if (cnt.find(tmp) != cnt.end()) {
            ans2 += max(cnt[v[i]], cnt[tmp]);
        } else {
            ans += cnt[v[i]];
        }
        
    }

    cout << ans + ans2 / 2 << "\n";
}

/*
4
4
0
3
2

*/