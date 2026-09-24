#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    void sol() {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while (q--) {
            string t;
            int x;
            cin >> t >> x;
            int ans = 0;
            int cnt = 0;
            for (int i = 0; i < t.size(); i++) {
                if (s[i + x - 1] == t[i]) {
                    cnt++;
                }
                else {
                    ans += cnt * (cnt + 1) / 2;
                    cnt = 0;
                }
            }
            ans += cnt * (cnt + 1) / 2;
            cout << ans << "\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T  = 1;
        // cin >> T;
        while (T--) sol();
    }
    #undef int 
}

int main() {
    return Xbbbz::main(), 0;
}