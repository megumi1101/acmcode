#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 2e18;
mt19937 gen((random_device())());
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n * n + 1, n + 1);
        for (int t = 1; t <= n; t++) {
            int cnt = 0;
            for (int i = 0; i < n * n + 1; i++) {
                if (a[i] == n + 1) {
                    cnt++;
                }
            }
            cout << "? " << cnt << " ";
            for (int i = 0; i < n * n + 1; i++) {
                if (a[i] == n + 1) {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
 
            int m;
            cin >> m;
            vector<int> b(m);
            for (auto &i : b) cin >> i;
            if (m >= n + 1) {
                cout << "! ";
                for (int i = 0; i <= n; i++) {
                    cout << b[i] << " ";
                }
                cout << endl;
                return;
            }
            for (auto &i : b) {
                a[i - 1] = t;
            }
        }
        
        int now = n + 1;
        vector<int> ans;
        for (int i = n * n; i >= 0; i--) {
            if (a[i] == now) {
                ans.push_back(i + 1);
                now--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "! ";
        for (int i = 0; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
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
