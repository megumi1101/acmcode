// AtCoder user: lnxbb
// Contest: agc003
// Problem: agc003_e
// Submission: https://atcoder.jp/contests/agc003/submissions/75475357
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long


signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> a;
    a.push_back(n);
    while (q--) {
        int x;
        cin >> x;
        while (!a.empty() && a.back() >= x) {
            a.pop_back();
        }
        a.push_back(x);
    }

    int siz = a.size();

    vector<int> cnt(siz);
    cnt.back() = 1;
    vector<int> d(n + 5);
    auto add = [&](this auto &&self, int L, int C) -> void {
        auto it = upper_bound(a.begin(), a.end(), L);
        
        if (it == a.begin()) {
            d[1] += C;
            d[L + 1] -= C; 
        } else {
            --it;
            int idx = it - a.begin();
            cnt[idx] += L / a[idx] * C;
            self(L % a[idx], C);
        }
    };
   
    for (int i = siz - 1; i > 0; i--) {
        cnt[i - 1] += a[i] / a[i - 1] * cnt[i];
        add(a[i] % a[i - 1], cnt[i]);
    }
    d[1] += cnt[0];
    d[a[0] + 1] -= cnt[0];
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        cout << d[i] << "\n";
    }
}