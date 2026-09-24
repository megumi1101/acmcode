#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    void sol() {
        int n; 
        cin >> n;
        int a[n + 5];
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        int m = sum * 2 / n;
        if (m * n != 2 * sum) {
            cout << "0\n";
            return;
        }
        map <int, int> mp;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += mp[m - a[i]];
            mp[a[i]]++;
        }
        cout << ans << "\n";
    }
    void main () {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
