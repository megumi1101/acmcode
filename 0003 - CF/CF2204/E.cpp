#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    string s;
    cin >> s;
    int n = s.size();
    int mx = 9 * n;
    int sum = 0;
    if (n == 1) {
        cout << s << "\n";
        return;
    }
    vector<int> has(10);
    for (auto c : s) {
        sum += c - '0';
        has[c - '0']++;
    }
    
    vector<int> cnt(10);
 
    auto get = [&](int x) -> int {
        int res = 0;
        while (x) {
            int rem = x % 10;
            res += rem;
            cnt[rem]++;
            x /= 10; 
        }
        return res;
    };
    for (int i = 1; i <= 9 * n; i++) {
        for (int j = 0; j < 10; j++) cnt[j] = 0;
        int x = i;
        vector<int> p;
        while (x > 9) {
            p.push_back(x);
            x = get(x);
        }
            
        p.push_back(x);
        x = get(x);
 
        bool fg = 0;
        int now = 0;
        for (int j = 0; j < 10; j++) {
            now += cnt[j] * j;
            if (has[j] < cnt[j]) {
                fg = 1;
                break;
            }
        }
        if (fg) continue;
 
        // for (int j = 0; j < 10; j++) cout << has[j] << " ";
        // cout << "\n";
        // for (int j = 0; j < 10; j++) cout << cnt[j] << " ";
        if (sum - now == i) {
            string ans;
            for (int j = 9; j >= 0; j--) {
                for (int k = 1; k <= has[j] - cnt[j]; k++) {
                    ans.push_back('0' + j);
                }
            }
            cout << ans;
            for (auto x : p) cout << x;
            cout << "\n";
            return;
        }
    }
    
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
