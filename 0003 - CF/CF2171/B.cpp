#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
 
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (auto &x : a) cin >> x;
        if (a[0] == -1 && a[n - 1] == -1) a[0] = a[n - 1] = 0;
        else if (a[0] == -1 || a[n - 1] == -1) a[0] = max(a[0], a[n - 1]), a[n - 1] = max(a[0], a[n - 1]);
        for (auto &x : a) if (x < 0) x = 0;
        cout << abs(a[0] - a[n - 1]) << "\n";
        for (auto &x : a) cout << x << " ";
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
