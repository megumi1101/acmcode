#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<tuple<int, int, int>> ans;
        for (auto &x : a) cin >> x;
        if (n <= 1) {
            cout << "YES\n0";
            return;
        } else if (n == 2) {
            if (a[0] == a[1]) {
                cout << "YES\n0";
            } else {
                cout << "NO\n";
            }
            return;
        } else {
            int mx = n - 1;
            if (n & 1) mx++;
            else {
                int now = 0;
                for (auto x : a) now ^= x;
                if (now != 0) {
                    cout << "NO\n";
                    return;
                }
            } 
            
            for (int i = 0; i + 2 < mx; i += 2) {
                int tmp = a[i] ^ a[i + 1] ^ a[i + 2];
                a[i] = a[i + 1] = a[i + 2];
                ans.emplace_back(i, i + 1, i + 2);
            }
 
            for (int i = 0; i + 4 < mx; i += 2) {
                ans.emplace_back(i, i + 1, mx - 1);
            }
        }
        
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (auto[x, y, z] : ans) cout << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
 
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
