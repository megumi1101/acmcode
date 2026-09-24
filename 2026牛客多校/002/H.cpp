#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

using ull = unsigned long long;
void sol() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> odd, even, vis(1 << n);
    vis[a] = 1, vis[b] = 1; 
    auto putans = [&] (auto &a, auto &b) -> void {
        vector<pair<int, int>> ans;
        for (int i = 0; i < a.size(); i++) {
            if (vis[a[i]]) continue;
            for (int j = i + 1; j < a.size(); j++) {
                if (vis[a[j]]) continue;
                if (popcount(ull(a[i] ^ a[j])) == 2) {
                    vis[a[i]] = 1;
                    vis[a[j]] = 1;
                    ans.push_back({a[i], a[j]});
                    break;
                }
            }
        }

        for (int i = 0; i < b.size(); i += 2) {
            ans.push_back({b[i], b[i + 1]});
        }

        if (ans.size() + 1 == (1 << (n - 1))) {
            cout << "Yes\n";
            for (auto [x, y] : ans) {
                cout << x << " " << y << "\n";
            }
        } else {
            cout << "No\n";
        }
    };


    if ((popcount((ull)a) & 1) != (popcount((ull)b) & 1)) {
        cout << "No\n";
    } else {
        for (int i = 0; i < (1 << n); i++) {
            if (popcount((ull)i) & 1) {
                odd.push_back(i);
            } else {
                even.push_back(i);
            }
        }

        if (popcount((ull)a) & 1) {
            putans(odd, even);
        } else {
            putans(even, odd);
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    
}