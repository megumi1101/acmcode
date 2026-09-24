#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
 
    void sol() {
        int n;
        cin >> n;
        bool fg = 0;
        vector<string> s(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            if (s[i][0] == s[i].back()) fg = 1;
        }
        vector<int> t2(26 * 26), t3q(26 * 26), t3h(26 * 26), t3(26 * 26 * 26);
        for (auto t : s) {
            if (t.size() == 2) {
                int x = (t[0] - 'a') * 26 + t[1] - 'a';
                int y = (t[1] - 'a') * 26 + t[0] - 'a';
                if (t2[y] || t3q[y]) fg = 1;
                t2[x] = 1;
            }
            if (t.size() == 3) {
                int x = (t[0] - 'a') * 26 + t[1] - 'a';
                int y = (t[1] - 'a') * 26 + t[2] - 'a';
                int z = (t[2] - 'a') * 26 + t[1] - 'a';
                int k = (t[2] - 'a') * 26 * 26 + (t[1] - 'a') * 26 + t[0] - 'a';
                int p = (t[0] - 'a') * 26 * 26 + (t[1] - 'a') * 26 + t[2] - 'a';
                if (t2[z] || t3[k]) fg = 1;
                t3[p] = 1;
                t3q[x] = 1;
            }
        }
        if (fg) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
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
    return Xbbbz::main(), 0;
}
