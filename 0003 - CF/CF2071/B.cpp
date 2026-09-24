#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
 
struct Point {
    int x, y, c;
};
 
struct cmp1 {
    bool operator() (const Point &a, const Point &b) const {
        return a.x < b.x;
    }
};
 
struct cmp2 {
    bool operator() (const Point &a, const Point &b) const {
        return a.y < b.y;
    }
};
    void sol() {
        int n;
        cin >> n;
 
        auto is = [&](int x) {
            return (int)sqrt(x) * (int)sqrt(x) == x;
        };
        if (n == 1) {
            cout << "-1\n";
            return;
        }
        if (n & 1) {
            if (is(n) && is((n + 1) / 2)) {
                cout << "-1\n";
                return;
            }
        } else {
            if (is(n + 1) && is(n / 2)) {
                cout << "-1\n";
                return;
            }
        }
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        for (int i = 0; i < n; i++) {
            if (a[i] & 1) {
                 if (is(a[i]) && is((a[i] + 1) / 2)) {
                    swap(a[i], a[i + 1]);
                    i++;
                }
            } else {
                 if (is(a[i] + 1) && is((a[i]) / 2)) {
                    swap(a[i], a[i + 1]);
                    i++;
                }
            }
        }
        for (auto x : a) cout << x << " ";
        cout << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
 
int main() {
    return Xbbbz::main(), 0;
}
