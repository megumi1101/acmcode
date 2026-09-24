#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> mx(n + 1, -1);
    
    auto ask = [&](int i, int j) -> int {
        cout << "? " << i << " " << j << endl;
        string s;
        cin >> s;
        if (s == "Yes") {
            return 1;
        } else {
            return 0;
        }
    };

    int r = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        r = max(i, r);
        while (r + 1 <= n) {
            if (ask(i, r + 1)) {
                r++;
            } else {
                break;
            }
        }
        ans += r - i;
    }
    cout << "! "<<  ans << endl;
}