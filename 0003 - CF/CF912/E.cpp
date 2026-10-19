#include <bits/stdc++.h>

using namespace std;

#define int long long


const int inf = 1e18;
signed main() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i & 1) b.push_back(p[i]);
        else a.push_back(p[i]);
    }

    set<int> sa;
    sa.insert(1);
    for (auto x : a) {
        for (auto y : sa) {
            if (y <= inf / x) {
                sa.insert(y * x);
            }
        }
    }
    
    vector<int> va(sa.begin(), sa.end());

    set<int> sb;
    sb.insert(1);
    for (auto x : b) {
        for (auto y : sb) {
            if (y <= inf / x) {
                sb.insert(y * x);
            }
        }
    }
    
    vector<int> vb(sb.begin(), sb.end());

    int k;
    cin >> k;

    int l = 1, r = inf;
    int ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int res = 0;
        for (auto x : va) {
            res += upper_bound(vb.begin(), vb.end(), mid / x) - vb.begin();
        }

        if (res >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
}

/*
3
2 3 5
7

*/