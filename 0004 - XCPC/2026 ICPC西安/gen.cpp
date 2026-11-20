#include <bits/stdc++.h>

using namespace std;

#define int long long

mt19937_64 rng(random_device{}());

void sol() {
    int mx = 10;
    int n = rng() % 5 + 1;
    int x = rng() % (int)mx + 1;
    int y = rng() % (int)mx + 1;
    vector<int> vis(1e6 + 1);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = rng() % (mx * 3) + 1;
        while (vis[a[i]]) {
            a[i] = rng() % (mx * 3) + 1;
        }
        vis[a[i]] = 1;
        b[i] = rng() % mx + 1;
    }
    sort(a.begin(), a.end());
    cout << n << " " << x << " " << y << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << b[i] << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << "1\n";
    sol();
}

/*
2
3 5 2
1 3
10 5
20 2
3 100 1
1 5
2 5
3 5


1
3 5 2
1 3
10 5
20 2


1
3 100 1
1 5
2 5
3 5


*/