// QOJ user: lnxbb
// Contest: 2022 ç¬?7å±ŠICPCè¥¿å®‰ç«?// Problem: #5117. Find Maximum (5117)
// Submission: https://qoj.ac/submission/1661431
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    void sol() {
        int l, r;
        cin >> l >> r;
        vector<int> a, b;
        vector<int> f(101);
        f[0] = 1;
        for (int i = 1; i <= 100; i++) {
            if (i % 3 == 0) f[i] = f[i / 3] + 1;
            else f[i] = f[i - 1] + 1;
        }
        if (r <= 100) {
            int mx = 0;
            for (int i = l; i <= r; i++) {
                mx = max(mx, f[i]);
            }
            cout << mx << "\n";
            return;
        }
        int x = l;

        int ans = 0;
        int res = 0;
        while (x) {
            res += (x % 3) + 1;
            a.push_back(x % 3); x /= 3;
        }
        ans = max(ans, res);


        x = r;
        res = 0;
        while (x) {
            res += (x % 3) + 1;
            b.push_back(x % 3); x /= 3;
        }
        ans = max(ans, res);
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        cerr << a.size() << "\n";
        cerr << b.size() << "\n";
        for (int i = 0; i < b.size(); i++) cerr << b[i];
        cerr << "\n";
        if (a.size() != b.size()) {
            res = (int)b.size() * 3 - 3;
            if (b[0] == 2) res += 2;
            else if (b[1] == 2) res++; 
            ans = max(ans,  res);
        } else {                            
            res = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == b[i]) res += b[i] + 1;
                else {
                    res += (b.size() - i) * 3 - 3 + b[i];
                    ans = max(ans, res);
                    break;
                }
            }
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
#undef int
int main() {
    return Xbbbz::main(),0;
}
</code>