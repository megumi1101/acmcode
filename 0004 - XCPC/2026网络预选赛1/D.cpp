#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353; 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p(n);
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s.insert(p[i]);
    }


    int mx = 0, mn = 0;
    int ans = 1;
    while (!s.empty()) {
        
        ans = ans * 2 % mod;
        while (!s.empty() && *s.begin() == mn) {
            s.extract(mn);
            mx++;
        }
        
        while (!s.empty()) {
            if (mx > *s.begin()) {
                int t = *s.begin();
                while (mn < t) {
                    mn++;
                    s.extract(mx);
                }
                while (!s.empty() && *s.begin() == mn) {
                    mx++;
                    s.extract(mn);
                }
            } else {
                while (!s.empty() && mn < mx) {
                    mn++;
                    s.extract(s.begin());
                }
                break;
            }
        }
    }

    cout << ans << "\n";
}

/*
4
4 1
2 4 3 2 4
3 2
1 3 1 2 3
1 3 3 2 1
5 2
2 4 4 2 3
2 4 4 2 3
4 2
2 2 2
1 4 2 1 4 3
*/