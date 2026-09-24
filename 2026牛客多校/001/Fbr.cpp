#include<bits/stdc++.h>

using namespace std;

#define int long long


signed main() {
    int n;
    cin >> n;
    vector<vector<vector<int>>> t(n);

    // freopen("3.txt", "w", stdout);
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    do {
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i * p[i] - sum;
            sum += p[i];
        }
        ans %= n;
        ans += n;
        ans %= n;
        t[ans].push_back(p);
    } while(next_permutation(p.begin(), p.end()));

    for (int i = 0; i < n; i++) {
        cout << i << "\n";
        cout << t[i].size() << "\n";
        for (auto p : t[i]) {
            for (auto tmp : p) cout << tmp << " ";
            cout << "\n";
        }
    }
}