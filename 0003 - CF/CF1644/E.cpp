#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
 
    void sol() {
        int n;
        cin >> n;
        int ans = n * n;
        string s;
        cin >> s;
        if (s[0] == 'R')
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 'R') s[i] = 'D';
                else if (s[i] == 'D') s[i] = 'R';
            }
        int cntR = 0, cntD = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') cntR++;
            else cntD++;
        }
        if (cntR == s.size() || cntR == 0) {
            cout << n << "\n";
            return;
        }
        int nowR = 0, nowD = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'D') {
                ans -= cntR - nowR;
                nowD++;
            }
            else {
                ans -= cntD - nowD;
                nowR++;
            }
        }
        int x = n - nowR - 1;
        int p = 0;
        while (s[p] == 'D') p++, ans -= x;
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T; cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
