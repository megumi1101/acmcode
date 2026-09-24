#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    void sol() {
        int n;
        cin >> n ;
        vector<int> lst(150005, 0);
        int ans = n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (lst[x]) {
                ans = min (ans, i - lst[x]);
            }
            lst[x] = i;
        }
        if (ans == n) {
            cout << "-1\n";
        }
        else cout << n - ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
