#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cnt++;
        }
        for (int i = 0; i < cnt; i++) {
            if (s[i] == '1') ans++;
        }
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz :: main(), 0;
}
