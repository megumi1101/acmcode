#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    s = " " + s;
    vector<int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    const int inf = 1e13;
 
    for (int i = 1; i < n; i++) {
        if (c[i + 1] < c[i]) {
            cout << "No\n";
            return;
        }
    }
 
 
    int l = 2;
    vector<int> ans(n + 1);
    ans[1] = c[1];
    if (s[1] == '1' && a[1] != c[1]) {
        cout << "No\n";
        return;
    }
 
 
    int r = -1;
    for (int t = 2; t <= n; t++) {
        if (c[t] > c[t - 1]) {
            r = t;
            int cnt = 0;
            for (int i = l; i <= r; i++) {
                if (s[i] == '0') cnt++;
            }
            int sd = c[r] - c[l - 1];
            int sum = 0;
            if (cnt == 0) {
                for (int i = l; i <= r; i++) {
                    if (sum > 0) {
                        cout << "No\n";
                        return;
                    }
                    if (s[i] == '1') {
                        sum += a[i];
                        ans[i] = a[i];
                    }
                    
                }
                if (sum != sd) {
                    cout << "No\n";
                    return;
                }
            } else if (cnt == 1) {
                for (int i = l; i <= r; i++) {
                    sum += a[i];
                }
                int x = sd - sum;
                sum = 0;
                for (int i = l; i <= r; i++) {
                    if (sum > 0) {
                        cout << "No\n";
                        return;
                    }
                    if (s[i] == '1') {
                        sum += a[i];
                        ans[i] = a[i];
                    } else {
                        sum += x;
                        ans[i] = x;
                    }
                    
                }
            } else {
                int posi = -1;
                for (int i = r; i >= l; i--) {
                    if (s[i] == '0') {
                        posi = i;
                        break;
                    }
                }
 
                for (int i = l; i <= r; i++) {
                    if (s[i] == '0' && i != posi) {
                        sum += -inf;
                    } 
                    if (s[i] == '1') {
                        sum += a[i];
                    }
                }
 
                int x = sd - sum;
                sum = 0;
                for (int i = l; i <= r; i++) {
                    if (sum > 0) {
                        cout << "No\n";
                        return;
                    }
                    if (s[i] == '0' && i != posi) {
                        sum += -inf;
                        ans[i] = -inf;
                    } 
                    if (s[i] == '1') {
                        sum += a[i];
                        ans[i] = a[i];
                    }
                    if (i == posi) {
                        sum += x;
                        ans[i] = x;
                    }
                    
                }
            }
            l = r + 1;
        } 
        
 
        if (t == n) {
            int sum = 0;
            r = n;
            for (int i = l; i <= r; i++) {
                if (s[i] == '0') {
                    sum += -inf;
                    ans[i] = -inf;
                } 
                if (s[i] == '1') {
                    sum += a[i];
                    ans[i] = a[i];
                }
                if (sum > 0) {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
 
 
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}

