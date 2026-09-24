#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> vis, pr, minp;
void init() {
    int n = 1e6;
    vis.assign(n + 5, 0);
    minp.assign(n + 5, 1);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) pr.push_back(i), minp[i] = i;
        for (int j : pr) {
            int m = i * j;
            if (m > n) break;
            vis[m] = 1;
            minp[m] = j;
            if (i % j == 0) {
                break;
            }
        }
    }
}
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1), cnt(n + 1);
    int has = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int x = a[i];
        while (x != 1) {
            int y = minp[x];
            cnt[i]++;
            while (x % y == 0) x /= y;
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) has++;
    }
 
    if (has == 0) {
        cout << "Bob\n";
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        a[i] = minp[a[i]];
        if (cnt[i] > 1) {
            cout << "Alice\n";
            return;
        }
    }
 
    has = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) has++;
    }
    if (has == 0) {
        cout << "Bob\n";
        return;
    } else {
        cout << "Alice\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t = 1;
    cin >> t;
    while (t--) sol();
}
