#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int ans = 0;
    int mxO = -1e18, mnO = 1e18;
    int mxE = -1e18, mnE = 1e18;
 
    bool sorted = 1;
    bool alleven = 1;
    bool allodd = 1;
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1 && a[i] < a[i - 1]) {
            sorted = 0;
        }
        if (a[i] & 1) {
            alleven = 0;
            mxO = max(a[i], mxO);
            mnO = min(a[i], mnO);
        } else {
            allodd = 0;
            mxE = max(a[i], mxE);
            mnE = min(a[i], mnE);
        }
    }
 
    if (sorted) {
        cout << "YES\n";
        return;
    }
 
    if (alleven || allodd) {
        cout << "NO\n";
        return;
    }
 
 
    int lf1 = n + 1, rt1 = 0;
 
    for (int i = 1; i <= n; i++) {
        if (a[i] & 1) {
            if (a[i] > mxE) {
                lf1 = i;
                break;
            }
        }
    }
 
    for (int i = n; i >= 1; i--) {
        if (a[i] & 1) {
            if (a[i] < mnE) {
                rt1 = i;
                break;
            }
        }
    }
 
    int lf2 = n + 1, rt2 = 0;
 
    for (int i = 1; i <= n; i++) {
        if (!(a[i] & 1)) {
            if (a[i] > mxO) {
                lf2 = i;
                break;
            }
        }
    }
 
    for (int i = n; i >= 1; i--) {
        if (!(a[i] & 1)) {
            if (a[i] < mnO) {
                rt2 = i;
                break;
            }
        }
    }
 
    if (lf1 < rt1 || lf2 < rt2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
