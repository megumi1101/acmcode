// AtCoder user: lnxbb
// Contest: agc001
// Problem: agc001_d
// Submission: https://atcoder.jp/contests/agc001/submissions/75220576
// Language: C++23 (GCC 15.2.0)

#include<bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    int odd = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        if (a[i] & 1) odd++;
    }
    
    if (odd > 2) cout << "Impossible\n";
    else {
        for (int i = 2; i < m; i++) {
            if ((a[i] & 1) && !(a[1] & 1)) {
                swap(a[1], a[i]);
            }
            if ((a[i] & 1) && !(a[m] & 1)) {
                swap(a[m], a[i]);
            } 
        }

        if (m == 1) {
            cout << a[1] << "\n";
            if (a[1] > 1) cout << "2\n";
            else cout << "1\n";
            cout << "1 ";
            if (a[1] > 1) cout << a[1] - 1 << "\n";
        } else {
            vector<int> b;
            int now = 0;
            if (a[1] != 1) b.push_back(a[1] - 1);
            for (int i = 2; i < m; i++) b.push_back(a[i]);
            b.push_back(a[m] + 1);
            for (int i = 1; i <= m; i++) cout << a[i] << " ";
            cout << "\n";
            cout << b.size() << "\n";
            for (auto x : b) cout << x << " ";
            cout << "\n";
        }
    }
}
