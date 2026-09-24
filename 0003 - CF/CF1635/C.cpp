#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n == 1) {
            cout << "0\n";
            return;
        }
        if (a[n] < 0) {
            for (int i = 1; i < n; i++) {
                if (a[i] > a[i + 1]) {
                    cout << "-1\n";
                    return;
                }
            }
            cout << "0\n";
            return;
        }
        else {
            if (a[n - 1] > a[n]) {
                cout << "-1\n";
                return;
            }
            cout << n - 2 << "\n";
            for (int i = 1; i <= n - 2; i++) {
                cout << i << " " << n - 1 << " " << n << "\n";
            }
        }
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
    return Xbbbz::main(),0;
}
