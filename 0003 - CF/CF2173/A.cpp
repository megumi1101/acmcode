#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
    void sol() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> vis(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                for (int j = i; j <= i + k && j < n; j++) {
                    vis[j] = 1;
                }
            }
        }
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                cnt++;
            }
        }
        cout << cnt << "\n";
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
