#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    auto c = a;
    int xsum = 0;
    for (int i = 0; i < n; i++) {
        c[i] ^= b[i];
        xsum ^= c[i];
    }

    sort(a.begin(), a.end());
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == xsum) {
            pos = i;
            break;
        }
    }

    vector<int> ta;
    for (int i = 0; i < n; i++) {
        if (i == pos) {
            ta.push_back(a[i]);
        } else {
            ta.push_back(a[i] ^ a[pos]);
        }
    }
    sort(ta.begin(), ta.end());
    sort(b.begin(), b.end());
    if (ta == b || a == b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) sol();
}