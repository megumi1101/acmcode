#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> d(n + 1);
    for (int i = 2; i <= n; i++) {
        d[i] = a[i] - a[i - 1];
    }

    vector<int> v;
    vector<int> d2(2, 0);
    for (int i = 2; i <= n; i++) {
        if (v.empty()) {
            v.push_back(d[i]);
        } else {
            if ((d[i] - v.back()) % 2 == 0) {
                v.push_back(d[i]);
            } else {
                sort(v.begin(), v.end());
                for (auto x : v) {
                    d2.push_back(x);
                }
                v.clear();
                v.push_back(d[i]);
            }
        }
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
        d2.push_back(x);
    }


    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + d2[i];
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
} 

/*
3
10
100 108 114 118 120 5 7 19 13 11
3
1 2 3
4
10 10 8 4
*/