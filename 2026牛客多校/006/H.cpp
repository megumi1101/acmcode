#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> vis, pr;
void init(int n) {
    vis.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) pr.push_back(i);
        for (int j : pr) {
            int m = i * j;
            if (m > n) break;
            vis[m] = 1;
            if (i % j == 0) {
                break;
            }
        }
    }
}


void sol() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    if (n == 1 || n == 3 || n == 4 || n == 6) {
        cout << "-1\n";
        return;
    } else if (n == 2) {
        cout << "1 2\n";
        return;
    }

    if (n & 1) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    } else {
        if (vis[n - 1]) {
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
        } else {
            for (int i = 1; i <= n - 4; i++) {
                cout << i << " ";
            }
            for (int i = n; i > n - 4; i--) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init(1e6);
    int t;
    cin >> t;
    while (t--) sol();
}

/*
3
5
bca a zz ab c
4
ba b aa aba
3
az za m
*/