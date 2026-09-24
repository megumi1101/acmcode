#include <bits/stdc++.h>
 
using namespace std;
 
 
void sol() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1);
    vector<int> p0, p1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i <= x || i > y) {
            p1.push_back(a[i]);
        }  else {
            p0.push_back(a[i]);
        }
    }
 
    const int inf = 1e9;
    int mnpos = 0;
    int mn = inf;
    for (int i = 0; i < p0.size(); i++) {
        if (p0[i] < mn) {
            mnpos = i;
            mn = p0[i];
        }
    }
 
    for (int i = 0; i < p1.size(); i++) {
        if (p1[i] < mn) {
            cout << p1[i] << " ";
        } else {
            for (int j = 0; j < p0.size(); j++) {
                cout << p0[(mnpos + j) % p0.size()] << " ";
            }
            for (int j = i; j < p1.size(); j++) {
                cout << p1[j] << " ";
            }
            break;
        }
 
        if (i + 1 == p1.size()) {
            for (int j = 0; j < p0.size(); j++) {
                cout << p0[(mnpos + j) % p0.size()] << " ";
            }
        }
    }
 
    if (p1.empty()) {
        for (int j = 0; j < p0.size(); j++) {
                cout << p0[(mnpos + j) % p0.size()] << " ";
            }
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
