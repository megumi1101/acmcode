#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
 
    void sol() {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first; 
        for (int i = 0; i < n; i++) cin >> a[i].second; 
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            if (k >= a[i].first) {
                k += a[i].second;
            }
        }
        cout << k << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
