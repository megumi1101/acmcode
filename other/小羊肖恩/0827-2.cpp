#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    
    auto dfs = [] (auto &&self, auto &a) -> vector<int> {
        if (a.size() <= 2) {
            return a;
        }

        vector<int> v0;
        vector<int> v1;
        for (int i = 0; i < a.size(); i++) {
            if (i & 1) v1.push_back(a[i]);
            else v0.push_back(a[i]);
        }

        v0 = self(self, v0);
        v1 = self(self, v1);
        vector<int> v;
        for (auto x : v0) v.push_back(x);
        for (auto x : v1) v.push_back(x);
        return v;
    };
    
    a = dfs(dfs, a);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (a[i] - 1) * n + a[j] << " ";
        }
        cout << "\n";
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    
}