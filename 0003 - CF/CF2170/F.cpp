#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    int q;
    cin >> q;
    vector<int> ans(q);
    vector<vector<tuple<int, int, int>>> qrys(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        qrys[r].emplace_back(i, l, x);
    }
    
    vector f(vector(13, vector(4096, -inf)));
    for (int i = 1; i <= n; i++) {
        auto nf = f;
        f[1][a[i]] = i;
        for (int j = 2; j <= 12; j++) {
            for (int k = 0; k < 4096; k++) {
                f[j][k] = max(f[j][k], nf[j - 1][k ^ a[i]]);
            }
        }
 
        for (auto [id, l, x] : qrys[i]) {
            for (int j = 1; j <= 12; j++) {
                if (f[j][x] >= l) {
                    ans[id] = j;
                    break;
                }
            }
        }
    }
 
    for (auto i : ans) cout << i << " ";
}
