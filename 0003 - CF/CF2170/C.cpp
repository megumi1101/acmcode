#include <bits/stdc++.h>
 
using namespace std;
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for (auto &i : a) {cin >> i;}
        for (auto &i : b) {cin >> i;}
        for (int i = 0; i < n; i++) {
            c[i] = (k - b[i]) / (b[i] + 1);
        }
        sort(c.begin(), c.end());
        sort(a.begin(), a.end());
        int l = 0, r = 0;
        while (l < n && r < n) {
            if (a[l] <= c[r]) l++, r++;
            else r++;
        }
        cout << l << "\n";
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
    return Xbbbz::main(),0;
}
