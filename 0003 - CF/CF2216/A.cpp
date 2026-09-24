#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k + 1), b(n + 1);
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<vector<int>> cnt(k + 5);
    for (int i = 1; i <= n; i++) {
        cnt[b[i]].push_back(i);
    }
    vector<int> ans;
    for (int i = k; i >= 1; i--) {
        for (auto x : cnt[i]) {
            for (int t = 0; t < k + 1 - i; t++) {
                ans.push_back(x);
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) sol();
}
