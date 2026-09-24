#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') cnt++;
            else cnt = 0;
            if (cnt >= m) {
                for (int j = i; j < min((int)s.size(), i + k); j++) {
                    s[j] = '1';    
                }
                cnt = 0;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
