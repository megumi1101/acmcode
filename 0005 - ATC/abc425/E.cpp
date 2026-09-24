#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> C;
void init(int n, int mod) {
    C.resize(n + 5);
    for (int i = 0; i <= n; i++) {
        C[i].resize(i + 5);
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= mod;
        }
    }
}
    
void sol(int mod) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 1;
    int sum = accumulate(a.begin() + 1, a.end(), 0ll);
    for (int i = 1; i <= n; i++) {
        ans = ans * C[sum][a[i]] % mod;
        sum -= a[i];
    }
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m;
    cin >> t >> m;
    init(5e3, m);

    while (t--) sol(m);
}
/*
3 1000000000000000
2
2 2
5
1 1 1 1 1
6
1 2 3 4 5 6
*/