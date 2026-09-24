#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n;
    cin >> n;
    int alln = n * 2 + 1;
 
    auto check = [&](int m, vector<int> fixd) -> bool {
        vector<int> q;
        for (int i = 1; i <= m; i++) {
            q.push_back(i);
        }
        for (auto x : fixd) {
            q.push_back(x);
        }
 
        if (q.empty()) return false;
 
        cout << "? " << q.size() << " ";
        for (auto x : q) cout << x << " ";
        cout << endl;
 
        int res;
        cin >> res;
        if (res == -1) exit(0);
        return (q.size() - res) % 2 != 0;
    };
 
    int l = 1, r = alln;
    int c1 = r;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, {})) {
            c1 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
 
    l = 1;
    r = c1 - 1;
    int c2 = r;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, {c1})) {
            c2 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
 
    l = 1;
    r = c2 - 1;
    int c3 = r;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, {c1, c2})) {
            c3 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << "! " << c3 << " " << c2 << " " << c1 << endl;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
