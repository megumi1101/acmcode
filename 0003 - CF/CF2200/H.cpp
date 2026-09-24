#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
 
int f (const vector<int>& a) {
    if (a.empty()) return 0;
    if (a.back() == 1) return 5;
    int n = a.size();
    int mod6 = a[0] % 6;
    vector<int> grps[7];
    for (int x : a) {
        if (x % 6 != mod6) return inf;
        grps[(x - mod6) / 6 % 7].push_back(x);
    }
    int ans = inf;
    for (int r = 0; r < 7; r++) {
        int k = (42 - 6 * r - mod6) % 42;
        vector<int> nex;
        for (int x : grps[r]) nex.push_back((x + k) / 42);
        int rec = f(nex);
        if (rec >= inf) continue;
        ans = min(ans, k + 42 * rec);
    }
    return ans;
}
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int res = f(a);
    if (res >= inf) cout << "-1\n";
    else cout << res << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
